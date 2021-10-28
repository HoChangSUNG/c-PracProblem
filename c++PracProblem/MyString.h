#pragma once
#include <iostream>
using namespace std;
class MyString
{
public:
	MyString();
	MyString(const char *srcStr);
	MyString(const MyString& srcStr);
	~MyString();

	const MyString& operator =(const MyString &srcStr);
	const MyString& operator =(const char *srcStr);
	const MyString operator +(const MyString& str2nd)const;
	const MyString operator +(const char *str2nd)const;
	const MyString& append(const char *str2nd);
	const MyString& append(const MyString& str2nd);
	bool operator ==(const MyString &str)const; 
	bool operator !=(const MyString &str)const; 
	const MyString& operator +=(const char* str2nd);

	int find(const char *subStr)const;
	int find(const MyString subStr)const;
	int find(int pos, const char *subStr)const;
	int find(int pos, const MyString subStr)const;

	int length()const; 
	char at(int pos)const;
	bool empty()const;

	friend istream& operator >>(istream& is, MyString &str);
	friend ostream& operator <<(ostream& os, const MyString &str);
	

	bool operator <(const MyString &str)const;
	bool operator >(const MyString &str)const;
	bool operator <=(const MyString &str)const;
	bool operator >=(const MyString &str)const;

	bool operator <(const char* str)const;
	bool operator >(const char* str)const;
	bool operator <=(const char* str)const;
	bool operator >=(const char* str)const;

	const MyString substr(int pos, int cnt)const; 
	const MyString& insert(int pos, const MyString& subStr); 
	const MyString& insert(int pos, const char *subStr);

	const MyString& replace(int pos, int cnt,const MyString &subStr);
	const MyString& replace(int pos, int cnt,const char *subStr);

	const MyString& erase(int pos, int cnt);

	char& operator [](int pos);
	friend int stoi(const MyString &srcStr, int pos=0 , int base=10);

private:
	int size;
	int capacity;
	char *charArr=NULL;
	static const int INIT_CAPACITY = 8;
	void resize(int newCapacity);
	int getNewArrCapacity(int newSize)const;
	int getNewArrSize(const char* srcStr)const;
	void copyCharArr(int newSize,int newCapacity, const char* srcStr);
	const MyString plus(int str2ndSize, const char* str2nd)const;
	void appendMyString(int str2ndSize, const char* str2ndCharArr);
	bool isEqual(const MyString& str)const;
	bool greaterThan(int strSize, const char* srcStr)const;
	bool lessThan(int strSize, const char* srcStr)const;
	int findPos(int pos, int subStrSize, const char* subStr)const;
	void insertStr(int pos,int subStrSize, const char* subStr);
	void replaceStr(int pos, int cnt, int subStrSize, const char* subStr);
	void addChar(char c);
};