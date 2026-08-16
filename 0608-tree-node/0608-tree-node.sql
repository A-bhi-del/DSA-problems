# Write your MySQL query statement below
SELECT id, "Root" AS type FROM Tree
WHERE p_id IS null
UNION
SELECT id, "Inner" AS type FROM Tree
WHERE p_id IS NOT null AND id IN (
    SELECT p_id FROM Tree
)
UNION
SELECT id, "Leaf" AS type FROM Tree
WHERE p_id IS NOT null AND id NOT IN(
    SELECT p_id FROM Tree
    WHERE p_id IS NOT null
)