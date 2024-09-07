-- SELECT title: Velg kolonnen "title"
-- FROM movies: Fra tabellen "movies"
-- JOIN stars ON movies.id = stars.movie_id: Koble sammen tabellen "movies" med tabellen "stars" basert på "id" og "movie_id"
-- JOIN people ON stars.person_id = people.id: Koble sammen tabellen "stars" med tabellen "people" basert på "person_id" og "id"
-- JOIN ratings ON movies.id = ratings.movie_id: Koble sammen tabellen "movies" med tabellen "ratings" basert på "id" og "movie_id"
-- WHERE people.name = 'Chadwick Boseman': Hvor navnet i tabellen "people" er 'Chadwick Boseman'
-- ORDER BY ratings.rating DESC: Sorter resultatene synkende etter vurdering
-- LIMIT 5: Begrens resultatene til de 5 beste
-- Denne spørringen henter titlene på de 5 filmene med høyest vurdering som Chadwick Boseman har vært med i
SELECT title
FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
JOIN ratings ON movies.id = ratings.movie_id
WHERE people.name = 'Chadwick Boseman'
ORDER BY ratings.rating DESC
LIMIT 5;
