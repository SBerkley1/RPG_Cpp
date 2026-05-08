cmake_minimum_required(VERSION 3.10)
project(RPG_GAME)

set(CMAKE_CXX_STANDARD 17)

include_directories(header)

add_executable(RPG_GAME
    src/main.cpp
    src/Ability.cpp
    src/AbilityFactory.cpp
    src/Character.cpp
    src/HP.cpp
    src/Player.cpp
    src/Monster.cpp
    src/Mana.cpp
  "header/Reveal.h")