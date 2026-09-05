# Write your MySQL query statement below
WITH COPY AS (
    SELECT E.employee_id, E.name, P.rating AS current_rating, 
    ROW_NUMBER() OVER(
        PARTITION BY E.employee_id
        ORDER BY P.review_date DESC
    ) AS rn, 
    LEAD(P.rating) OVER(
        PARTITION BY E.employee_id
        ORDER BY P.review_date DESC
    ) AS next,
    LAG(P.rating) OVER(
        PARTITION BY E.employee_id
        ORDER BY P.review_date DESC
    ) AS prev
    FROM employees E
    JOIN performance_reviews P
    ON E.employee_id = P.employee_id
    WHERE (
        SELECT COUNT(*) FROM performance_reviews PP
        WHERE P.employee_id = E.employee_id
    ) >= 3
)

SELECT employee_id, name, (prev - next) AS improvement_score FROM copy
WHERE rn = 2 AND current_rating < prev AND current_rating > next
ORDER BY improvement_score DESC, name