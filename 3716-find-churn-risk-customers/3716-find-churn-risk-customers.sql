# Write your MySQL query statement below
WITH copy AS (
    SELECT S.user_id, S.event_date, S.event_type, S.plan_name, S.monthly_amount, ROW_NUMBER() OVER(
        PARTITION BY S.user_id
        ORDER BY S.event_date DESC
    ) AS rn,
    MIN(S.event_date) OVER(
        PARTITION BY S.user_id
    ) AS start_date,
    MAX(S.monthly_amount) OVER(
        PARTITION BY S.user_id
    ) AS max_amount
    FROM subscription_events S
    WHERE S.user_id NOT IN (
        SELECT SS.user_id FROM 
        subscription_events SS
        WHERE SS.event_type = "cancel"
    ) AND S.user_id IN (
        SELECT SS.user_id FROM
        subscription_events SS
        WHERE SS.event_type = "downgrade"
    )
)

SELECT user_id, plan_name AS current_plan, monthly_amount AS current_monthly_amount, max_amount AS max_historical_amount, DATEDIFF(event_date , start_date) AS days_as_subscriber 
FROM copy
WHERE rn = 1
HAVING ROUND((current_monthly_amount/max_historical_amount) * 100, 2) <= 50 AND days_as_subscriber >= 60
ORDER BY days_as_subscriber DESC, user_id
