# Write your MySQL query statement below
(
    SELECT 
        "Fall" AS season,
        p.category,
        SUM(quantity) AS total_quantity,
        SUM(quantity * price) AS total_revenue
    FROM sales s
    JOIN products p
        ON s.product_id = p.product_id
    WHERE MONTH(sale_date) IN (9, 10, 11)
    GROUP BY p.category
    HAVING 
        SUM(quantity) = (
            SELECT MAX(total_quantity)
            FROM (
                SELECT SUM(quantity) AS total_quantity
                FROM sales s2
                JOIN products p2
                    ON s2.product_id = p2.product_id
                WHERE MONTH(s2.sale_date) IN (9, 10, 11)
                GROUP BY p2.category
            ) x
        )
    ORDER BY total_quantity DESC, total_revenue DESC, p.category
    LIMIT 1
)
UNION
(
    SELECT 
        "Spring" AS season,
        p.category,
        SUM(quantity) AS total_quantity,
        SUM(quantity * price) AS total_revenue
    FROM sales s
    JOIN products p
        ON s.product_id = p.product_id
    WHERE MONTH(sale_date) IN (3, 4, 5)
    GROUP BY p.category
    HAVING 
        SUM(quantity) = (
            SELECT MAX(total_quantity)
            FROM (
                SELECT SUM(quantity) AS total_quantity
                FROM sales s2
                JOIN products p2
                    ON s2.product_id = p2.product_id
                WHERE MONTH(s2.sale_date) IN (3, 4, 5)
                GROUP BY p2.category
            ) x
        )
    ORDER BY total_quantity DESC, total_revenue DESC, p.category
    LIMIT 1
)
UNION
(
    SELECT 
        "Summer" AS season,
        p.category,
        SUM(quantity) AS total_quantity,
        SUM(quantity * price) AS total_revenue
    FROM sales s
    JOIN products p
        ON s.product_id = p.product_id
    WHERE MONTH(sale_date) IN (6, 7, 8)
    GROUP BY p.category
    HAVING 
        SUM(quantity) = (
            SELECT MAX(total_quantity)
            FROM (
                SELECT SUM(quantity) AS total_quantity
                FROM sales s2
                JOIN products p2
                    ON s2.product_id = p2.product_id
                WHERE MONTH(s2.sale_date) IN (6, 7, 8)
                GROUP BY p2.category
            ) x
        )
    ORDER BY total_quantity DESC, total_revenue DESC, p.category
    LIMIT 1
)
UNION
(
    SELECT 
        "Winter" AS season,
        p.category,
        SUM(quantity) AS total_quantity,
        SUM(quantity * price) AS total_revenue
    FROM sales s
    JOIN products p
        ON s.product_id = p.product_id
    WHERE MONTH(sale_date) IN (12, 1, 2)
    GROUP BY p.category
    HAVING 
        SUM(quantity) = (
            SELECT MAX(total_quantity)
            FROM (
                SELECT SUM(quantity) AS total_quantity
                FROM sales s2
                JOIN products p2
                    ON s2.product_id = p2.product_id
                WHERE MONTH(s2.sale_date) IN (12, 1, 2)
                GROUP BY p2.category
            ) x
        )
    ORDER BY total_quantity DESC, total_revenue DESC, p.category
    LIMIT 1
)