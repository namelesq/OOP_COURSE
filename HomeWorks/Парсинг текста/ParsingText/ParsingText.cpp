#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

struct WordCount
{
    char word[50];
    int count;
};

bool isDelimiter(char c)
{
    return c == ' ' || c == '\n' || c == '\t' || c == '.' || c == ',' ||
        c == '!' || c == '?' || c == '"' || c == '(' || c == ')' || c == ';';
}

bool compareWords(const char* w1, const char* w2)
{
    return strcmp(w1, w2) == 0;
}

void copyWord(char* dest, const char* src)
{
    int size = 0;
    for (int i = 0; i < 50; i++)
    {
        if (src[i] != ' ') { size++; }
    }
    strcpy_s(dest,size, src);
}

void saveTextToFile(const char* text, const char* filename)
{
    std::ofstream outFile(filename);
    outFile << text;
    outFile.close();
}

void processWord(const char* currentWord, std::vector<WordCount>& wordCounts)
{
    bool found = false;
    for (auto& wordCount : wordCounts)
    {
        if (compareWords(wordCount.word, currentWord))
        {
            wordCount.count++;
            found = true;
            break;
        }
    }
    if (!found)
    {
        WordCount newWord;
        copyWord(newWord.word, currentWord);
        newWord.count = 1;
        wordCounts.push_back(newWord);
    }
}

void handleWordWrapping(char* text)
{
    int length = strlen(text);
    for (int i = 0; i < length - 1; ++i)
    {
        if (text[i] == '-' && text[i + 1] == '\n')
        {
            std::memmove(&text[i], &text[i + 2], length - i - 1);
            text[length - 2] = '\0';  
            length -= 2;
            --i; 
        }
    }
}

void countWords(char* text, std::vector<WordCount>& wordCounts)
{
    char currentWord[50];
    int pos = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (!isDelimiter(text[i]))
        {
            currentWord[pos++] = text[i];
        }
        else if (pos > 0)
        {
            currentWord[pos] = '\0';
            pos = 0;
            processWord(currentWord, wordCounts);
        }
    }
    if (pos > 0)
    {
        currentWord[pos] = '\0';
        processWord(currentWord, wordCounts);
    }
}

void saveWordCountsToFile(const std::vector<WordCount>& wordCounts, const char* filename)
{
    std::ofstream statFile(filename);
    for (const auto& wordCount : wordCounts)
    {
        statFile << wordCount.word << ": " << wordCount.count << std::endl;
        std::cout << wordCount.word << ": " << wordCount.count << std::endl;
    }
    statFile.close();
}

int main()
{
    std::vector<WordCount> wordCounts;
    char text[1000];

    std::cout << "Enter text: ";
    std::cin.getline(text, 1000);

    handleWordWrapping(text);
    saveTextToFile(text, "input.txt");
    countWords(text, wordCounts);
    saveWordCountsToFile(wordCounts, "word_count.txt");

    return 0;
}