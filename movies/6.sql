-- SELECT AVG(rating): Beregn gjennomsnittlig vurdering
-- FROM ratings: Fra tabellen "ratings"
-- JOIN movies ON ratings.movie_id = movies.id: Koble sammen tabellen "ratings" med tabellen "movies" basert på "movie_id" og "id"
-- WHERE movies.year = 2012: Hvor året i tabellen "movies" er 2012
-- Denne spørringen beregner gjennomsnittlig vurdering for filmer fra 2012
SELECT AVG(rating)
FROM ratings
JOIN movies ON ratings.movie_id = movies.id
WHERE movies.year = 2012;
