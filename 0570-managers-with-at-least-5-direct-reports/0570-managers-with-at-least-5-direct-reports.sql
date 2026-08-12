# Write your MySQL query statement below
SELECT E.name FROM Employee E LEFT JOIN Employee E2 ON E.id = E2.managerId
GROUP BY E.id
HAVING COUNT(E.id) >= 5