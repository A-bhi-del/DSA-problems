# Write your MySQL query statement below
SELECT 
    user_id,
    ROUND(AVG(
        CASE 
            WHEN activity_type = 'free_trial' 
            THEN activity_duration 
        END
    ), 2) AS trial_avg_duration,
    
    ROUND(AVG(
        CASE 
            WHEN activity_type = 'paid' 
            THEN activity_duration 
        END
    ), 2) AS paid_avg_duration

FROM UserActivity
GROUP BY user_id
HAVING (MIN(CASE WHEN activity_type = "paid" THEN activity_date END) < MIN(CASE WHEN activity_type = "cancelled" THEN activity_date END) OR (MIN(CASE WHEN activity_type = "cancelled" THEN activity_date END) IS NULL AND MIN(CASE WHEN activity_type = "paid" THEN activity_date END) IS NOT NULL) AND trial_avg_duration IS NOT NULL)
ORDER BY user_id;
