# Escape from Alcatraz

[![C++17](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=c%2B%2B)](https://isocpp.org)
[![CMake](https://img.shields.io/badge/CMake-3.10-064F8C?logo=cmake)](https://cmake.org)
[![Platform](https://img.shields.io/badge/platform-Windows-blue)](https://en.wikipedia.org/wiki/Microsoft_Windows)
[![License](https://img.shields.io/badge/license-MIT-green)](LICENSE)

A text-based interactive fiction game based on the 1962 Alcatraz escape. You play as Frank Morris, and each choice branches the story toward different endings.

## Background

Loosely inspired by the 1962 Alcatraz escape, where Frank Morris and the Anglin brothers fled the prison through a ventilation duct using dummy heads and a raft made from raincoats. That event and the 1979 film with Clint Eastwood were the starting point, but most of the scenes, characters, and routes in this game are fictional.

## Features

- Multiple story paths with different endings
- C++17, shared_ptr-based scene graph, RAII
- SOLID-inspired separation of concerns: Scene, Story, Game
- Templated input validation with type-safe parsing
- Dual language support (English / Spanish) with runtime selection
- No external dependencies (pure C++ standard library)

## Project Structure

```
EscapeFromAlcatraz/
  CMakeLists.txt
  src/
    main.cpp
    core/Scene.h/.cpp
    core/Story.h/.cpp
    core/Game.h/.cpp
    core/Language.h
    data/EscapeStory.h/.cpp
  util/Input.h
```

| Layer | Responsibility |
|---|---|
| Scene | Stores narrations, decisions, and child scenes |
| Story | Manages the scene graph, traversal, and restarts |
| Game | Runs the narrative loop and user interaction |
| EscapeStory | Builds the branching graph |

## Getting Started

Requirements: C++17 compiler, CMake >= 3.10.

```
cmake -B build
cmake --build build
./build/escape.exe
```

Or compile manually:

```
g++ -std=c++17 -Isrc -Iutil src/main.cpp src/core/Scene.cpp src/core/Story.cpp src/core/Game.cpp src/data/EscapeStory.cpp -o escape
```

## Gameplay

You play as Frank Morris, inmate AZ-1441, at Alcatraz. Narrated scenes advance the story. At key points you make choices that determine the outcome. Some paths end in freedom, others in capture or death. The game supports English and Spanish.

## License

MIT.
