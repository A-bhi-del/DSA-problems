# Write your MySQL query statement below
WITH rn AS (
    SELECT customer_id, COUNT(DISTINCT product_key) AS total_pro FROM Customer
    GROUP BY customer_id
)

SELECT customer_id FROM rn
WHERE total_pro = (
    SELECT COUNT(*) FROM Product
)