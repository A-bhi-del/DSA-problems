# Write your MySQL query statement below
WITH COPY AS (
    SELECT a.user_id, a.action, COUNT(*) AS streak_length, MIN(a.action_date) AS start_date, MAX(a.action_date) AS end_date
    FROM activity a
    GROUP BY a.user_id, a.action
    HAVING COUNT(*) >= 5 AND a.user_id NOT IN (
        SELECT aa.user_id
        FROM activity aa
        GROUP BY aa.user_id, aa.action_date
        HAVING COUNT(*) >= 2
    )
), COPY2 AS(
    SELECT *, ROW_NUMBER() OVER(
        PARTITION BY user_id
        ORDER BY streak_length
    ) AS rn
    FROM COPY
)

SELECT user_id, action, streak_length, start_date, end_date
FROM COPY2
WHERE rn = 1
ORDER BY streak_length DESC, user_id