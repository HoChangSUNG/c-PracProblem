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
	bool isFirstAlpha = true;
	int diff = 'a' - 'A';

	for (int i = 0; i < sentence.size(); i++) {
		if (('a' <= sentence[i] && sentence[i] <= 'z') || ('A' <= sentence[i] && sentence[i] <= 'Z')) 
		{
			if (isFirstAlpha)
			{
				sentence[i] = toupper(sentence[i]);
				isFirstAlpha = false;
			}
			else 
			{
				sentence[i] = tolower(sentence[i]);
			}
		}
	}
	return sentence;
}