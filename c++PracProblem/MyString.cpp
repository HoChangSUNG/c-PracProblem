#include "MyString.h";
#include <iostream>;

using namespace std;

MyString::MyString()
{
	initialization();
}

void MyString::initialization()
{
	if (charArr != NULL)
		delete charArr;

	const int INIT_CAPACITY = 8;
	size = 0;
	capacity = INIT_CAPACITY;
	charArr = new char[capacity];
}

MyString::MyString(const char *srcStr)
{
	initialization();
	int idx = 0;
	while (srcStr[idx] != '\0')
	{
		addChar(srcStr[idx++]);
	}
}

MyString::MyString(const MyString& srcStr)
{
	initialization();
	copyCharArr(srcStr);

}

void MyString::addChar(char newChar)
{
	if (size == capacity)
		resize(2 * capacity);
	charArr[size++] = newChar;
}


void MyString::resize(int newCapacity)
{
	char *tempStr = new char[newCapacity];
	for (int i = 0; i < size; i++)
	{
		tempStr[i] = charArr[i];
	}
	delete[] charArr;
	charArr = tempStr;
	capacity = newCapacity;
}

void MyString::copyCharArr(const MyString& srcStr)
{
	capacity = srcStr.capacity;
	size = srcStr.size;
	delete[] charArr;
	charArr = new char[capacity];
	for (int i = 0; i < size; i++)
		charArr[i] = srcStr.charArr[i];
}

MyString& MyString::operator =(const MyString &srcStr)
{
	if (this == &srcStr)
		return *this;

	copyCharArr(srcStr);
	return *this;
}

MyString& MyString::operator =(const char *srcStr)
{
	MyString tempMyString = srcStr;
	operator =(tempMyString);
	return 	*this;
}

const MyString MyString::operator +(const MyString& str2nd)
{
	MyString newString(*this);// 복사생성자
	
	for (int i = 0; i < str2nd.size; i++)
		newString.addChar(str2nd.charArr[i]);
	return MyString(newString);
}

const MyString MyString::operator +(const char *str2nd)
{
	return operator +(MyString(str2nd));
}

const MyString& MyString::append(const MyString& str2nd)
{
	MyString temp = operator +(str2nd);
	copyCharArr(temp);
	return *this;
}

const MyString& MyString::append(const char* str2nd)
{
	return append(MyString(str2nd));
}

MyString::~MyString()
{
	delete[] charArr;
}

int MyString::length()const
{
	return size;
}

char MyString::at(int pos)const
{
	if (-1 < pos&& pos < size)
	{
		return charArr[pos];
	}

	return '\0';
}
bool  MyString::empty()const
{
	return size == 0;
}

bool MyString::operator ==(const MyString& str)
{
	if (size == str.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (charArr[i] != str.charArr[i])
				return false;
		}
		return true;
	}
	return false;
}

int MyString::find(const char* subStr)
{
	return find(0,subStr);
}

int MyString::find(const MyString subStr)
{
	return find(0, subStr);
}

int MyString::find(int pos, const char* subStr)
{
	return find(pos, MyString(subStr));
}

int MyString::find(int pos, const MyString subStr)
{
	int resultPos = -1;
	int subStrIdx = 0;
	if (pos < 0)
		return resultPos;

	for (int i = pos; i < size; i++)
	{
		if (charArr[i] == subStr.charArr[subStrIdx])
			subStrIdx++;
		else
		{
			subStrIdx = 0;
			if (charArr[i] == subStr.charArr[subStrIdx])
				subStrIdx++;
		}

		if (subStrIdx == subStr.size)
		{
			resultPos = i - subStr.size + 1;
			break;
		}
	}
	return resultPos;
}

bool MyString::operator !=(const MyString& str)
{
	return !operator==(str);
}

const MyString& MyString::operator +=(const char* str2nd)
{
	copyCharArr(operator +(str2nd));
	return *this;
}

bool MyString::operator <(const MyString &str)const
{
	int i = 0;
	while (i < size && i < str.size)
	{
		if (charArr[i] < str.charArr[i])
			return true;
		else if (charArr[i] > str.charArr[i])
			return false;
		else
			i++;
	}
	if (size < str.size)
		return true;

	return false;

}

bool MyString::operator >(const MyString& str)const
{
	int i = 0;
	while (i < size && i < str.size)
	{
		if (charArr[i] > str.charArr[i])
			return true;
		else if (charArr[i] < str.charArr[i])
			return false;
		else
			i++;
	}
	if (size > str.size)
		return true;

	return false;
}

bool MyString::operator <=(const MyString& str)const
{
	return !operator >(str);
}

bool MyString::operator >=(const MyString& str)const
{
	return !operator <(str);
}

bool MyString::operator <(const char* str)const
{
	return operator <(MyString(str));
}

bool MyString::operator >(const char* str)const
{
	return operator >(MyString(str));
}

bool MyString::operator <=(const char* str)const
{
	return operator <=(MyString(str));
}

bool MyString::operator >=(const char* str)const
{
	return operator >=(MyString(str));
}

const MyString MyString::substr(int pos, int cnt)const
{

	MyString tempStr;
	for (int i = pos; (i < size) && (i < pos+cnt) ; i++)
	{
		tempStr.addChar(charArr[i]);
	}
	return MyString(tempStr);
}

const MyString& MyString::insert(int pos, const MyString& subStr) // -1넣었을때 어케 되나 확인해보기
{
	MyString tempStr;
	for (int i = 0; i < pos; i++)
		tempStr.addChar(charArr[i]);
	for (int i = 0; i < subStr.size; i++)
		tempStr.addChar(subStr.charArr[i]);
	for(int i = pos; i < size; i++)
		tempStr.addChar(charArr[i]);
	copyCharArr(tempStr);
	return *this; //리턴 타입이 this인지 새로운 객체인지 생각해보기
} 

const MyString& MyString::insert(int pos, const char* subStr)
{
	return insert(pos,MyString(subStr));
}

const MyString& MyString::replace(int pos, int cnt, const MyString& subStr)
{
	MyString tempStr;
	for (int i = 0; i < pos; i++)
		tempStr.addChar(charArr[i]);
	tempStr.append(subStr);

	for(int i=pos+cnt;i<size;i++)
		tempStr.addChar(charArr[i]);
	copyCharArr(tempStr);
	return *this;
}

const MyString& MyString::replace(int pos, int cnt, const char* subStr)
{
	return replace(pos, cnt, MyString(subStr));
}

const MyString& MyString::erase(int pos, int cnt)
{
	return replace(pos, cnt, "");
}

ostream& operator <<(ostream& os, const MyString &str)//테스트 종료 후 변경하기
{
	for (int i = 0; i < str.size; i++)
		cout << str.charArr[i];
	cout << " size:" << str.size << " capacity:" << str.capacity << "객체주소"<<&str<< endl; //테스트 휴 지우기
	
	return os;
}

istream& operator >>(istream& is, MyString &str)
{
	str.initialization();

	while (1)
	{
		char newChar = getchar();

		if (newChar == '\n')
			break;

		if (str.size == str.capacity)
			str.resize(2 * str.capacity);
		str.charArr[str.size++] = newChar;
	}

	return is;
}


