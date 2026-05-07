# Hangman Game - Terminal Edition

A classic word-guessing game implemented in C++ that runs in the Ubuntu 24 terminal. Players guess letters to reveal a hidden word before running out of attempts.

## Features

- 📚 **Word list loading** from external text file
- 🎲 **Random word selection** for replayability
- 🔤 **Real-time word progress** display with underscores
- ❌ **Wrong guess tracking** with limited attempts (6 lives)
- 🚫 **Duplicate guess prevention**
- 🏆 **Win/loss detection** with word reveal
- 📝 **Case-insensitive** input handling

## Prerequisites

- **Ubuntu 24** (or any Linux distribution)
- **G++ compiler** (part of build-essential package)

## Installation

### 1. Create project directory

```bash
mkdir hangman
cd hangman
```

### 2. Create the words file

```bash
nano words.txt
```

Add words (one per line):
```
computer
programming
hangman
terminal
ubuntu
science
developer
keyboard
linux
algorithm
```

Save with `CTRL+O`, `Enter`, `CTRL+X`

### 3. Create the source file

```bash
nano main.cpp
```

Copy the complete C++ code from this repository into the file.

### 4. Install G++ (if not already installed)

```bash
sudo apt update
sudo apt install g++
```

### 5. Compile the game

```bash
g++ main.cpp -o hangman
```

### 6. Run the game

```bash
./hangman
```

## How to Play

1. The game randomly selects a secret word
2. The word is displayed as underscores: `_ _ _ _ _`
3. Guess one letter at a time by typing it and pressing Enter
4. **Correct guess** → Letter appears in all positions
5. **Wrong guess** → Lose one life (start with 6 lives)
6. **Duplicate guess** → No penalty, but try again
7. **Win** → Guess all letters before lives run out
8. **Lose** → Word is revealed at game over

## Game Flow Example

```
===== HANGMAN =====

Word: _ _ _ _ _ _ _ _ 
Guesses left: 6
Guessed letters: 

Enter a letter: a

Correct!

Word: _ a _ _ a _ _ _ 
Guesses left: 6
Guessed letters: a 

Enter a letter: z

Wrong!

Word: _ a _ _ a _ _ _ 
Guesses left: 5
Guessed letters: a z 

Enter a letter: p

Correct!

Word: _ a _ _ a _ _ _ 
Guesses left: 5
Guessed letters: a z p 
...
```

## Code Structure

| Function | Purpose |
|----------|---------|
| `loadWords()` | Reads words from text file into vector |
| `getRandomWord()` | Selects random word from loaded list |
| `displayWord()` | Shows current progress with underscores |
| `isWordGuessed()` | Checks if all letters have been guessed |
| `main()` | Controls game loop and user interaction |

### Key C++ Concepts Demonstrated

- **File I/O** (`ifstream`) - Reading external word lists
- **Vectors** - Dynamic storage for words and guessed letters
- **Strings** - Word manipulation and searching
- **Random number generation** (`rand()`, `srand()`)
- **STL algorithms** (`find()`) - Searching in containers
- **Loops** - Game logic and input validation
- **Conditional statements** - Win/loss checking

## Customization Guide

### Adding More Words

Edit `words.txt` and add one word per line:
```text
elephant
mountain
challenge
```

### Changing Number of Lives

In `main.cpp`, modify:
```cpp
int guessesLeft = 6;  // Change to desired number
```

### Case Sensitivity

The game automatically converts all input to lowercase. To change:
```cpp
guess = tolower(guess);  // Remove or modify this line
```

## Possible Enhancements

After mastering the basic version, try adding:

- 🎨 **ASCII Hangman drawing** - Visual hangman that builds with wrong guesses
- 📊 **Difficulty levels** - Easy (short words, more lives) / Hard (long words, fewer lives)
- 🎯 **Word categories** - Animals, countries, programming terms
- 💾 **Score tracking** - Persist wins/losses across sessions
- 🌈 **Colored output** - Green for correct, red for wrong
- 🔊 **Sound effects** - Beep on wrong guess (using terminal bell)
- 🔄 **Replay option** - Play multiple rounds without restarting
- 👥 **Multiplayer mode** - Players take turns guessing
- 📖 **Dictionary hints** - Show word definition after game

## Advanced Example: ASCII Hangman

Add this array to draw hangman stages:

```cpp
const string HANGMAN_STAGES[] = {
    "  +---+\n      |\n      |\n      |\n      |\n      |\n=========",
    "  +---+\n  O   |\n      |\n      |\n      |\n      |\n=========",
    "  +---+\n  O   |\n  |   |\n      |\n      |\n      |\n=========",
    // Add more stages...
};
```

Display based on `guessesLeft`:
```cpp
cout << HANGMAN_STAGES[6 - guessesLeft] << endl;
```

## Troubleshooting

| Issue | Solution |
|-------|----------|
| `g++: command not found` | Install build-essential: `sudo apt install g++` |
| `Error: Could not load words!` | Ensure `words.txt` exists in same directory as executable |
| Word file not found | Run from correct directory or use absolute path: `loadWords("/full/path/words.txt")` |
| Random words always same | Check `srand(time(0))` is called before `rand()` |
| Duplicate guesses not detected | Verify `find()` is checking `guessedLetters` vector |

## Building with Make (Optional)

Create a `Makefile`:

```makefile
CXX = g++
CXXFLAGS = -Wall -O2
TARGET = hangman
SOURCES = main.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
```

Then compile with:
```bash
make
```

Run with:
```bash
make run
```

## Learning Resources

- [C++ Reference](https://en.cppreference.com/) - Comprehensive C++ documentation
- [STL Algorithms](https://en.cppreference.com/w/cpp/algorithm) - Standard library algorithms
- [GCC Documentation](https://gcc.gnu.org/onlinedocs/) - Compiler options

## License

This project is open source for educational purposes.

---

## Project Ideas Progression

After completing Hangman, try these terminal games in order:

1. **Number Guessing Game** - Simple random number guessing
2. **Tic-Tac-Toe** - Two-player board game
3. **Hangman** (this project) - Word guessing
4. **Quiz Application** - Multiple choice questions
5. **Snake Game** - Real-time keyboard input
6. **Wordle Clone** - Daily word puzzle
7. **File-based Student Management System** - Data persistence

---

## Author

Created as a C++ learning project for Ubuntu 24 terminal environment.

**Happy Guessing! 🎯**
```

