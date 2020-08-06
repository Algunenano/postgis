SELECT 'TG1', encode(ST_AsMVT(q, 'test', 4096, 'geom'), 'base64') FROM (SELECT 1 AS c1,
	ST_AsMVTGeom(ST_GeomFromText('POINT(25 17)'),
		ST_MakeBox2D(ST_Point(0, 0), ST_Point(4096, 4096)), 4096, 0, false) AS geom) AS q;