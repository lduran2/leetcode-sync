# Write your MySQL query statement below

# Table: ActorDirector

# Report that provides the pairs (actor_id, director_id) where the
# actor has cooperated with the director at least three times.

# find all (actor, director) pairs with >= 3 cooperations
SELECT
        actor_id,
        director_id
    FROM
        (
            # count the cooperations between each actor and director
            SELECT
                    actor_id,
                    director_id,
                    count(timestamp) AS N_COOPERATIONS
                FROM
                    ActorDirector
                GROUP BY
                    actor_id,
                    director_id
        ) AS ActorDirectorCooperations
    WHERE
        (N_COOPERATIONS >= 3)
;