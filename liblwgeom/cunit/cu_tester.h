/**********************************************************************
 *
 * PostGIS - Spatial Types for PostgreSQL
 * http://postgis.net
 *
 * Copyright (C) 2009 Paul Ramsey <pramsey@cleverelephant.ca>
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU General Public Licence. See the COPYING file.
 *
 **********************************************************************/

#ifndef _CU_TESTER_H
#define _CU_TESTER_H 1

#include "liblwgeom.h"

#define MAX_CUNIT_ERROR_LENGTH 512

#define PG_ADD_TEST(suite, testfunc) CU_add_test(suite, #testfunc, testfunc)

/* Contains the most recent error message generated by lwerror. */
extern char cu_error_msg[];

/* Resets cu_error_msg back to blank. */
void cu_error_msg_reset(void);

/* Our internal callback to register Suites with the main tester */
typedef void (*PG_SuiteSetup)(void);

#define ASSERT_DOUBLE_EQUAL(o,e) do { \
  if ( o != e ) \
    fprintf(stderr, "[%s:%d]\n Expected: %g\n Obtained: %g\n", __FILE__, __LINE__, (double)(e), (o)); \
  CU_ASSERT_EQUAL(o,(double)e); \
} while (0);

#define ASSERT_INT_EQUAL(o,e) do { \
  if ( o != e ) \
    fprintf(stderr, "[%s:%d]\n Expected: %d\n Obtained: %d\n", __FILE__, __LINE__, (e), (o)); \
  CU_ASSERT_EQUAL(o,e); \
} while (0);

#define ASSERT_STRING_EQUAL(o,e) do { \
  if ( strcmp(o,e) != 0 ) \
    fprintf(stderr, "[%s:%d]\n Expected: %s\n Obtained: %s\n", __FILE__, __LINE__, (e), (o)); \
  CU_ASSERT_STRING_EQUAL(o,e); \
} while (0);

#define ASSERT_VARLENA_EQUAL(v, s) \
	do \
	{ \
		if (strncmp(v->data, s, LWSIZE_GET(v->size) - LWVARHDRSZ) != 0) \
		{ \
			fprintf( \
			    stderr, "[%s:%d]\n Expected: %s\n Obtained: %s\n", __FILE__, __LINE__, (s), (v->data)); \
			CU_FAIL(); \
		} \
		else \
			CU_PASS(); \
	} while (0);

#define ASSERT_LWGEOM_EQUAL(o, e) do { \
	if ( !lwgeom_same(o, e) ) { \
		char* wkt_o = lwgeom_to_ewkt(o); \
		char* wkt_e = lwgeom_to_ewkt(e); \
		fprintf(stderr, "[%s:%d]\n Expected: %s\n Obtained: %s\n", __FILE__, __LINE__, (wkt_o), (wkt_e)); \
		lwfree(wkt_o); \
		lwfree(wkt_e); \
	} \
	CU_ASSERT_TRUE(lwgeom_same(o, e)); \
} while(0);

#define ASSERT_INTARRAY_EQUAL(o, e, n) do { \
	size_t i = 0; \
	for (i = 0; i < n; i++) { \
		if (o[i] != e[i]) { \
			fprintf(stderr, "[%s:%d]", __FILE__, __LINE__); \
			fprintf(stderr, "\nExpected: ["); \
			for (i = 0; i < n; i++) \
				fprintf(stderr, " %d", e[i]); \
			fprintf(stderr, " ]\nObtained: ["); \
			for (i = 0; i < n; i++) \
				fprintf(stderr, " %d", o[i]); \
			fprintf(stderr, " ]\n"); \
			CU_FAIL(); \
			break; \
		} \
	} \
	CU_PASS(); \
} while(0);

#define ASSERT_POINT2D_EQUAL(o, e, eps) do { \
	CU_ASSERT_DOUBLE_EQUAL(o.x, e.x, eps); \
	CU_ASSERT_DOUBLE_EQUAL(o.y, e.y, eps); \
} while(0);

#define ASSERT_POINT4D_EQUAL(o, e, eps) do { \
	CU_ASSERT_DOUBLE_EQUAL(o.x, e.x, eps); \
	CU_ASSERT_DOUBLE_EQUAL(o.y, e.y, eps); \
	CU_ASSERT_DOUBLE_EQUAL(o.z, e.z, eps); \
	CU_ASSERT_DOUBLE_EQUAL(o.m, e.m, eps); \
} while(0);

/* Utility functions */
void do_fn_test(LWGEOM* (*transfn)(LWGEOM*), char *input_wkt, char *expected_wkt);

#endif /* _CU_TESTER_H */
