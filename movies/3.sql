-- SELECT title: Velg kolonnen "title"
-- FROM movies: Fra tabellen "movies"
-- WHERE year >= 2018: Hvor året er større enn eller lik 2018
-- ORDER BY title ASC: Sorter resultatene alfabetisk stigende etter "title"
-- Denne spørringen henter titlene på filmene fra tabellen "movies" som er fra 2018 eller senere, sortert alfabetisk
SELECT title
FROM movies
WHERE year >= 2018
ORDER BY title ASC;
