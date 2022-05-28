# Write your MySQL query statement below

# calculate the rank
SELECT
        score,
        # cast rank as integer
        (
            SELECT CAST(
                (
                    CASE
                        # if same score, reuse the rank
                        WHEN (score = score_lag) THEN @i_rank
                        # otherwise if new score,
                        ELSE
                            # increment the rank
                            (@i_rank := @i_rank + 1)
                    END
                )
            AS unsigned)
        ) AS 'rank'
    FROM
        (
            # add the previous score (or lag) to each score
            SELECT
                    score,
                    lag(score, 1, null) OVER () AS score_lag
                FROM
                    (
                        # sort the scores
                        SELECT score
                            FROM
                                Scores
                            # in order of score descending
                            ORDER BY -score
                    ) AS SortedScores
        ) AS ScoresWithLag

        # initialize the ranks
        # and cross multiply onto each row
        CROSS JOIN (
            SELECT @i_rank := 0 as INIT_RANK
        ) As InitRank
;