cmake_minimum_required(VERSION 2.8)

# TODO: replace with toolchain
set(CMAKE_SYSTEM_NAME "Generic")
set(CMAKE_C_COMPILER "arm-vita-eabi-gcc")
set(CMAKE_CXX_COMPILER "arm-vita-eabi-g++")

project(libk)

option(CREATE_PRX "produce skprx and suprx" OFF)

add_definitions(-Wl,-q -Wall -Werror -pedantic -Os -std=c99 -ffreestanding)

set(PDCLIB_DIR "${CMAKE_SOURCE_DIR}/thirdparty/pdclib")

set(PDCLIB_INTERNAL_SOURCES
#1	"${PDCLIB_DIR}/functions/_PDCLIB/assert.c"
	"${PDCLIB_DIR}/functions/_PDCLIB/atomax.c"
#1	"${PDCLIB_DIR}/functions/_PDCLIB/closeall.c"
	"${PDCLIB_DIR}/functions/_PDCLIB/digits.c"
	"${PDCLIB_DIR}/functions/_PDCLIB/errno.c"
	"${PDCLIB_DIR}/functions/_PDCLIB/filemode.c"
	"${PDCLIB_DIR}/functions/_PDCLIB/prepread.c"
	"${PDCLIB_DIR}/functions/_PDCLIB/prepwrite.c"
	"${PDCLIB_DIR}/functions/_PDCLIB/print.c"
	"${PDCLIB_DIR}/functions/_PDCLIB/scan.c"
	"${PDCLIB_DIR}/functions/_PDCLIB/seed.c"
	#"${PDCLIB_DIR}/functions/_PDCLIB/stdarg.c"
	"${PDCLIB_DIR}/functions/_PDCLIB/strtox_main.c"
	"${PDCLIB_DIR}/functions/_PDCLIB/strtox_prelim.c"
)

set(PDCLIB_CTYPE_SOURCES
	"${PDCLIB_DIR}/functions/ctype/isspace.c"
	"${PDCLIB_DIR}/functions/ctype/tolower.c"
)

set(PDCLIB_INTTYPES_SOURCES
	"${PDCLIB_DIR}/functions/inttypes/imaxabs.c"
	"${PDCLIB_DIR}/functions/inttypes/imaxdiv.c"
	"${PDCLIB_DIR}/functions/inttypes/strtoimax.c"
	"${PDCLIB_DIR}/functions/inttypes/strtoumax.c"
)

set(PDCLIB_STDIO_SOURCES
	"${PDCLIB_DIR}/functions/stdio/clearerr.c"
#1	"${PDCLIB_DIR}/functions/stdio/fclose.c"
	"${PDCLIB_DIR}/functions/stdio/feof.c"
	"${PDCLIB_DIR}/functions/stdio/ferror.c"
	"${PDCLIB_DIR}/functions/stdio/fflush.c"
	"${PDCLIB_DIR}/functions/stdio/fgetc.c"
	"${PDCLIB_DIR}/functions/stdio/fgetpos.c"
	"${PDCLIB_DIR}/functions/stdio/fgets.c"
#1	"${PDCLIB_DIR}/functions/stdio/fopen.c"
	"${PDCLIB_DIR}/functions/stdio/fprintf.c"
	"${PDCLIB_DIR}/functions/stdio/fputc.c"
	"${PDCLIB_DIR}/functions/stdio/fputs.c"
	"${PDCLIB_DIR}/functions/stdio/fread.c"
#1	"${PDCLIB_DIR}/functions/stdio/freopen.c"
	"${PDCLIB_DIR}/functions/stdio/fscanf.c"
	"${PDCLIB_DIR}/functions/stdio/fseek.c"
	"${PDCLIB_DIR}/functions/stdio/fsetpos.c"
	"${PDCLIB_DIR}/functions/stdio/ftell.c"
	"${PDCLIB_DIR}/functions/stdio/fwrite.c"
	"${PDCLIB_DIR}/functions/stdio/gets.c"
	"${PDCLIB_DIR}/functions/stdio/perror.c"
	"${PDCLIB_DIR}/functions/stdio/printf.c"
	"${PDCLIB_DIR}/functions/stdio/puts.c"
	"${PDCLIB_DIR}/functions/stdio/rename.c"
	"${PDCLIB_DIR}/functions/stdio/rewind.c"
	"${PDCLIB_DIR}/functions/stdio/scanf.c"
#1	"${PDCLIB_DIR}/functions/stdio/setbuf.c"
#1	"${PDCLIB_DIR}/functions/stdio/setvbuf.c"
	"${PDCLIB_DIR}/functions/stdio/snprintf.c"
	"${PDCLIB_DIR}/functions/stdio/sprintf.c"
	"${PDCLIB_DIR}/functions/stdio/sscanf.c"
#1	"${PDCLIB_DIR}/functions/stdio/tmpnam.c"
	"${PDCLIB_DIR}/functions/stdio/ungetc.c"
	"${PDCLIB_DIR}/functions/stdio/vfprintf.c"
	"${PDCLIB_DIR}/functions/stdio/vfscanf.c"
	"${PDCLIB_DIR}/functions/stdio/vprintf.c"
	"${PDCLIB_DIR}/functions/stdio/vscanf.c"
	"${PDCLIB_DIR}/functions/stdio/vsnprintf.c"
	"${PDCLIB_DIR}/functions/stdio/vsprintf.c"
	"${PDCLIB_DIR}/functions/stdio/vsscanf.c"
)

