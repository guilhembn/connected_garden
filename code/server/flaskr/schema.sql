DROP TABLE IF EXISTS measure;

CREATE TABLE measure (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    timestamp INTEGER NOT NULL,
    temperature INTEGER,
    humidity INTEGER,
    estimatedTimestamp INTEGER
);