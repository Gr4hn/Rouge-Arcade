#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "clearScreen.h"
#include "sleepForSeconds.h"
#include "printCentered.h"
#include "getConsolewidth.h"
#include "paddingSelection.h"
#include "Hangman.h"
#include "loadWordsFromFile.h"
#include "regPlayers.h"
#include <iostream>

using namespace std;



TEST_CASE("Test Player class") {
    Player player1("Eric");
    REQUIRE(player1.getName() == "Eric");
    player1.setName("Erik");
    REQUIRE(player1.getName() == "Erik");
}
