#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <time.h>

void InputWordsToVector(std::vector<std::string>& words)
{
    std::ifstream file("words.txt");
    std::string word;
    while (file >> word) { words.push_back(word); }
}

std::string ChoiseWord(std::vector<std::string>& words)
{
    srand(time(NULL));
    int index_word = rand() % words.size();
    return words[index_word];
}

std::string FillingSecretWord(std::string word)
{
    std::string secret_word(word.size(), '*');
    return secret_word;
}

char SearchLetterInWord(char letter, std::string word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == letter)
        {
            return letter;
        }
    }
    return ' ';
}

std::string GetLetterForPrintSecretWord(std::string word, std::string secretword, char letter)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == letter) { secretword[i] = letter; }
    }
    return secretword;
}

void DisplayHangman(int attempts)
{
    const std::vector<std::string> hangman = {
        "   +---+\n       |\n       |\n       |\n      ===",
        "   +---+\n   O   |\n       |\n       |\n      ===",
        "   +---+\n   O   |\n   |   |\n       |\n      ===",
        "   +---+\n   O   |\n  /|   |\n       |\n      ===",
        "   +---+\n   O   |\n  /|\\  |\n       |\n      ===",
        "   +---+\n   O   |\n  /|\\  |\n  /    |\n      ===",
        "   +---+\n   O   |\n  /|\\  |\n  / \\  |\n      ==="
    };

    if (attempts < hangman.size())
    {
        std::cout << hangman[attempts] << std::endl;
    }
}

void TheGameProcess(std::vector<std::string>& words)
{
    const int maxAttempts = 6; 
    std::string word = ChoiseWord(words);
    std::string secretWord = FillingSecretWord(word);
    int attempts = 0;

    while (attempts <= maxAttempts)
    {
        char letter;
        std::cout << "Enter a letter to search for it in the hidden word: ";
        std::cin >> letter;
        std::cout << std::endl;

        char letterInWord = SearchLetterInWord(letter, word);
        if (letter == letterInWord)
        {
            secretWord = GetLetterForPrintSecretWord(word, secretWord, letter);
            std::cout << "You guessed the letter, your word: " << secretWord << std::endl;
        }
        else
        {
            attempts++;
            std::cout << "You didn't guess the letter. Attempts left: " << maxAttempts - attempts << std::endl;
            DisplayHangman(attempts);
        }

        if (word == secretWord)
        {
            std::cout << "You have won!" << std::endl;
            std::cout << "Your attempts: " << attempts << std::endl;
            break;
        }
        else if (attempts == maxAttempts)
        {
            std::cout << "You have lost." << std::endl;
            std::cout << "The word was: " << word << std::endl;
            DisplayHangman(attempts);
            break;
        }
    }
}
int main()
{
    std::cout << "-------------------------The Gallows Game-------------------------" << std::endl;
    const int TimeDivider = 1000;
    std::vector<std::string> words;
    InputWordsToVector(words);

    int start = clock();
    TheGameProcess(words);
    int end = clock();

    double seconds = double(end - start) / TimeDivider;
    std::cout << "Game time: " << seconds << " seconds" << std::endl;
    return 0;
}