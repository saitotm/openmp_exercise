cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
message(STATUS "set env var")
set(ENV{CC} "/usr/local/opt/llvm/bin/clang")
set(ENV{CXX} "/usr/local/opt/llvm/bin/clang++")
set(ENV{LDFLAGS} "-L/usr/local/opt/llvm/lib")
set(ENV{CPPFLAGS} "-I/usr/local/opt/llvm/include")

#######################################################################
#                               Project                               #
#######################################################################
project(MatrixProduct CXX)
find_package(OpenMP)

# Create Main project
set(SOURCES
    06array_mul.cpp
    06_verify.cpp
)

set(HEADERS
)

add_executable(main
    ${SOURCES}
    ${HEADERS}
)


if(OpenMP_CXX_FOUND)
	target_link_libraries(main PUBLIC OpenMP::OpenMP_CXX)
endif()


#######################################################################
#                              Benchmark                              #
#######################################################################
add_subdirectory(${PROJECT_SOURCE_DIR}/bench)



#######################################################################
#                                Test                                 #
#######################################################################
add_subdirectory(${PROJECT_SOURCE_DIR}/tests)

