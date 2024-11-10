#include <iostream>
#include <fstream>
#include <vector>

struct WordCount
{
    char word[50];
    int count;
};

bool isDelimiter(char c)
{
    return c == ' '|| c == '\n' || c == '\t' || c == '.' || c == ',' ||
        c == '!' || c == '?' || c == '"' || c == '(' || c == ')' || c == ';';
}

bool compareWords(const char* w1, const char* w2)
{
    int i = 0;
    while (w1[i] != '\0' && w2[i] != '\0')
    {
        if (w1[i] != w2[i])
            return false;
        i++;
    }
    return w1[i] == '\0' && w2[i] == '\0';
}

void copyWord(char* dest, const char* src)
{
    int i = 0;
    while (src[i] != '\0' && i < 50 - 1) 
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void saveTextToFile(const char* text, const char* filename)
{
    std::ofstream outFile(filename);
    int i = 0;
    while (text[i] != '\0')
    {
        outFile.put(text[i]);
        i++;
    }
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

int customStrlen(const char* str)
{
    int length = 0;
    while (str[length] != '\0')
        length++;
    return length;
}

void customMemmove(char* dest, const char* src, int n)
{
    if (dest < src)
    {
        for (int i = 0; i < n; i++)
            dest[i] = src[i];
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
            dest[i] = src[i];
    }
}

void handleWordWrapping(char* text)
{
    int length = customStrlen(text);
    for (int i = 0; i < length - 1; ++i)
    {
        if (text[i] == '-' && text[i + 1] == '\n')
        {
            customMemmove(&text[i], &text[i + 2], length - i - 1);
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
        int i = 0;
        while (wordCount.word[i] != '\0')
        {
            statFile.put(wordCount.word[i]);
            std::cout.put(wordCount.word[i]);
            i++;
        }
        statFile << ": " << wordCount.count << std::endl;
        std::cout << ": " << wordCount.count << std::endl;
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