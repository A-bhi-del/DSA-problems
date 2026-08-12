# Write your MySQL query statement below
WITH rn AS (
    SELECT *, DENSE_RANK() OVER(
        ORDER BY salary DESC
    ) AS `rank` FROM Employee
)

SELECT MAX(
    CASE WHEN `rank` = 2 THEN salary ELSE null END
) AS SecondHighestSalary FROM rn
