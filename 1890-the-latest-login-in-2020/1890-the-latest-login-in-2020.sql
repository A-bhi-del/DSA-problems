# Write your MySQL query statement below
WITH rn AS (
    SELECT *, ROW_NUMBER() OVER(
        PARTITION BY user_id
        ORDER BY time_stamp DESC
    ) AS `rank` 
    FROM Logins
    WHERE time_stamp >= "2020-01-01 00:00:00" AND time_stamp <= "2020-12-31 23:59:59"
)

SELECT user_id, time_stamp AS last_stamp
FROM rn
WHERE `rank` = 1