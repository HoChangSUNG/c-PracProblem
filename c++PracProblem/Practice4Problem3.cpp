#include <iostream>
#include <string>

using namespace std;
string getEncryptionString(string sentence);

int main()
{
	string sentence;
	getline(cin, sentence);
	cout << getEncryptionString(sentence);

	return 0;
}

string getEncryptionString(string sentence)
{
	const int ENCRYPTION_NUMBER = 3;
	const int ALPHABET_CNT = 26;

	for (int i = 0; i < sentence.size(); i++)
	{
		if (isalpha(sentence[i])) 
		{
			if ('a' <= sentence[i] && sentence[i] <= 'z')
			{
				sentence[i] = (sentence[i] + ENCRYPTION_NUMBER - 'a') % ALPHABET_CNT + 'a';
			}
			else
			{
				sentence[i] = (sentence[i] + ENCRYPTION_NUMBER - 'A') % ALPHABET_CNT + 'A';
			}
		}
	}
	return sentence;
}
