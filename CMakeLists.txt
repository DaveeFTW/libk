cmake_minimum_required(VERSION 2.8)

# TODO: replace with toolchain
set(CMAKE_SYSTEM_NAME "Generic")
set(CMAKE_C_COMPILER "arm-vita-eabi-gcc")
set(CMAKE_CXX_COMPILER "arm-vita-eabi-g++")

project(libk)

option(CREATE_PRX "produce skprx and suprx" OFF)

add_definitions(-Wl,-q -Wall -Werror -pedantic -Os -std=c99 -ffreestanding)

set(PDCLIB_DIR "${CMAKE_SOURCE_DIR}/thirdparty/pdclib")
file(GLOB PDCLIB_STRING_SOURCES "${PDCLIB_DIR}/functions/string/*.c")

include_directories(${PDCLIB_DIR}/includes)
include_directories(${PDCLIB_DIR}/internals)
include_directories(include)

add_library(string_objects OBJECT ${PDCLIB_STRING_SOURCES})
add_library(k $<TARGET_OBJECTS:string_objects>)

# custom targets to create dynamic libraries, if so desired
if (${CREATE_PRX})
	add_executable(libk.elf
		$<TARGET_OBJECTS:string_objects>
		${CMAKE_SOURCE_DIR}/src/vita.c
	)

	target_link_libraries(libk.elf -Wl,-q -nostdlib -nodefaultlibs)

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
	${CMAKE_SOURCE_DIR}/include/libk/string.h 
	${CMAKE_SOURCE_DIR}/include/libk/_PDCLIB_aux.h 
	${CMAKE_SOURCE_DIR}/include/libk/_PDCLIB_glue.h 
	${CMAKE_SOURCE_DIR}/include/libk/_PDCLIB_int.h
	${CMAKE_SOURCE_DIR}/include/_PDCLIB_config.h
	DESTINATION include/libk
)

install(TARGETS k
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)
