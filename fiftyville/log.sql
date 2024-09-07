-- Keep a log of any SQL queries you execute as you solve the mystery.

Here’s a revised version of the comments in Norwegian, with a different style:

sql

-- Dokumenter alle SQL-spørringer du kjører mens du etterforsker saken.

-- Undersøk detaljer om kriminaliteten som fant sted på angitt sted og tidspunkt.
SELECT description
  FROM crime_scene_reports
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND street = 'Humphrey Street';

-- To hendelser skjedde den dagen; den ene var tyveri og den andre var forsøpling.

-- Vitnene kan være involvert. Hent navnene på vitnene fra interviews-tabellen og se gjennom intervjuene deres.
SELECT name, transcript
  FROM interviews
 WHERE year = 2021
   AND month = 7
   AND day = 28;

-- To transkripter nevner navnet Eugene. Sjekk hvor mange personer med navnet Eugene som er registrert i 'people'-tabellen.
SELECT name
  FROM people
 WHERE name = 'Eugene';
-- Bekreftet at det bare er én Eugene. Gå videre med dette.

-- Finn navnene på de tre vitnene fra listen over personer som ble intervjuet 28. juli 2021. Kriminalrapporten sier at vitnene nevnte "bakeri" i transkriptene sine. Sorter resultatene alfabetisk etter vitnenes navn.
SELECT name, transcript
  FROM interviews
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND transcript LIKE '%bakery%'
 ORDER BY name;
-- Vitnene er Eugene, Raymond og Ruth.

-- Eugene ga en ledetråd: Tyven tok ut penger fra en minibank på Leggett Street. Sjekk kontonummeret som ble brukt i den transaksjonen.
SELECT account_number, amount
  FROM atm_transactions
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND atm_location = 'Leggett Street'
   AND transaction_type = 'withdraw';
-- Finn navnene knyttet til de aktuelle kontonumrene. Legg disse navnene til på 'Mistenkte Liste'.
SELECT name, atm_transactions.amount
  FROM people
  JOIN bank_accounts
    ON people.id = bank_accounts.person_id
  JOIN atm_transactions
    ON bank_accounts.account_number = atm_transactions.account_number
 WHERE atm_transactions.year = 2021
   AND atm_transactions.month = 7
   AND atm_transactions.day = 28
   AND atm_transactions.atm_location = 'Leggett Street'
   AND atm_transactions.transaction_type = 'withdraw';

-- Raymond ga en ledetråd: Etter å ha forlatt bakeriet, ringte de en person og snakket i mindre enn ett minutt. De ba personen på den andre enden av samtalen om å kjøpe en flybillett til den tidligste flyvningen 29. juli 2021.
-- Finn informasjon om flyplassen i Fiftyville, som ville være avreiseflyplassen for tyven.
SELECT abbreviation, full_name, city
  FROM airports
 WHERE city = 'Fiftyville';
-- Søk etter flyvninger den 29. juli fra Fiftyville flyplass, og sorter dem etter tid.
SELECT flights.id, full_name, city, flights.hour, flights.minute
  FROM airports
  JOIN flights
    ON airports.id = flights.destination_airport_id
 WHERE flights.origin_airport_id =
       (SELECT id
          FROM airports
         WHERE city = 'Fiftyville')
   AND flights.year = 2021
   AND flights.month = 7
   AND flights.day = 29
 ORDER BY flights.hour, flights.minute;
-- Den første flyvningen går kl. 08:20 til LaGuardia Airport i New York City (Flight id- 36). Dette kan være stedet tyven dro til.
-- Sjekk listen over passasjerer på denne flyvningen. Legg dem alle til på 'Mistenkte Liste'. Sorter navnene etter passnummer.
SELECT passengers.flight_id, name, passengers.passport_number, passengers.seat
  FROM people
  JOIN passengers
    ON people.passport_number = passengers.passport_number
  JOIN flights
    ON passengers.flight_id = flights.id
 WHERE flights.year = 2021
   AND flights.month = 7
   AND flights.day = 29
   AND flights.hour = 8
   AND flights.minute = 20
 ORDER BY passengers.passport_number;
-- Sjekk telefonoppringningsdataene for å finne personen som kjøpte billettene.
-- Først, sjekk mulige navn på oppringeren, og legg disse navnene til på 'Mistenkte Liste'. Sorter dem etter samtalens varighet.
SELECT name, phone_calls.duration
  FROM people
  JOIN phone_calls
    ON people.phone_number = phone_calls.caller
 WHERE phone_calls.year = 2021
   AND phone_calls.month = 7
   AND phone_calls.day = 28
   AND phone_calls.duration <= 60
 ORDER BY phone_calls.duration;
-- Deretter, sjekk mulige navn på mottakeren av samtalen. Sorter dem etter samtalens varighet.
SELECT name, phone_calls.duration
  FROM people
  JOIN phone_calls
    ON people.phone_number = phone_calls.receiver
 WHERE phone_calls.year = 2021
   AND phone_calls.month = 7
   AND phone_calls.day = 28
   AND phone_calls.duration <= 60
   ORDER BY phone_calls.duration;

-- Ruth ga en ledetråd: Tyven kjørte bort fra bakeriet innen 10 minutter etter tyveriet. Sjekk derfor registreringsnumrene til biler innenfor dette tidsrommet. Finn deretter navnene til eierne av disse bilene. De kan være mistenkte.
SELECT name, bakery_security_logs.hour, bakery_security_logs.minute
  FROM people
  JOIN bakery_security_logs
    ON people.license_plate = bakery_security_logs.license_plate
 WHERE bakery_security_logs.year = 2021
   AND bakery_security_logs.month = 7
   AND bakery_security_logs.day = 28
   AND bakery_security_logs.activity = 'exit'
   AND bakery_security_logs.hour = 10
   AND bakery_security_logs.minute >= 15
   AND bakery_security_logs.minute <= 25
 ORDER BY bakery_security_logs.minute;

-- Bruce må være tyven, da han er nevnt på alle de 4 listene: Liste over passasjerer, liste over personer som utførte spesifikke minibanktransaksjoner, liste over personer som ringte, og liste over personer som kjørte bort fra bakeriet.
-- Han må ha flyktet til New York City, siden han tok flyvningen dit.
-- Robin må være medskyldig som kjøpte flybilletten og hjalp Bruce med å flykte til New York City.
