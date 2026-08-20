# Write your MySQL query statement below
WITH rn AS (
    SELECT *, (
        CASE WHEN income < 20000 
        THEN "Low Salary"
        WHEN income >= 20000 AND income <= 50000
        THEN "Average Salary"
        ELSE "High Salary"
        END
    ) AS category
    FROM Accounts
),
catogories AS (
    SELECT "Low Salary" AS category
    UNION ALL
    SELECT "Average Salary" AS category
    UNION ALL 
    SELECT "High Salary" AS category
)

SELECT C.category, COUNT(rn.account_id) AS accounts_count
FROM catogories C
LEFT JOIN rn
ON C.category = rn.category
GROUP BY C.category