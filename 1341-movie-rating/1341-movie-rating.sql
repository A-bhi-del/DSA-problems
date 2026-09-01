# Write your MySQL query statement below
WITH copy AS (
    (SELECT U.name AS username, COUNT(DISTINCT MR.movie_id) AS freq
    FROM MovieRating MR
    JOIN Users U
    ON MR.user_id = U.user_id
    GROUP BY MR.user_id
    ORDER BY freq DESC, U.name 
    LIMIT 1)

    UNION 

    (SELECT M.title, AVG(MR.rating) AS rate
    FROM MovieRating MR
    JOIN Movies M
    ON MR.movie_id = M.movie_id
    WHERE DATE_FORMAT(MR.created_at, '%Y-%m') = "2020-02"
    GROUP BY MR.movie_id
    ORDER BY rate DESC, M.title
    LIMIT 1)
)

SELECT username AS results FROM copy

-- SELECT M.title, AVG(MR.rating) AS rate
--     FROM MovieRating MR
--     JOIN Movies M
--     ON MR.movie_id = M.movie_id
--     WHERE DATE_FORMAT(MR.created_at, '%Y-%m') = "2020-02"
--     GROUP BY MR.movie_id
--     ORDER BY rate DESC, M.title
--     LIMIT 1