//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Stephen on 03/08/2016.
//  Copyright © 2016 luminator.technology.com. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <string>
#include <algorithm>

#endif /* FBullCowGame_hpp */

using FString = std::string;
using int32 = int;

// All value initiated to zero
struct FBullCowCount {
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EWordStatus {
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase,
    Not_a_Word,
    Nothing_Entered
};

class FBullCowGame {
public:
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;

    bool IsGameWon() const;
    EWordStatus CheckGuessValidity(FString) const;
    void Reset(); // TODO make a more rich return statement
    void IncTry();
    FString convertToLower(FString) const;
    
    
    FBullCowCount SubmitGuess(FString);
    
private:
    int32 myMaxTries = 5;
    int32 myCurrentTry = 1;
    FString MyHiddenWord;
};