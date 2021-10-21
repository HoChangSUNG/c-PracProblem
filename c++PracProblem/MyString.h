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

	MyString& operator =(const MyString &srcStr);
	MyString& operator =(const char *srcStr);
	const MyString operator +(const MyString& str2nd);
	const MyString operator +(const char *str2nd);
	const MyString& append(const char *str2nd);
	const MyString& append(const MyString& str2nd);
	bool operator ==(const MyString &str); //const �ٿ��� �Ǵ°� �ƴѰ�?
	bool operator !=(const MyString &str); //const �ٿ��� �Ǵ°� �ƴѰ�?
	int find(const char *subStr);
	int find(const MyString subStr);
	int find(int pos, const char *subStr);
	int find(int pos, const MyString subStr);

	int length()const; 
	char at(int pos)const;
	bool empty()const;

	friend istream& operator >>(istream& is, MyString &str);
	friend ostream& operator <<(ostream& os, const MyString &str);
	
	const MyString& operator +=(const char *str2nd);

	bool operator <(const MyString &str)const;
	bool operator >(const MyString &str)const;
	bool operator <=(const MyString &str)const;
	bool operator >=(const MyString &str)const;

	bool operator <(const char* str)const;
	bool operator >(const char* str)const;
	bool operator <=(const char* str)const;
	bool operator >=(const char* str)const;

	const MyString substr(int pos, int cnt)const; //�տ� const �³�?
	const MyString& insert(int pos, const MyString& subStr); //this�Ѱ��ִ°� �³�?
	const MyString& insert(int pos, const char *subStr);

	const MyString& replace(int pos, int cnt,const MyString &subStr);
	const MyString& replace(int pos, int cnt,const char *subStr);

	const MyString& erase(int pos, int cnt);
private:
	int size;
	int capacity;
	char *charArr=NULL;
	void resize(int newCapacity);
	void initialization();
	void addChar(char newChar);
	void copyCharArr(const MyString& srcStr);
};