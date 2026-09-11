# Write your MySQL query statement below
SELECT sc.student_id, sc.subject, MAX(
    CASE WHEN exam_date = (
        SELECT MIN(S.exam_date)
        FROM Scores S
        WHERE S.student_id = sc.student_id AND S.subject = sc.subject
    )
    THEN sc.score
    END
) AS first_score, MAX(
    CASE WHEN exam_date = (
        SELECT MAX(S.exam_date) 
        FROM Scores S
        WHERE S.student_id = sc.student_id AND S.subject = sc.subject
    )
    THEN sc.score
    END
) AS latest_score
FROM Scores sc
GROUP BY sc.student_id, sc.subject
HAVING first_score < latest_score
ORDER BY sc.student_id, sc.subject