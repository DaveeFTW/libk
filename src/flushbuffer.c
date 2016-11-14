/* $Id$ */

/* _PDCLIB_flushbuffer( struct _PDCLIB_file_t * )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is an example implementation of _PDCLIB_flushbuffer() fit for
   use with POSIX kernels.
*/

#include <stdio.h>
#include <string.h>

#ifndef REGTEST
#include <_PDCLIB_glue.h>

typedef long ssize_t;
extern ssize_t write( int fd, const void * buf, size_t count );

/* The number of attempts to complete an output buffer flushing before giving
 *    up.
 *    */
#define _PDCLIB_IO_RETRIES 1

/* What the system should do after an I/O operation did not succeed, before   */
/* trying again. (Empty by default.)                                          */
#define _PDCLIB_IO_RETRY_OP( stream )

int _PDCLIB_flushbuffer( struct _PDCLIB_file_t * stream )
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

