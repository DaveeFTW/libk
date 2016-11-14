/* $Id$ */

/* _PDCLIB_allocpages( int const )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is an example implementation of _PDCLIB_allocpages() (declared in
   _PDCLIB_config.h), fit for use with POSIX kernels.
*/

#include <stdint.h>
#include <stddef.h>

int brk( void * );
void * sbrk( intptr_t );

#ifndef _PDCLIB_GLUE_H
#define _PDCLIB_GLUE_H _PDCLIB_GLUE_H
#include <_PDCLIB_glue.h>
#endif


void * _PDCLIB_allocpages( int const n )
{
	return NULL;
}

#ifdef TEST
#include <_PDCLIB_test.h>

int main( void )
{
#ifndef REGTEST
    {
    char * startbreak = sbrk( 0 );
    TESTCASE( _PDCLIB_allocpages( 0 ) );
    TESTCASE( ( (char *)sbrk( 0 ) - startbreak ) <= _PDCLIB_PAGESIZE );
    startbreak = sbrk( 0 );
    TESTCASE( _PDCLIB_allocpages( 1 ) );
    TESTCASE( sbrk( 0 ) == startbreak + ( 1 * _PDCLIB_PAGESIZE ) );
    TESTCASE( _PDCLIB_allocpages( 5 ) );
    TESTCASE( sbrk( 0 ) == startbreak + ( 6 * _PDCLIB_PAGESIZE ) );
    TESTCASE( _PDCLIB_allocpages( -3 ) );
    TESTCASE( sbrk( 0 ) == startbreak + ( 3 * _PDCLIB_PAGESIZE ) );
    }
#endif
    return TEST_RESULTS;
}

#endif
