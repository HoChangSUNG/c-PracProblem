#include <iostream>
#include <string>
using namespace std;

string toCorrectSentence(string sentence);

int main()
{
	string sentence;
	getline(cin, sentence);
	cout << toCorrectSentence(sentence);
	return 0;
}

string toCorrectSentence(string sentence)
{
	int i = 0;
	for(;i<sentence.size();i++)
	{
		if (isalpha(sentence[i])) 
		{
			sentence[i] = toupper(sentence[i]);
			i++;
			break;
		}
	}

	for (; i < sentence.size(); i++)
	{
		if (isalpha(sentence[i]))
			sentence[i] = tolower(sentence[i]);
	}

	return sentence;
}