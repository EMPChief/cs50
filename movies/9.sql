-- SELECT name: Velg kolonnen "name"
-- FROM people: Fra tabellen "people"
-- JOIN stars ON stars.person_id = people.id: Koble sammen tabellen "people" med tabellen "stars" basert på "id" og "person_id"
-- JOIN movies ON stars.movie_id = movies.id: Koble sammen tabellen "stars" med tabellen "movies" basert på "movie_id" og "id"
-- WHERE movies.year = 2004: Hvor året i tabellen "movies" er 2004
-- ORDER BY people.birth: Sorter resultatene etter fødselsdatoen i tabellen "people"
-- Denne spørringen henter navnene på personer som har spilt i filmer fra 2004, sortert etter deres fødselsdato
SELECT name
FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movies.id
WHERE movies.year = 2004
ORDER BY people.birth;
