cmake_minimum_required(VERSION 2.6)
enable_testing()

project(Geometry)

# Boost lib
find_package( Boost REQUIRED COMPONENTS regex )
include_directories( ${Boost_INCLUDE_DIRS} )

# C++11 activation
if(CMAKE_COMPILER_IS_GNUCXX)
   SET(ENABLE_CXX11 "-std=c++11")

   EXECUTE_PROCESS(COMMAND "${CMAKE_CXX_COMPILER} -dumpversion" OUTPUT_VARIABLE GCC_VERSION)
   if (GCC_VERSION VERSION_LESS 4.7)
      SET(ENABLE_CXX11 "-std=c++0x")
   endif()

   SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ENABLE_CXX11}")
endif()

set(TARGET geometry)

file(GLOB_RECURSE SOURCES Sources/*)

add_executable(${TARGET} ${SOURCES})

set(TEST_DIR "Tests")
set(TEST_PATTERN "Test*")
set(TEST_BIN "test.sh")

file(GLOB ALLTESTS "${TEST_DIR}/${TEST_PATTERN}")
foreach(file ${ALLTESTS})
    GET_FILENAME_COMPONENT(BASENAME ${file} NAME)
    add_test(${BASENAME} ../${TEST_DIR}/${TEST_BIN} ${file})
    set_tests_properties(${BASENAME}
    PROPERTIES PASS_REGULAR_EXPRESSION "Global      : PASSED")
endforeach()

target_link_libraries( ${TARGET} ${Boost_REGEX_LIBRARY} )
