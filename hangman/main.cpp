#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Load words from file
vector<string> loadWords(const string& filename)
{
    vector<string> words;
    ifstream file(filename);

    string word;

    while (file >> word)
    {
        words.push_back(word);
    }

    return words;
}

// Choose random word
string getRandomWord(const vector<string>& words)
{
    int index = rand() % words.size();
    return words[index];
}

// Display current progress
void displayWord(const string& word, const vector<char>& guessedLetters)
{
    for (char c : word)
    {
        if (find(guessedLetters.begin(), guessedLetters.end(), c) != guessedLetters.end())
        {
            cout << c << " ";
        }
        else
        {
            cout << "_ ";
        }
    }

    cout << endl;
}

// Check if word is fully guessed
bool isWordGuessed(const string& word, const vector<char>& guessedLetters)
{
    for (char c : word)
    {
        if (find(guessedLetters.begin(), guessedLetters.end(), c) == guessedLetters.end())
        {
            return false;
        }
    }

    return true;
}

int main()
{
    srand(time(0));

    // Load words
    vector<string> words = loadWords("words.txt");

    if (words.empty())
    {
        cout << "Error: Could not load words!" << endl;
        return 1;
    }

    string secretWord = getRandomWord(words);

    vector<char> guessedLetters;

    int guessesLeft = 6;

    cout << "===== HANGMAN =====" << endl;

    while (guessesLeft > 0)
    {
        cout << "\nWord: ";
        displayWord(secretWord, guessedLetters);

        cout << "Guesses left: " << guessesLeft << endl;

        cout << "Guessed letters: ";
        for (char c : guessedLetters)
        {
            cout << c << " ";
        }
        cout << endl;

        char guess;
        cout << "Enter a letter: ";
        cin >> guess;

        // Convert to lowercase
        guess = tolower(guess);

        // Check duplicate guess
        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end())
        {
            cout << "You already guessed that letter!" << endl;
            continue;
        }

        guessedLetters.push_back(guess);

        // Check if guess is in word
        if (secretWord.find(guess) != string::npos)
        {
            cout << "Correct!" << endl;
        }
        else
        {
            cout << "Wrong!" << endl;
            guessesLeft--;
        }

        // Check win
        if (isWordGuessed(secretWord, guessedLetters))
        {
            cout << "\nYou won!" << endl;
            cout << "The word was: " << secretWord << endl;
            return 0;
        }
    }

    cout << "\nGame Over!" << endl;
    cout << "The word was: " << secretWord << endl;

    return 0;
}
