// Fill out your copyright notice in the Description page of Project Settings.
/*
    Rules:
        Bulls are correct letter in the correct spot
        Cows are correct letter in the wrong spot
        The word must be an Isogram (No repeating letters)
 */
#include "BullCowCartridge.h"


/*
Create a small array of isograms.
return 1 array index at the start of the game */
FString MakeNewWord()
{
    FString HiddenWord = TEXT("cake");
    return HiddenWord;
}

/* TODO: Learn about classs, am I in one already? where is my this? */
FString HiddenWord = MakeNewWord();


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();    
    PrintLine(TEXT("Welcome to Bulls & Cows!"));
    PrintLine(TEXT("You need to guess a secret word."));
    PrintLine(FString::Printf(TEXT("It has %i letters..."), HiddenWord.Len()));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    
    if(Input.Len() == HiddenWord.Len())
    {
        /* More logic here
        
            Need to parse the hidden word and compair it to input word at a char by char level.
            (make this a method)

         */
        if(HiddenWord.Equals(Input))
        {
            PrintLine(TEXT("You guessed the word! You win!"));
        }
        else
        {
            PrintLine(TEXT("Your guess has the same number of letters but it's not the right word."));
        }
        
        
    }
    else if (Input.Len() > HiddenWord.Len())
    {
        PrintLine(TEXT("Too many letters dope! Try again..."));
    }
    else
    {
        PrintLine(FString::Printf(TEXT("Not enough letters... You can read, can't you? We said %i letters..."), HiddenWord.Len()));
    }
    
}