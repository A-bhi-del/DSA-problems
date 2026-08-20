# Write your MySQL query statement below
SELECT S.user_id, ROUND(
    COUNT(
        CASE WHEN action = "confirmed" THEN 1 END
    )/COUNT(S.user_id), 2
) AS confirmation_rate
FROM Signups S
LEFT JOIN Confirmations C
ON S.user_id = C.user_id
GROUP BY S.user_id