#include <iostream>
#include <string>
#include <stack>

enum Brackets
{
	START_CIRCLE = '(',
	END_CIRCLE = ')',
	START_SQUARE = '[',
	END_SQUARE = ']',
	START_CURLY = '{',
	END_CURLY = '}',
	END_STRING = ';'
};

bool IsCheckElem(char startElem, char endElem)
{
	return(startElem == '(' && endElem == ')') ||
		(startElem == '[' && endElem == ']') ||
		(startElem == '{' && endElem == '}');
}

void CheckBrackets(const std::string& str)
{
	std::stack<char> BracketsStack;
	std::string Message;
	for (size_t i{ 0 }; i < str.length(); i++)
	{
		char meaning = str[i];
		if (meaning == START_CIRCLE || meaning == START_SQUARE || meaning == START_CURLY)
		{
			BracketsStack.push(meaning);
		}
		else if (meaning == END_CIRCLE || meaning == END_SQUARE || meaning == END_CURLY)
		{										
			if (BracketsStack.empty() || !IsCheckElem(BracketsStack.top(), meaning))
			{
				Message = str.substr(0, i + 1);
				break;
			}
			BracketsStack.pop();
		}
		else if (meaning == END_STRING) { break; }
	}
	if (!BracketsStack.empty()) { Message = str; }
	if (Message.empty()) { std::cout << "String is correct"; }
	else { std::cout << "String is not correct"; }
}


int main()
{
	std::string expression;
	std::cout << "Enter expression(end is ;): ";
	std::cin >> expression;
	CheckBrackets(expression);
	return 0;
}
