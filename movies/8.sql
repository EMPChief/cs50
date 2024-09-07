-- SELECT name: Velg kolonnen "name"
-- FROM people: Fra tabellen "people"
-- JOIN stars ON people.id = stars.person_id: Koble sammen tabellen "people" med tabellen "stars" basert på "id" og "person_id"
-- JOIN movies ON stars.movie_id = movies.id: Koble sammen tabellen "stars" med tabellen "movies" basert på "movie_id" og "id"
-- WHERE movies.title = 'Toy Story': Hvor tittelen i tabellen "movies" er 'Toy Story'
-- Denne spørringen henter navnene på personer som har spilt i filmen med tittelen 'Toy Story'
SELECT name
FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE movies.title = 'Toy Story';
