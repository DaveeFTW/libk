/* $Id$ */

/* tmpfile( void )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <stdio.h>

#ifndef REGTEST


#include <_PDCLIB_glue.h>


extern struct _PDCLIB_file_t * _PDCLIB_filelist;

/* This is an example implementation of tmpfile() fit for use with POSIX
   kernels.
*/
struct _PDCLIB_file_t * tmpfile( void )
{
	return NULL;
}

#endif

#ifdef TEST
#include <_PDCLIB_test.h>
#include <string.h>

int main()
{
    FILE * fh;
#ifndef REGTEST
    char filename[ L_tmpnam ];
    FILE * fhtest;
#endif
    TESTCASE( ( fh = tmpfile() ) != NULL );
    TESTCASE( fputc( 'x', fh ) == 'x' );
    /* Checking that file is actually there */
    TESTCASE_NOREG( strcpy( filename, fh->filename ) == filename );
    TESTCASE_NOREG( ( fhtest = fopen( filename, "r" ) ) != NULL );
    TESTCASE_NOREG( fclose( fhtest ) == 0 );
    /* Closing tmpfile */
    TESTCASE( fclose( fh ) == 0 );
    /* Checking that file was deleted */
    TESTCASE_NOREG( fopen( filename, "r" ) == NULL );
    return TEST_RESULTS;
}

#endif

