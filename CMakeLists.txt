cmake_minimum_required(VERSION 3.20)
project(MatamEx4)

set(CMAKE_CXX_STANDARD 11)

add_executable(MatamEx4 testsMain.cpp Players/Player.cpp Players/Wizard.cpp Players/Fighter.cpp Players/Rogue.cpp utilities.cpp Cards/Card.cpp Cards/BattleCard.cpp Cards/Goblin.cpp Cards/Dragon.cpp Cards/Vampire.cpp Cards/Fairy.cpp Cards/Barfight.cpp Cards/Pitfall.cpp Cards/Treasure.cpp Mtmchkin.cpp Cards/Merchant.cpp Cards/Gang.cpp Cards/Gang.h)
