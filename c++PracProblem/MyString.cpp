#include "MyString.h"
#include <iostream>

using namespace std;

MyString::MyString()
{
	charArr = new char[INIT_CAPACITY];
	size = 0;
	capacity = INIT_CAPACITY;
	charArr[0] = '\0';
}

MyString::MyString(const char *srcStr)
{
	int newSize = getNewArrSize(srcStr);
	capacity = getNewArrCapacity(newSize);
	charArr = new char[capacity];
	copyCharArr(newSize, srcStr);
}

MyString::MyString(const MyString &srcStr)
{
	capacity = srcStr.capacity;
	charArr = new char[capacity];
	copyCharArr(srcStr.size, srcStr.charArr);

}

int MyString::getNewArrCapacity(int newSize)const
{
	return (newSize / INIT_CAPACITY + 1) * INIT_CAPACITY;
}

int MyString::getNewArrSize(const char* srcStr)const
{
	int strLen;
	for (strLen = 0; srcStr[strLen] != '\0'; strLen++);
	return strLen;
}

void MyString::copyCharArr(int newSize, const char* srcStr)
{
	size = newSize;
	for (int i = 0; i < size; i++)
		charArr[i] = srcStr[i];
	charArr[size] = '\0';
}

void MyString::resize(int newCapacity)
{
	char *tempStr = new char[newCapacity];
	for (int i = 0; i < size; i++)
	{
		tempStr[i] = charArr[i];
	}
	tempStr[size] = '\0';

	delete[] charArr;
	charArr = tempStr;
	capacity = newCapacity;
}

MyString::~MyString()
{
	delete[] charArr;
}

const MyString& MyString::operator =(const MyString &srcStr)
{
	if (this == &srcStr)
		return *this;

	delete[] charArr;
	capacity = srcStr.capacity;
	charArr = new char[capacity];
	copyCharArr(srcStr.size, srcStr.charArr);
	return *this;
}

const MyString& MyString::operator =(const char *srcStr)
{
	delete[] charArr;
	int newSize = getNewArrSize(srcStr);
	capacity = getNewArrCapacity(newSize);
	charArr = new char[capacity];
	copyCharArr(newSize, srcStr);
	return 	*this;
}

const MyString MyString::plus(int str2ndSize, const char *str2nd)const
{
	char* tempArr = new char[getNewArrCapacity(size + str2ndSize)];
	for (int i = 0; i < size; i++)
	{
		tempArr[i] = charArr[i];
	}
	for (int j = 0; j < str2ndSize; j++)
	{
		tempArr[size + j] = str2nd[j];
	}
	tempArr[size + str2ndSize] = '\0';

	MyString temp(tempArr);
	delete[] tempArr;
	return temp;
}

const MyString MyString::operator +(const MyString& str2nd)const
{
	return plus(str2nd.size, str2nd.charArr);
}

const MyString MyString::operator +(const char *str2nd)const
{
	int str2ndSize = getNewArrSize(str2nd);
	return plus(str2ndSize, str2nd);
}

const MyString& MyString::append(const MyString& str2nd)
{
	appendMyString(str2nd.size, str2nd.charArr);
	return *this;
}

const MyString& MyString::append(const char* str2nd)
{
	appendMyString(getNewArrSize(str2nd), str2nd);
	return *this;
	
}

void MyString::appendMyString(int str2ndSize, const char* str2ndCharArr)
{
	int newSize = size + str2ndSize;
	if(getNewArrCapacity(newSize)>capacity)
	{
		resize(getNewArrCapacity(newSize));
	}

	for (int i = 0; i < str2ndSize; i++)
		charArr[size + i] = str2ndCharArr[i];
	charArr[newSize] = '\0';
	size = newSize;

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

bool MyString::empty()const
{
	return size == 0;
}

bool MyString::isEqual(const MyString& str)const
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
	else
		return false;
}

bool MyString::operator ==(const MyString& str)const
{
	return isEqual(str);
}

bool MyString::operator !=(const MyString& str)const
{
	return !isEqual(str);
}

const MyString& MyString::operator +=(const char* str2nd)
{
	appendMyString(getNewArrSize(str2nd), str2nd);
	return *this;
}

bool MyString::greaterThan(int strSize, const char* srcStr)const
{
	int i = 0;

	for (; i < size && i < strSize; i++)
	{
		if (charArr[i] > srcStr[i])
			return true;
		else if (charArr[i] < srcStr[i])
			return false;
	}

	if (size > strSize)
		return true;

	return false;
}

bool MyString::lessThan(int strSize, const char* srcStr)const
{
	int i = 0;

	for (; i < size && i < strSize; i++) 
	{
		if (charArr[i] < srcStr[i])
			return true;
		else if (charArr[i] > srcStr[i])
			return false;
	}

	if (size < strSize)
		return true;

	return false;
}

bool MyString::operator <(const MyString& str)const
{
	return lessThan(str.size, charArr);
}

bool MyString::operator >(const MyString& str)const
{
	return greaterThan(str.size, charArr);

}

bool MyString::operator <=(const MyString& str)const
{
	return !greaterThan(str.size, charArr);

}

bool MyString::operator >=(const MyString& str)const
{
	return !lessThan(str.size, charArr);
}

bool MyString::operator <(const char* str)const
{
	return lessThan(getNewArrSize(str), str);
}

