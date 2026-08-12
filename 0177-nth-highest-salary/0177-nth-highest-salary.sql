CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      WITH rn AS (
        SELECT *, DENSE_RANK() OVER(
            ORDER BY salary DESC
        ) AS `rank` FROM Employee
      )

      SELECT MAX(
        CASE WHEN `rank` = N THEN salary ELSE null END
      ) FROM rn
  );
END