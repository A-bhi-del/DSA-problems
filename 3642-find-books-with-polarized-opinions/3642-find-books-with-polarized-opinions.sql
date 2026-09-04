# Write your MySQL query statement below
SELECT B.book_id, B.title, B.author, B.genre, B.pages,
(MAX(RS.session_rating) - MIN(RS.session_rating)) AS rating_spread,
ROUND(SUM(
    CASE WHEN RS.session_rating <= 2 OR RS.session_rating >= 4
    THEN 1
    END
) / COUNT(*), 2) AS polarization_score
FROM books B
JOIN reading_sessions RS
ON B.book_id = RS.book_id
GROUP BY B.book_id
HAVING MIN(RS.session_rating) <= 2 AND MAX(RS.session_rating) >= 4 AND COUNT(*) >= 5 AND polarization_score >= 0.6
ORDER BY polarization_score DESC, B.title DESC


