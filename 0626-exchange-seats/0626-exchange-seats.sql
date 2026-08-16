# Write your MySQL query statement below
WITH rn AS (
    SELECT *, LAG(student) OVER() AS bef, 
    LEAD(student) OVER() AS aft
    FROM Seat
)

SELECT id, (
    CASE WHEN id % 2 = 1 AND aft IS NOT null THEN aft
    WHEN id % 2 = 0 AND bef IS NOT null THEN bef
    ELSE student END
) AS student FROM rn
ORDER BY id