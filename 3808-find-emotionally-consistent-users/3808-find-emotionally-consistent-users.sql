# Write your MySQL query statement below
WITH copy AS (
    SELECT R1.user_id, R1.reaction, COUNT(*) AS reaction_count
    FROM reactions R1
    WHERE R1.user_id IN (
        SELECT R2.user_id 
        FROM reactions R2
        GROUP BY R2.user_id
        HAVING COUNT(*) >= 5 
    )
    GROUP BY user_id, reaction
), copy2 AS(
    SELECT user_id, reaction, reaction_count, ROW_NUMBER() OVER(
        PARTITION BY user_id
        ORDER BY reaction_count DESC
    ) AS rn,
    SUM(reaction_count) OVER(
        PARTITION BY user_id
    ) AS total_reaction
    FROM copy
)


SELECT c1.user_id, c1.reaction AS dominant_reaction, ROUND(c1.reaction_count / total_reaction, 2) AS reaction_ratio
FROM copy2 c1
WHERE c1.rn = 1 
AND c1.user_id IN (
    SELECT c2.user_id
    FROM copy c2
    GROUP BY c2.user_id
    HAVING ROUND(MAX(c2.reaction_count) / SUM(c2.reaction_count), 2) >= 0.6
)
GROUP BY c1.user_id
ORDER BY reaction_ratio DESC, c1.user_id
