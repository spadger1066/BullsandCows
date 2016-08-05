//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Stephen on 03/08/2016.
//  Copyright © 2016 luminator.technology.com. All rights reserved.
//
#include "FBullCowGame.hpp"

int32 FBullCowGame::GetMaxTries() const { return myMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return myCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return (int32)MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return false; }

EWordStatus FBullCowGame::CheckGuessValidity(FString guess) const {

    // if the guess isn't the isogram
    if (false) {
        return EWordStatus::Not_Isogram;
        // if the guess isn't all lowercase
    } else if (convertToLower(guess) != guess) {
        return EWordStatus::Not_Lowercase;
        // if the guess isn't the right length
    } else if (guess.length() != FBullCowGame::GetHiddenWordLength()) {
        return EWordStatus::Wrong_Length;
    } else {
        return EWordStatus::OK;
    }
}

void FBullCowGame::Reset() {
    constexpr int32 MAX_TRIES = 8;
    myMaxTries = MAX_TRIES;
    
    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;
    
    myCurrentTry = 1;
    return;
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

FString FBullCowGame::convertToLower(FString text) const {
    std::string str = text;
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}