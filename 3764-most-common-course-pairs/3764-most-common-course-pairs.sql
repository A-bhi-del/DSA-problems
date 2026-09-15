# Write your MySQL query statement below
WITH COPY AS (
    SELECT C.user_id, C.course_id, C.course_name, C.course_rating, C.completion_date
    FROM course_completions C
    WHERE C.user_id IN (
        SELECT CC.user_id
        FROM course_completions CC
        GROUP BY CC.user_id
        HAVING AVG(CC.course_rating) >= 4 AND COUNT(*) >= 5
    )
), COPY2 AS(
    SELECT user_id, course_id, course_rating,
    LAG(course_name) OVER(
        PARTITION BY user_id
        ORDER BY completion_date
    ) AS bef, course_name
    FROM COPY
)

SELECT bef AS first_course, course_name AS second_course, COUNT(*) AS transition_count
FROM COPY2
WHERE bef IS NOT NULL
GROUP BY course_id, bef, course_name
ORDER BY transition_count DESC, first_course, second_course

-- SELECT * FROM COPY

