cmake_minimum_required(VERSION 2.8)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/mep-toolchain.cmake)

project(libk C)

add_definitions(-Wl,-q -Wall -Werror -pedantic -Os -std=c99 -ffreestanding)

set(PDCLIB_DIR "${CMAKE_SOURCE_DIR}/thirdparty/pdclib")
file(GLOB PDCLIB_STRING_SOURCES "${PDCLIB_DIR}/functions/string/*.c")

include_directories(${PDCLIB_DIR}/includes)
include_directories(${PDCLIB_DIR}/internals)
include_directories(include)

add_library(string_objects OBJECT ${PDCLIB_STRING_SOURCES})
add_library(k $<TARGET_OBJECTS:string_objects>)

install(FILES
	${CMAKE_SOURCE_DIR}/include/libk/string.h 
	${CMAKE_SOURCE_DIR}/include/libk/_PDCLIB_aux.h 
	${CMAKE_SOURCE_DIR}/include/libk/_PDCLIB_glue.h 
	${CMAKE_SOURCE_DIR}/include/libk/_PDCLIB_int.h
	${CMAKE_SOURCE_DIR}/include/_PDCLIB_config.h
	DESTINATION include/libk
)

install(FILES
	${CMAKE_SOURCE_DIR}/mep-toolchain.cmake
	DESTINATION share
)

install(TARGETS k
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)
