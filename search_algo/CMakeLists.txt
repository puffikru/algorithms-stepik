cmake_minimum_required(VERSION 3.15)

project(algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

add_executable(algorithms days_count)

#env CC=gcc-8 CXX=g++-8 cmake ..
# Compile: g++ -std=c++17 -Wshadow -Wall -o "%e" "%f" -O2 -Wno-unused-result
# Build:   g++ -std=c++17 -Wshadow -Wall -o "%e" "%f" -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
