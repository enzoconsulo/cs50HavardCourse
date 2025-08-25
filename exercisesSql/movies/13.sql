SELECT DISTINCT name FROM people
JOIN stars ON people.id = stars.person_id
WHERE stars.movie_id IN (                      -- searchs into a sublist with all ids with movies that have kevin bacon on
    SELECT movie_id FROM stars
    JOIN people ON stars.person_id = people.id -- creates a sublist with all movies id's where have "kevin bacon"
    WHERE people.name = "Kevin Bacon"          --  with birth at 1958 staring in.
    AND people.birth = 1958
)
AND people.name != "Kevin Bacon";
