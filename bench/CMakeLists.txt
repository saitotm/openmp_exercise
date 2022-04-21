#######################################################################
#                              Benchmark                              #
#######################################################################

add_executable( bench_xxx EXCLUDE_FROM_ALL bench_xxx.cpp )
add_executable( bench_yyy EXCLUDE_FROM_ALL bench_yyy.cpp )
add_executable( bench_zzz EXCLUDE_FROM_ALL bench_zzz.cpp )

if(OpenMP_CXX_FOUND)
	target_link_libraries(bench_xxx PUBLIC OpenMP::OpenMP_CXX)
	target_link_libraries(bench_yyy PUBLIC OpenMP::OpenMP_CXX)
	target_link_libraries(bench_zzz PUBLIC OpenMP::OpenMP_CXX)
endif()

find_package(benchmark REQUIRED)
target_link_libraries(bench_xxx PRIVATE benchmark::benchmark)
target_link_libraries(bench_yyy PRIVATE benchmark::benchmark)
target_link_libraries(bench_zzz PRIVATE benchmark::benchmark)

