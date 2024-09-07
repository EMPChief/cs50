-- SELECT title, year: Velg kolonnene "title" og "year"
-- FROM movies: Fra tabellen "movies"
-- WHERE title LIKE 'Harry Potter%': Hvor tittelen begynner med 'Harry Potter'
-- ORDER BY year ASC: Sorter resultatene stigende etter "year"
-- Denne spørringen henter tittelen og året på filmene fra tabellen "movies" hvor tittelen begynner med 'Harry Potter', sortert etter året
SELECT title, year
FROM movies
WHERE title LIKE 'Harry Potter%'
ORDER BY year ASC;