bool MyString::operator >(const char* str)const
{
	return greaterThan(getNewArrSize(str), str);

}

bool MyString::operator <=(const char* str)const
{
	return !greaterThan(getNewArrSize(str), str);
}

bool MyString::operator >=(const char* str)const
{
	return !lessThan(getNewArrSize(str), str);
}

int MyString::findPos(int pos, int subStrSize, const char* subStr)const
{
	for (int i= pos; i <= size - subStrSize; i++)
	{
		int j;
		for (j = 0; j < subStrSize; j++)
		{
			if (charArr[i + j] != subStr[j])
				break;
		}
		if (j == subStrSize)
			return i;
	}
	return -1;
}

int MyString::find(const char* subStr)const
{
	return findPos(0,getNewArrSize(subStr),subStr);
}

int MyString::find(const MyString subStr)const
{
	return findPos(0, subStr.size, subStr.charArr);
}

int MyString::find(int pos, const char* subStr)const
{
	return findPos(pos, getNewArrSize(subStr), subStr);
}

int MyString::find(int pos, const MyString subStr)const
{
	return findPos(pos, subStr.size, subStr.charArr);

}

const MyString MyString::substr(int pos, int cnt)const
{
	
	char* tempChar;
	int idx = 0;
	if (pos + cnt - 1 < size)
		tempChar = new char[cnt+1];
	else
		tempChar = new char[size-pos+1];

	for (int i = pos; (i < size) && (i < pos+cnt) ; i++)
	{
		tempChar[idx++] = charArr[i];

	}
	tempChar[idx] = '\0';

	MyString tempStr(tempChar);
	delete[] tempChar;

	return tempStr;
}

const MyString& MyString::erase(int pos, int cnt)
{
	if (pos < 0 || pos >= size|| cnt == 0)
		return *this;

	int idx;
	for (idx = pos; (idx + cnt) < size; idx++)
	{
		charArr[idx] = charArr[idx+cnt];
	}
	charArr[idx] = '\0';
	size = idx;
	
	int newCapacity = getNewArrCapacity(size);
	if (newCapacity < capacity)
		resize(newCapacity); 
	return *this;
}

void MyString::insertStr(int pos, int subStrSize, const char* subStr)
{
	if (pos < 0 || pos > size || subStrSize == 0)
	{
		return;
	}
		
	int newSize = size + subStrSize;
	int newCapacity = getNewArrCapacity(newSize);
	if (capacity < newCapacity)
		resize(newCapacity);

	for (int i = size - 1; i >= pos; i--)
		charArr[i + subStrSize] = charArr[i];
	for (int i = 0; i < subStrSize; i++)
		charArr[pos + i] = subStr[i];
	size = newSize;
	charArr[size] = '\0';

}

const MyString& MyString::insert(int pos, const MyString& subStr)
{
	insertStr(pos, subStr.size, subStr.charArr);

	return *this;
}

const MyString& MyString::insert(int pos, const char* subStr)
{
	insertStr(pos, getNewArrSize(subStr), subStr);

	return *this;
}

int stoi(const MyString& srcStr, int pos , int base)
{
	int result = 0, curNum = 0;
	bool isNegative = false;
	if (srcStr.charArr[pos] == '-'|| srcStr.charArr[pos] == '+')
	{
		if (srcStr.charArr[pos] == '-')
			isNegative = true;
		pos++;
	}
		
	for(int i=pos; i< srcStr.size; i++)
	{
		if ('0'<= srcStr.charArr[i] && srcStr.charArr[i]<'0'+base && srcStr.charArr[i] <= '9')
		{
			curNum = srcStr.charArr[i] - '0';
		}
		else if(base>10&& ('A' <= toupper(srcStr.charArr[i])) && (toupper(srcStr.charArr[i]) < ('A' + (base % 10))))
		{
			curNum = 10 + (toupper(srcStr.charArr[i]) - 'A');
		}
		else
		{
			break;
		}
		result = base * result + curNum;
	}
	
	if (isNegative)
		return -result;
	return result;
}

char& MyString::operator [](int pos)
{
	return charArr[pos];
}

void MyString::replaceStr(int pos, int cnt, int subStrSize, const char* subStr)
{
	erase(pos, cnt);
	insertStr(pos, getNewArrSize(subStr), subStr);
}
	
const MyString& MyString::replace(int pos, int cnt, const MyString& subStr)
{
	replaceStr(pos, cnt, subStr.size, subStr.charArr);
	return *this;
}

const MyString& MyString::replace(int pos, int cnt, const char* subStr)
{
	replaceStr(pos, cnt, getNewArrSize(subStr), subStr);
	return *this;
}

void MyString::addChar(char c)
{
	int newCapacity = getNewArrCapacity(size + 1);
	if (newCapacity > capacity)
		resize(newCapacity);
	charArr[size++] = c;
	charArr[size] = '\0';

}

ostream& operator <<(ostream& os, const MyString &str)
{
	os << str.charArr<<"????"<<str.size<<"capacity"<<str.capacity;
	return os;
}

istream& operator >>(istream& is, MyString &str)
{
	if (str.size != 0)
	{
		str.size = 0; 
		str.resize(str.getNewArrCapacity(str.size));
	}

	char inputChar;
	for (int idx = 0; (inputChar = is.get()) != '\n'; idx++)
	{
		str.addChar(inputChar);
	}

	return is;
}


