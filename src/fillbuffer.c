/* $Id$ */

/* _PDCLIB_fillbuffer( struct _PDCLIB_file_t * stream )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is an example implementation of _PDCLIB_fillbuffer() fit for
   use with POSIX kernels.
*/

#include <stdio.h>

#ifndef REGTEST
#include <_PDCLIB_glue.h>

typedef long ssize_t;
extern ssize_t read( int fd, void * buf, size_t count );

int _PDCLIB_fillbuffer( struct _PDCLIB_file_t * stream )
{
	_PDCLIB_errno = _PDCLIB_EIO;
	return EOF;
}

#endif

#ifdef TEST
#include <_PDCLIB_test.h>

int main( void )
{
    /* Testing covered by ftell.c */
    return TEST_RESULTS;
}

#endif

