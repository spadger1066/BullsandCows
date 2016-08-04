//
//  main.cpp
//  BullCowGame
//
//  Created by Stephen on 03/08/2016.
//  Copyright © 2016 luminator.technology.com. All rights reserved.
//

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetGuess();
void PlayGame();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

int main() {

    PrintIntro();

    do {
        PlayGame();
    } while (AskToPlayAgain());

    return 0;
}

void PlayGame(){
    BCGame.Reset();
    
    // Loop for the number of turns asking for guesses
    for (int32 count = 1; count <= BCGame.GetMaxTries(); count++) {
        FText guess = GetGuess();
        FBullCowCount bullCowCount = BCGame.SubmitGuess(guess);
        // print the number of bulls and cows
        std::cout << "Bulls " << bullCowCount.Bulls;
        std::cout << " Cows " << bullCowCount.Cows;
        std::cout << std::endl;
    }
    return;
}

// Introduce the game
void PrintIntro() {
    constexpr int32 WORD_LENGTH = 9;

    std::cout << "Welcome to Bulls and Cows\n";
    std::cout << "Can you guess the " << WORD_LENGTH;
    std::cout << " letter isogram I'm thinking of?\n";
    return;
}

// Get a guess from the player
FText GetGuess() {
    FText Guess = "";
    std::cout << BCGame.GetCurrentTry() << ". Make a guess: ";
    //BCGame.IncTry();
    getline(std::cin, Guess);
    return Guess;
}

bool AskToPlayAgain(){
    std::cout << "Do you want to play again?";
    FText resp;
    getline(std::cin, resp);
    
    return (resp[0] == 'y' || resp[0] == 'Y');
}