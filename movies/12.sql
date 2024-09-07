-- SELECT title: Velg kolonnen "title"
-- FROM movies: Fra tabellen "movies"
-- JOIN stars sc1 ON movies.id = sc1.movie_id: Koble sammen tabellen "movies" med tabellen "stars" (aliased som sc1) basert på "id" og "movie_id"
-- JOIN people p1 ON sc1.person_id = p1.id: Koble sammen tabellen "stars" (aliased som sc1) med tabellen "people" (aliased som p1) basert på "person_id" og "id"
-- JOIN stars sc2 ON movies.id = sc2.movie_id: Koble sammen tabellen "movies" med tabellen "stars" (aliased som sc2) basert på "id" og "movie_id"
-- JOIN people p2 ON sc2.person_id = p2.id: Koble sammen tabellen "stars" (aliased som sc2) med tabellen "people" (aliased som p2) basert på "person_id" og "id"
-- WHERE p1.name = 'Bradley Cooper' AND p2.name = 'Jennifer Lawrence': Hvor navnet i tabellen "people" (aliased som p1) er 'Bradley Cooper' og navnet i tabellen "people" (aliased som p2) er 'Jennifer Lawrence'
-- Denne spørringen henter titlene på filmer der både Bradley Cooper og Jennifer Lawrence har vært med
SELECT title
FROM movies
JOIN stars sc1 ON movies.id = sc1.movie_id
JOIN people p1 ON sc1.person_id = p1.id
JOIN stars sc2 ON movies.id = sc2.movie_id
JOIN people p2 ON sc2.person_id = p2.id
WHERE p1.name = 'Bradley Cooper' AND p2.name = 'Jennifer Lawrence';
