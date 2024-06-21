cmake_minimum_required(VERSION 3.29 FATAL_ERROR)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_language(OBJC)
project(click_counter LANGUAGES CXX)

add_executable(click_counter)
target_sources(click_counter PRIVATE "src/main.cxx")
