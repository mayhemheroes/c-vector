# Fuzz
add_executable(c-vector-fuzzer fuzzer.c)
target_link_libraries(c-vector-fuzzer c-vector)
target_compile_options(c-vector-fuzzer PUBLIC -fsanitize=fuzzer)
target_link_options(c-vector-fuzzer PUBLIC -fsanitize=fuzzer)
