# Write your MySQL query statement below
WITH copy1 AS (
    SELECT S.store_id , S.store_name, S.location, I.product_name, I.quantity, DENSE_RANK() OVER(
        PARTITION BY S.store_id
        ORDER BY I.price
    ) AS aft_r
    FROM stores S
    JOIN inventory I
    ON S.store_id = I.store_id
    WHERE S.store_id IN (
        SELECT II.store_id FROM inventory II
        GROUP BY II.store_id
        HAVING COUNT(*) >= 3
    )
), copy2 AS (
    SELECT S.store_id, S.store_name, S.location, I.product_name, I.quantity, DENSE_RANK() OVER(
        PARTITION BY S.store_id
        ORDER BY I.price DESC
    ) AS bef_r
    FROM stores S
    JOIN inventory I
    ON S.store_id = I.store_id
    WHERE S.store_id IN (
        SELECT II.store_id FROM inventory II
        GROUP BY II.store_id
        HAVING COUNT(*) >= 3
    )
)

SELECT C1.store_id, C1.store_name, C1.location, C2.product_name AS most_exp_product, C1.product_name AS cheapest_product, ROUND(C1.quantity/C2.quantity, 2) AS imbalance_ratio
FROM copy1 C1
JOIN copy2 C2
ON C1.store_id = C2.store_id
WHERE aft_r = 1 AND bef_r = 1 AND C1.quantity > C2.quantity
-- GROUP BY C1.store_id
ORDER BY imbalance_ratio DESC


-- SELECT store_id, store_name, location, most_exp_product, cheapest_product, imbalance_ratio 
-- FROM copy3
-- GROUP BY store_id