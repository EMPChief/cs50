-- SELECT title, rating: Velg kolonnene "title" og "rating"
-- FROM movies: Fra tabellen "movies"
-- JOIN ratings ON movies.id = ratings.movie_id: Koble sammen tabellen "movies" med tabellen "ratings" basert på "id" og "movie_id"
-- WHERE movies.year = 2010: Hvor året i tabellen "movies" er 2010
-- ORDER BY rating DESC, title ASC: Sorter resultatene synkende etter "rating" og deretter stigende etter "title"
-- Denne spørringen henter titler og vurderinger på filmer fra 2010, sortert etter vurdering i synkende rekkefølge og deretter etter tittel i stigende rekkefølge
SELECT title, rating
FROM movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE movies.year = 2010
ORDER BY rating DESC, title ASC;