set(PDCLIB_STDLIB_SOURCES
	"${PDCLIB_DIR}/functions/stdlib/_Exit.c"
#1	"${PDCLIB_DIR}/functions/stdlib/abort.c"
	"${PDCLIB_DIR}/functions/stdlib/abs.c"
#1	"${PDCLIB_DIR}/functions/stdlib/atexit.c"
	"${PDCLIB_DIR}/functions/stdlib/atoi.c"
	"${PDCLIB_DIR}/functions/stdlib/atol.c"
	"${PDCLIB_DIR}/functions/stdlib/atoll.c"
	"${PDCLIB_DIR}/functions/stdlib/bsearch.c"
#1	"${PDCLIB_DIR}/functions/stdlib/calloc.c"
	"${PDCLIB_DIR}/functions/stdlib/div.c"
#1	"${PDCLIB_DIR}/functions/stdlib/exit.c"
#1	"${PDCLIB_DIR}/functions/stdlib/free.c"
	"${PDCLIB_DIR}/functions/stdlib/labs.c"
	"${PDCLIB_DIR}/functions/stdlib/ldiv.c"
	"${PDCLIB_DIR}/functions/stdlib/llabs.c"
	"${PDCLIB_DIR}/functions/stdlib/lldiv.c"
#1	"${PDCLIB_DIR}/functions/stdlib/malloc.c"
	"${PDCLIB_DIR}/functions/stdlib/qsort.c"
	"${PDCLIB_DIR}/functions/stdlib/rand.c"
#1	"${PDCLIB_DIR}/functions/stdlib/realloc.c"
	"${PDCLIB_DIR}/functions/stdlib/srand.c"
	"${PDCLIB_DIR}/functions/stdlib/strtol.c"
	"${PDCLIB_DIR}/functions/stdlib/strtoll.c"
	"${PDCLIB_DIR}/functions/stdlib/strtoul.c"
	"${PDCLIB_DIR}/functions/stdlib/strtoull.c"
)

set(PDCLIB_STRING_SOURCES
	"${PDCLIB_DIR}/functions/string/memchr.c"
	"${PDCLIB_DIR}/functions/string/memcmp.c"
	"${PDCLIB_DIR}/functions/string/memcpy.c"
	"${PDCLIB_DIR}/functions/string/memmove.c"
	"${PDCLIB_DIR}/functions/string/memset.c"
	"${PDCLIB_DIR}/functions/string/strcat.c"
	"${PDCLIB_DIR}/functions/string/strchr.c"
	"${PDCLIB_DIR}/functions/string/strcmp.c"
	"${PDCLIB_DIR}/functions/string/strcoll.c"
	"${PDCLIB_DIR}/functions/string/strcpy.c"
	"${PDCLIB_DIR}/functions/string/strcspn.c"
	"${PDCLIB_DIR}/functions/string/strerror.c"
	"${PDCLIB_DIR}/functions/string/strlen.c"
	"${PDCLIB_DIR}/functions/string/strncat.c"
	"${PDCLIB_DIR}/functions/string/strncmp.c"
	"${PDCLIB_DIR}/functions/string/strncpy.c"
	"${PDCLIB_DIR}/functions/string/strpbrk.c"
	"${PDCLIB_DIR}/functions/string/strrchr.c"
	"${PDCLIB_DIR}/functions/string/strspn.c"
	"${PDCLIB_DIR}/functions/string/strstr.c"
	"${PDCLIB_DIR}/functions/string/strtok.c"
	"${PDCLIB_DIR}/functions/string/strxfrm.c"
)

