cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
message(STATUS "set env var")
set(ENV{CC} "/usr/local/opt/llvm/bin/clang")
set(ENV{CXX} "/usr/local/opt/llvm/bin/clang++")
set(ENV{LDFLAGS} "-L/usr/local/opt/llvm/lib")
set(ENV{CPPFLAGS} "-I/usr/local/opt/llvm/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wshadow -Wconversion -Wfloat-equal -Wno-char-subscripts")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftrapv -fsanitize=address,undefined -fno-omit-frame-pointer -fno-sanitize-recover")
message(STATUS "${CMAKE_CXX_FLAGS}")
 

#######################################################################
#                               Project                               #
#######################################################################
project(MatrixProduct CXX)
find_package(OpenMP)

# Create Main project
set(SOURCES
    merge_sort.cpp
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

