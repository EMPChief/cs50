-- SELECT DISTINCT name: Velg unike navn
-- FROM people: Fra tabellen "people"
-- JOIN directors ON people.id = directors.person_id: Koble sammen tabellen "people" med tabellen "directors" basert på "id" og "person_id"
-- JOIN movies ON directors.movie_id = movies.id: Koble sammen tabellen "directors" med tabellen "movies" basert på "movie_id" og "id"
-- JOIN ratings ON movies.id = ratings.movie_id: Koble sammen tabellen "movies" med tabellen "ratings" basert på "id" og "movie_id"
-- WHERE ratings.rating >= 9.0: Hvor vurderingen er større enn eller lik 9.0
-- Denne spørringen henter unike navn på personer som har regissert filmer med en vurdering på 9.0 eller høyere
SELECT DISTINCT name
FROM people
JOIN directors ON people.id = directors.person_id
JOIN movies ON directors.movie_id = movies.id
JOIN ratings ON movies.id = ratings.movie_id
WHERE ratings.rating >= 9.0;
