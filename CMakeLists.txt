cmake_minimum_required(VERSION 2.8)

set(CMAKE_SYSTEM_NAME "Generic")
set(CMAKE_C_COMPILER "arm-vita-eabi-gcc")
set(CMAKE_CXX_COMPILER "arm-vita-eabi-g++")

project(libk)

enable_language(ASM)

add_definitions(-Wl,-q -Wall -Werror -pedantic -Os -std=c99 -ffreestanding)

set(PDCLIB_DIR "${CMAKE_SOURCE_DIR}/thirdparty/pdclib")

file(GLOB PDCLIB_STRING_SOURCES "${PDCLIB_DIR}/functions/string/*.c")

set(LIBK_HEADERS 
	${CMAKE_SOURCE_DIR}/include/libk/string.h 
	${CMAKE_SOURCE_DIR}/include/libk/_PDCLIB_aux.h 
	${CMAKE_SOURCE_DIR}/include/libk/_PDCLIB_glue.h 
	${CMAKE_SOURCE_DIR}/include/libk/_PDCLIB_int.h
	${CMAKE_SOURCE_DIR}/include/_PDCLIB_config.h
)

include_directories(${PDCLIB_DIR}/includes)
include_directories(${PDCLIB_DIR}/internals)
include_directories(include)

add_library(string_objects OBJECT ${PDCLIB_STRING_SOURCES})

add_executable(libk.elf
	$<TARGET_OBJECTS:string_objects>
	${CMAKE_SOURCE_DIR}/src/vita.c
)

add_library(k $<TARGET_OBJECTS:string_objects>)

target_link_libraries(libk.elf -Wl,-q -nostdlib -nodefaultlibs)

add_custom_target(libk.skprx ALL
	COMMAND vita-elf-create -n -e ${CMAKE_SOURCE_DIR}/kernel_exports.yml libk.elf libk.vkprx ${CMAKE_SOURCE_DIR}/kernel.json
	COMMAND vita-make-fself libk.vkprx libk.skprx
	COMMAND vita-elf-export k libk.elf ${CMAKE_SOURCE_DIR}/kernel_exports.yml libk_kernel.json
)

add_custom_target(libk.suprx ALL
	COMMAND vita-elf-create -n -e ${CMAKE_SOURCE_DIR}/user_exports.yml libk.elf libk.vuprx ${CMAKE_SOURCE_DIR}/kernel.json
	COMMAND vita-make-fself libk.vuprx libk.suprx
	COMMAND vita-elf-export u libk.elf ${CMAKE_SOURCE_DIR}/user_exports.yml libk_user.json
)

add_dependencies(libk.skprx libk.elf)
add_dependencies(libk.suprx libk.elf)

install(FILES ${LIBK_HEADERS}
	DESTINATION include/libk)

install(TARGETS k
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib)

#install(TARGETS libk.skprx DESTINATION bin)
#install(TARGETS ${PDCLIB_HEADERS} DESTINATION include/klibk)

#add_library(pdclib ${PDCLIB_SOURCES})
