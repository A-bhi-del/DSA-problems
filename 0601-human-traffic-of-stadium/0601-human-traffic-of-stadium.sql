# Write your MySQL query statement below
WITH rn AS (
    SELECT *, ROW_NUMBER() OVER(
        ORDER BY visit_date
    ) AS `rank`
    FROM Stadium
    WHERE people >= 100
),
rn2 AS (
    SELECT *, COUNT(*) OVER(
        PARTITION BY (id - `rank`)
    ) AS same FROM rn
)

SELECT id, visit_date, people FROM rn2
WHERE same >= 3
ORDER BY visit_date