# Write your MySQL query statement below
SELECT ct.customer_id 
FROM customer_transactions ct
GROUP BY ct.customer_id
HAVING DATEDIFF(MAX(ct.transaction_date), MIN(ct.transaction_date)) >= 30 AND (
    SELECT ROUND(COUNT(
        CASE WHEN ctt.transaction_type = 'refund'
        THEN 1
        END
    ) / COUNT(*), 2) * 100
    FROM customer_transactions ctt
    WHERE ctt.customer_id = ct.customer_id
) < 20 AND (
    SELECT COUNT(
        CASE WHEN ctt.transaction_type = 'purchase'
        THEN 1
        END
    )
    FROM customer_transactions ctt
    WHERE ctt.customer_id = ct.customer_id
) >= 3
ORDER BY ct.customer_id