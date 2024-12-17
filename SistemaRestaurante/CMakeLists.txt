cmake_minimum_required(VERSION 3.10)
project(SistemaRestaurante)

set(CMAKE_CXX_STANDARD 17)

# Subdiretórios
add_subdirectory(src)

# Executável principal
add_executable(main src/main.cpp)

# Link do executável com a biblioteca src
target_link_libraries(main PRIVATE src)
