cmake_minimum_required(VERSION 3.29 FATAL_ERROR)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(click_counter LANGUAGES CXX)
enable_language(CXX)



# Include and Link directories for system libraries (e.g., nlohmann)
include_directories(/usr/local/include/)
link_directories(/usr/local/lib)

file(GLOB SOURCES src/*.cxx src/core/*.cpp src/core/*.hpp)

# Add executable
add_executable(click_counter ${SOURCES}
        src/core/whd.h)

# Include directories for the project's core
target_include_directories(click_counter PRIVATE ${PROJECT_SOURCE_DIR}/src/core)

# Linking to macOS-specific frameworks
find_library(CORE_FOUNDATION_FRAMEWORK CoreFoundation)
find_library(APPLICATION_SERVICES_FRAMEWORK ApplicationServices)

# Ensure the frameworks are found
if(NOT CORE_FOUNDATION_FRAMEWORK)
        message(FATAL_ERROR "CoreFoundation framework not found")
endif()

if(NOT APPLICATION_SERVICES_FRAMEWORK)
        message(FATAL_ERROR "ApplicationServices framework not found")
endif()

target_include_directories(click_counter PRIVATE "/usr/local/include/nlohmann")
# Link the frameworks to the executable
target_link_libraries(click_counter PRIVATE
        "${CORE_FOUNDATION_FRAMEWORK}"
        "${APPLICATION_SERVICES_FRAMEWORK}"
        fmt  # Assuming fmt is correctly located in your project's lib directory
)

# Include directories for custom libraries (assuming fmt and others)
target_include_directories(click_counter PRIVATE ${PROJECT_SOURCE_DIR}/lib)
target_link_directories(click_counter PRIVATE ${PROJECT_SOURCE_DIR}/lib)

