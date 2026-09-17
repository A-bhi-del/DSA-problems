# Write your MySQL query statement below
SELECT a.session_id, a.user_id, TIMESTAMPDIFF(MINUTE, MIN(a.event_timestamp), MAX(a.event_timestamp)) AS session_duration_minutes, SUM(
    CASE WHEN a.event_type = "scroll"
    THEN 1
    END
) AS scroll_count
FROM app_events a
GROUP BY a.session_id, a.user_id
HAVING session_duration_minutes > 30 AND scroll_count >= 5 AND (
    SELECT ROUND(COUNT(
        CASE WHEN aa.event_type = "click"
        THEN 1
        END
    )/COUNT(
        CASE WHEN aa.event_type = "scroll"
        THEN 1
        END
    ), 2)
    FROM app_events aa
    WHERE aa.session_id = a.session_id AND aa.user_id = a.user_id
) < 0.20 AND a.session_id NOT IN (
    SELECT aa.session_id
    FROM app_events aa
    WHERE aa.event_type = "purchase"
)
ORDER BY scroll_count DESC, a.session_id