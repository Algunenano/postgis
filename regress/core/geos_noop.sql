SELECT
	--ST_AsEWKT(g),
	ST_AsEWKT(postgis_geos_noop(g)) FROM ( VALUES
('SRID=4326;POINT EMPTY'),
('SRID=4326;MULTIPOINT EMPTY'),
('SRID=4326;LINESTRING EMPTY'),
('SRID=4326;MULTILINESTRING EMPTY'),
('SRID=4326;POLYGON EMPTY'),
('SRID=4326;MULTIPOLYGON EMPTY'),
('SRID=4326;GEOMETRYCOLLECTION EMPTY'),
('SRID=4326;GEOMETRYCOLLECTION(POINT EMPTY, LINESTRING EMPTY, POLYGON EMPTY, GEOMETRYCOLLECTION EMPTY)')
) as foo(g);
