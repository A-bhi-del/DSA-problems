# Write your MySQL query statement below
WITH rn AS
(
    SELECT requester_id AS id FROM RequestAccepted
    UNION ALL
    SELECT accepter_id AS id FROM RequestAccepted
),
CNT AS (
    SELECT id, COUNT(*) AS num FROM rn
    GROUP BY id
),
ranked AS (
    SELECT id, num, DENSE_RANK() OVER(
        ORDER BY num DESC
    ) AS `rank` FROM CNT
)

SELECT id, num FROM ranked
WHERE `rank` = 1
