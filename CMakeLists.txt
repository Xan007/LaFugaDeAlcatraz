cmake_minimum_required(VERSION 3.10)
project(EscapeFromAlcatraz LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(escape src/main.cpp
                src/core/Scene.cpp
                src/core/Scene.h
                src/core/Story.cpp
                src/core/Story.h
                src/core/Game.cpp
                src/core/Game.h
                 src/core/Language.h
                 src/data/EscapeStory.cpp
                src/data/EscapeStory.h
                util/Input.h)

target_include_directories(escape PRIVATE src util)
