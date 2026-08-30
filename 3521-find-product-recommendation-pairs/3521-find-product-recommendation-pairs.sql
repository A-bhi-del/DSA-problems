# Write your MySQL query statement below
WITH COMBI AS (
    SELECT user_id, PP.product_id, category
    FROM ProductPurchases PP
    JOIN ProductInfo PIn
    ON PP.product_id = PIn.product_id
)

SELECT c1.product_id AS product1_id, c2.product_id AS product2_id,
c1.category AS product1_category, c2.category AS product2_category, COUNT(DISTINCT c1.user_id) AS customer_count
FROM COMBI c1
JOIN COMBI c2
ON c1.user_id = c2.user_id
WHERE c1.product_id < c2.product_id
GROUP BY c1.product_id, c2.product_id
HAVING COUNT(DISTINCT c1.user_id) >= 3
ORDER BY customer_count DESC, product1_id, product2_id