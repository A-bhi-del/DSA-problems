# Write your MySQL query statement below
WITH daily AS (
    SELECT visited_on, SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
),
rn AS (
    SELECT *, SUM(amount) OVER(
        ORDER BY visited_on
        ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
    ) AS amt,
    AVG(amount) OVER(
        ORDER BY visited_on
        ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
    ) AS average_amount,
    ROW_NUMBER() OVER(
        ORDER BY visited_on
    ) AS `rank` FROM daily
)

SELECT visited_on, amt AS amount, ROUND(average_amount,2) AS average_amount
FROM rn
WHERE `rank` >= 7
ORDER BY visited_on

