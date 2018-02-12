// CIA Code Breaking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
	cout << "Initializing Codebreaker Program..." << endl << endl;
	int correct = 0;
	int numberOfGuesses = 0;
	bool finished = false;

	//initializes the words and hints in an array
	enum fields {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] = {
		{"accommodate", "I will do my best to help."},
		{"handkerchief", "Try not to blow it."},
		{"pharaoh", "Tut tut tut."},
		{"millennium", "Try not to take to long."},
		{"ecstasy", "You'll be happy when you figure it out."},
		{"playwright", "Will this be a tragedy or a comedy?"},
		{"conscience", "Try to think about what you're doing."},
		{"indict", "Are you in trouble?"},
		{"weird", "How strange."},
		{"czechoslovakia", "If you find yourself here, you've discovered time travel."}
	};

	//generates a random seed
	srand(static_cast<unsigned int>(time(0)));
	while (finished == false) {
		//chooses a random word
		int choice = (rand() % NUM_WORDS);
		string codeWord = WORDS[choice][WORD];
		string codeHint = WORDS[choice][HINT];

		//jumbles word
		string jumble = codeWord;
		int length = jumble.size();
		for (int i = 0; i < length; ++i)
		{
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}

		//welcomes player
		cout << "Decode the word to show your skills." << endl;
		cout << "Enter 'hint' to recieve a hint." << endl;
		cout << "Enter 'quit' to end the program." << endl;
		cout << "The jumble is: " << jumble << endl << endl;

		//takes player's guess
		string guess;
		cout << "Your Guess: ";
		cin >> guess;
		cout << endl;

		//interprets player guess
		while ((guess != codeWord) && (guess != "quit"))
		{
			if (guess == "hint")
			{
				cout << codeHint << endl << endl;
			}
			else
			{
				cout << "Incorrect." << endl << endl;
				numberOfGuesses++;
			}
			cout << "Your Guess: ";
			cin >> guess;
			cout << endl;
		}

		if (guess == codeWord)
		{
			cout << "Correct. ";
			correct++;
			numberOfGuesses++;
		}
		if (guess == "quit")
		{
			return 0;
		}

		if (correct != 3)
		{
			cout << "Moving on to next word." << endl << endl;
		}

		if (correct == 3)
		{
			cout << "All words have been unscrambled." << endl;
			cout << "It took you " << numberOfGuesses << " guesses to get all three words." << endl << endl;
			finished = true;
		}
	}

	system("pause");

    return 0;
}

