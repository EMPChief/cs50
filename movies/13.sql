-- SELECT DISTINCT name: Velg unike navn
-- FROM people: Fra tabellen "people"
-- JOIN stars s1 ON people.id = s1.person_id: Koble sammen tabellen "people" med tabellen "stars" (aliased som s1) basert på "id" og "person_id"
-- JOIN movies m ON s1.movie_id = m.id: Koble sammen tabellen "stars" (aliased som s1) med tabellen "movies" basert på "movie_id" og "id"
-- JOIN stars s2 ON m.id = s2.movie_id: Koble sammen tabellen "movies" med tabellen "stars" (aliased som s2) basert på "id" og "movie_id"
-- JOIN people kb ON s2.person_id = kb.id: Koble sammen tabellen "stars" (aliased som s2) med tabellen "people" (aliased som kb) basert på "person_id" og "id"
-- WHERE kb.name = 'Kevin Bacon' AND kb.birth = 1958: Hvor navnet i tabellen "people" (aliased som kb) er 'Kevin Bacon' og fødselsåret er 1958
-- AND people.name != 'Kevin Bacon': Og navnet i tabellen "people" er ikke 'Kevin Bacon'
-- Denne spørringen henter unike navn på personer som har spilt i filmer med Kevin Bacon (som ble født i 1958), ekskludert Kevin Bacon selv
SELECT DISTINCT name
FROM people
JOIN stars s1 ON people.id = s1.person_id
JOIN movies m ON s1.movie_id = m.id
JOIN stars s2 ON m.id = s2.movie_id
JOIN people kb ON s2.person_id = kb.id
WHERE kb.name = 'Kevin Bacon' AND kb.birth = 1958 AND people.name != 'Kevin Bacon';
