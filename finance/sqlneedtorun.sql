-- Sletter eksisterende tabeller hvis de finnes
DROP TABLE IF EXISTS users;
DROP TABLE IF EXISTS trades;

-- Oppretter en tabell for å lagre brukerdata
CREATE TABLE users (
    id INTEGER PRIMARY KEY,
    username TEXT NOT NULL,
    hash TEXT NOT NULL,
    cash NUMERIC NOT NULL DEFAULT 10000.00
);

-- Oppretter en unik indeks på brukernavnet for rask søking
CREATE UNIQUE INDEX username ON users (username);

-- Oppretter en tabell for å lagre transaksjonsdata
CREATE TABLE trades (
    id INTEGER NOT NULL,
    transaction_id INTEGER PRIMARY KEY AUTOINCREMENT,
    symbol TEXT NOT NULL,
    name TEXT NOT NULL,
    shares INTEGER NOT NULL,
    price NUMERIC NOT NULL,
    transacted TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY(id) REFERENCES users(id)
);

-- Forklaring av trades-tabellen:
-- id: Brukerens ID som utførte transaksjonen, kobles til "users"-tabellen
-- transaction_id: Unik ID for hver transaksjon, som øker automatisk
-- symbol: Aksjesymbolet som ble handlet (f.eks. AAPL, TSLA)
-- name: Navnet på aksjen
-- shares: Antall aksjer som ble handlet
-- price: Prisen på hver aksje da transaksjonen ble gjennomført
-- transacted: Tidspunkt for når transaksjonen fant sted, settes automatisk til gjeldende tid
-- FOREIGN KEY: Kobler brukerens ID til "id"-kolonnen i "users"-tabellen
