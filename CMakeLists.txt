cmake_minimum_required(VERSION 3.23)

project(Game)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_PROGRESS ON
    GIT_SHALLOW ON
    GIT_CONFIG http.version=1.1
    EXCLUDE_FROM_ALL
    SYSTEM)

FetchContent_MakeAvailable(SFML)

add_executable(main)

# MAIN TARGET
target_sources(main
  PRIVATE
    main.cpp 
)

target_compile_features(main
  PRIVATE
    cxx_std_20
)

target_link_libraries(main
  PRIVATE 
    SFML::Graphics
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)