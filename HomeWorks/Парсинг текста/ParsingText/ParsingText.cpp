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
    return c == ' ' || c == '\n' || c == '\t' || c == '.' || c == ',' || c == '!' || c == '?'
        || c=='"'||c=='('||c==')'||c==';';
}

bool compareWords(const char* w1, const char* w2)
{
    int i = 0;

    while (w1[i] != '\0' && w2[i] != '\0') 
    {
        if (w1[i] != w2[i]) { return false; }
        i++;
    }
    return w1[i] == '\0' && w2[i] == '\0';
}

void copyWord(char* dest, const char* src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main() 
{
    std::vector<WordCount> wordCounts;

    std::cout << "Enter text: ";
    char text[1000];
    std::cin.getline(text, 1000);

    std::ofstream outFile("input.txt");
    outFile << text;
    outFile.close();
   
    char currentWord[50];
    int pos = 0;
    for (int i = 0; text[i] != '\0'; i++) 
    {
        if (!isDelimiter(text[i])) { currentWord[pos++] = text[i];}
        else if (pos > 0) 
        {
            currentWord[pos] = '\0';
            pos = 0;
            bool found = false;
            for (int j = 0; j < wordCounts.size(); j++) 
            {
                if (compareWords(wordCounts[j].word, currentWord)) 
                {
                    wordCounts[j].count++;
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
    }
  
    if (pos > 0)
    {
        currentWord[pos] = '\0';
        bool found = false;
        for (int j = 0; j < wordCounts.size(); j++) 
        {
            if (compareWords(wordCounts[j].word, currentWord)) 
            {
                wordCounts[j].count++;
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

    std::ofstream statFile("word_count.txt");
    for (int i = 0; i < wordCounts.size(); i++) 
    {
        statFile << wordCounts[i].word << ": " << wordCounts[i].count << std::endl;
        std::cout << wordCounts[i].word << ": " << wordCounts[i].count << std::endl;
    }
    statFile.close();
    
    return 0;
}