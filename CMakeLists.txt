cmake_minimum_required(VERSION 3.21)
project(MatamEx4)

set(CMAKE_CXX_STANDARD 11)

add_executable(MatamEx4 main.cpp utilities.cpp Player.cpp Card.cpp Card.h Goblin.cpp Goblin.h Dragon.cpp Dragon.h Vampire.cpp Vampire.h Fairy.cpp Fairy.h Barfight.cpp Barfight.h Pitfall.cpp Pitfall.h Merchant.cpp Merchant.h Treasure.cpp Treasure.h)
