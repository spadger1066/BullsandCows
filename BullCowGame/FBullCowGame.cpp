//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Stephen on 03/08/2016.
//  Copyright © 2016 luminator.technology.com. All rights reserved.
//

#include "FBullCowGame.hpp"

void FBullCowGame::Reset() {
    constexpr int32 MAX_TRIES = 8;
    myMaxTries = MAX_TRIES;
    
    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;
    
    myCurrentTry = 1;
    return;
}

int32 FBullCowGame::GetMaxTries() const {
    return myMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const {
    return myCurrentTry;
}

bool FBullCowGame::IsGameWon() const {
    return false;
}

bool FBullCowGame::CheckGuessValidity(FString) {
    return false;
}

void FBullCowGame::IncTry() {
    myCurrentTry++;
    return;
}

// counts the Bulls and Cows and increments the try count
FBullCowCount FBullCowGame::SubmitGuess(FString guess) {
    
    // Increment the turn number
    myCurrentTry++;
    
    // Setup a return value
    FBullCowCount bullCowCount;
    
    // get the hidden word length
    long hiddenWordLen = MyHiddenWord.length();
    long guessLen = guess.length();
    
    // Loop through all letters in the guess
    for (int32 cntGuess = 0; cntGuess < guessLen ; cntGuess++) {
        //  compare letters against the hidden word
        for (int32 cntHW = 0; cntHW < hiddenWordLen ; cntHW++) {
            // if they match then
            if (guess[cntGuess] == MyHiddenWord[cntHW]) {
                // increment bulls if they are in the same place
                if (cntGuess == cntHW) {
                    bullCowCount.Bulls++;
                } else { // increment cows if they are not
                    bullCowCount.Cows++;
                }
            }
        }
    }
    return bullCowCount;
}