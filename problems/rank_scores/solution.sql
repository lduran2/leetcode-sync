# Write your MySQL query statement below

# sort the scores
SELECT
        Scores.score AS score,
        ScoreRankings.rank
    FROM
        Scores
        LEFT JOIN
        (
            SELECT
                    score,
                    # cast rank as integer
                    (
                        SELECT CAST(
                            (@i_rank := @i_rank + 1)
                        AS unsigned)
                    ) AS 'rank'
                FROM
                    (
                        # sort the scores
                        SELECT score
                            FROM
                                Scores
                            # combine equal scores
                            GROUP BY score
                            # in order of score descending
                            ORDER BY -score
                    ) AS UniqueScores

                    # initialize the ranks
                    # and cross multiply onto each row
                    CROSS JOIN (
                        SELECT @i_rank := 0 AS INIT_RANK
                    ) AS InitRank
        ) AS ScoreRankings
        ON Scores.score = ScoreRankings.score
    # in order of score descending
    ORDER BY -Scores.score
;