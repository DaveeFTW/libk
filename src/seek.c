/* $Id$ */

/* int64_t _PDCLIB_seek( FILE *, int64_t, int )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <stdio.h>

#ifndef _PDCLIB_GLUE_H
#define _PDCLIB_GLUE_H
#include <_PDCLIB_glue.h>
#endif

extern _PDCLIB_int64_t lseek64( int fd, _PDCLIB_int64_t offset, int whence );

_PDCLIB_int64_t _PDCLIB_seek( struct _PDCLIB_file_t * stream, _PDCLIB_int64_t offset, int whence )
{
    _PDCLIB_errno = _PDCLIB_EIO;
    return EOF;
}

#ifdef TEST
#include <_PDCLIB_test.h>

int main()
{
    /* Testing covered by ftell.c */
    return TEST_RESULTS;
}

#endif

