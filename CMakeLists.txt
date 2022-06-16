cmake_minimum_required(VERSION 3.20)
project(MatamEx4)

set(CMAKE_CXX_STANDARD 11)

add_executable(MatamEx4 main.cpp Player.cpp Wizard.cpp Fighter.cpp Rogue.cpp utilities.cpp Card.cpp BattleCard.cpp Goblin.cpp Dragon.cpp Vampire.cpp  Fairy.cpp Barfight.cpp Pitfall.cpp Treasure.cpp Mtmchkin.cpp Merchant.cpp)