set(LIBK_SOURCES
	"${CMAKE_SOURCE_DIR}/src/io.c"
	"${CMAKE_SOURCE_DIR}/src/fillbuffer.c"
	"${CMAKE_SOURCE_DIR}/src/flushbuffer.c"
	"${CMAKE_SOURCE_DIR}/src/close.c"
	"${CMAKE_SOURCE_DIR}/src/seek.c"
	"${CMAKE_SOURCE_DIR}/src/rename.c"
	"${CMAKE_SOURCE_DIR}/src/remove.c"
	"${CMAKE_SOURCE_DIR}/src/open.c"
	"${CMAKE_SOURCE_DIR}/src/allocpages.c"
	"${CMAKE_SOURCE_DIR}/src/_Exit.c"
	"${CMAKE_SOURCE_DIR}/src/tmpfile.c"
)

include_directories(${PDCLIB_DIR}/includes)
include_directories(${PDCLIB_DIR}/internals)
include_directories(include)

add_library(libk_objs OBJECT 
	${PDCLIB_INTERNAL_SOURCES} 
	${PDCLIB_CTYPE_SOURCES}
	${PDCLIB_INTTYPES_SOURCES}
	${PDCLIB_STDIO_SOURCES}
	${PDCLIB_STDLIB_SOURCES}
	${PDCLIB_STRING_SOURCES}
	${LIBK_SOURCES}
)

add_library(k $<TARGET_OBJECTS:libk_objs>)

# custom targets to create dynamic libraries, if so desired
if (${CREATE_PRX})
	add_executable(libk.elf
		$<TARGET_OBJECTS:libk_objs>
		${CMAKE_SOURCE_DIR}/src/vita.c
	)

	target_link_libraries(libk.elf -Wl,-q -nostdlib -nodefaultlibs
		gcc
	)

	add_custom_target(libk.skprx ALL
		COMMAND vita-elf-create -n -e ${CMAKE_SOURCE_DIR}/kernel_exports.yml libk.elf libk.vkprx
		COMMAND vita-make-fself libk.vkprx libk.skprx
		COMMAND vita-elf-export k libk.elf ${CMAKE_SOURCE_DIR}/kernel_exports.yml libk_kernel.json
	)

	add_custom_target(libk.suprx ALL
		COMMAND vita-elf-create -n -e ${CMAKE_SOURCE_DIR}/user_exports.yml libk.elf libk.vuprx
		COMMAND vita-make-fself libk.vuprx libk.suprx
		COMMAND vita-elf-export u libk.elf ${CMAKE_SOURCE_DIR}/user_exports.yml libk_user.json
	)

	add_dependencies(libk.skprx libk.elf)
	add_dependencies(libk.suprx libk.elf)
endif()

install(FILES
	${CMAKE_SOURCE_DIR}/include/libk/_PDCLIB_aux.h 
	${CMAKE_SOURCE_DIR}/include/libk/_PDCLIB_glue.h 
	${CMAKE_SOURCE_DIR}/include/libk/_PDCLIB_int.h
	${CMAKE_SOURCE_DIR}/include/libk/assert.h
	${CMAKE_SOURCE_DIR}/include/libk/ctype.h
	${CMAKE_SOURCE_DIR}/include/libk/errno.h
	${CMAKE_SOURCE_DIR}/include/libk/inttypes.h
	${CMAKE_SOURCE_DIR}/include/libk/iso646.h
	${CMAKE_SOURCE_DIR}/include/libk/limits.h
	${CMAKE_SOURCE_DIR}/include/libk/stdarg.h
	${CMAKE_SOURCE_DIR}/include/libk/stdbool.h
	${CMAKE_SOURCE_DIR}/include/libk/stddef.h
	${CMAKE_SOURCE_DIR}/include/libk/stdint.h
	${CMAKE_SOURCE_DIR}/include/libk/stdio.h
	${CMAKE_SOURCE_DIR}/include/libk/stdlib.h
	${CMAKE_SOURCE_DIR}/include/libk/string.h
	${CMAKE_SOURCE_DIR}/include/_PDCLIB_config.h
	DESTINATION include/libk
)

install(TARGETS k
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)
