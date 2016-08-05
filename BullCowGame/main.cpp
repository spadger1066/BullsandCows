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

    do {
        PlayGame();
    } while (AskToPlayAgain());

    return 0;
}

void PlayGame(){
    BCGame.Reset();
    
    PrintIntro();
    
    // Loop for the number of turns asking for guesses
    for (int32 count = 1; count <= BCGame.GetMaxTries(); count++) {
        FText guess = GetGuess();
        
        EWordStatus status = BCGame.CheckGuessValidity(guess);
        
        switch (status) {
            case EWordStatus::OK: {
                FBullCowCount bullCowCount = BCGame.SubmitGuess(guess);
                // print the number of bulls and cows
                std::cout << "Bulls " << bullCowCount.Bulls;
                std::cout << " Cows " << bullCowCount.Cows;
                std::cout << std::endl;

                break;
            }
            case EWordStatus::Wrong_Length: {
                std::cout << "Wrong length! Try again.\n";
                break;
            }
            case EWordStatus::Not_Lowercase : {
                std::cout << "Not Lowercase! Try again.\n";
                break;
            }
            default: {
                std::cout << "Not Valid! Try again.\n";
                break;
            }
        }
        if (status == EWordStatus::OK) {
        }
    }
    return;
}

// Introduce the game
void PrintIntro() {
    std::cout << "Welcome to Bulls and Cows\n";
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
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