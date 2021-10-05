#include <iostream>
#include <string>
using namespace std;

char toLowerAlpha(char alpha);
void printAlphabetCounting(int alphabetArr[], const int ARR_LENGTH);

int main()
{
	string sentence;
	getline(cin, sentence);

	const int ALPHABET_CNT = 26;
	int alphabetCntArr[ALPHABET_CNT] = {0};

	for (int i = 0; i < sentence.size(); i++)
	{
		if (('a' <= sentence[i] && sentence[i] <= 'z') || ('A' <= sentence[i] && sentence[i] <= 'Z'))
		{
			char curAlphabet = toLowerAlpha(sentence[i]);
			alphabetCntArr[curAlphabet - 'a'] ++;
		}
		
	}

	printAlphabetCounting(alphabetCntArr, ALPHABET_CNT);
}

char toLowerAlpha(char alpha)
{
	int diff = 'a' - 'A';
	if ('A' <= alpha && alpha <= 'Z')
	{
		return alpha + diff;
	}
	return alpha;
}

void printAlphabetCounting(int alphabetArr[],const int ARR_LENGTH)
{
	for (int i = 0; i < ARR_LENGTH; i++)
	{
		if (alphabetArr[i]) 
		{
			cout << '[' << char(i + 'a') << ']' << ' ' << alphabetArr[i] << " ";
		}
		
	}
}