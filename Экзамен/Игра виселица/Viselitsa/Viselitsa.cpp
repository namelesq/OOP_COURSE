#include <iostream>
#include <vector>
#include <fstream>
void InputWordsToVector(std::vector<std::string>& words)
{
	std::ifstream file("words.txt");
	std::string word;
	while (file >> word) { words.push_back(word); }
}

std::string Choise_A_SecretWord(std::vector<std::string>& words)
{
	srand(time(NULL));
	int index_word = rand() % words.size();
	return words[index_word];
}

std::string FillingWordOfStars(std::string word)
{
	std::string secret_word(word.size(), '*');
	return secret_word;
}

void TheGameProcess(std::vector<std::string>& words)
{
	std::string word = Choise_A_SecretWord(words);
	std::string secretWord = FillingWordOfStars(word);
	std::cout << secretWord;

}

int main()
{
	const int TimeDivider = 1000;	
	std::vector<std::string> words;
	InputWordsToVector(words);
	Choise_A_SecretWord(words);
	return 0;
}