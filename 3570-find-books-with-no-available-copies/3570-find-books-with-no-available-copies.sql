# Write your MySQL query statement below
SELECT B.book_id, L.title, L.author, L.genre, L.publication_year, COUNT(B.book_id) AS current_borrowers
FROM library_books L
LEFT JOIN borrowing_records B
ON L.book_id = B.book_id
WHERE B.return_date IS NULL
GROUP BY B.book_id, L.title, L.author, L.genre, L.publication_year, L.total_copies
HAVING current_borrowers = L.total_copies
ORDER BY current_borrowers DESC, title ASC