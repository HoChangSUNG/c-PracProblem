#pragma once
#include <iostream>
using namespace std;

class Set
{
public:
	Set();
	Set(int* newItemArray, int newSize, int newCapacity);
	~Set();
	Set operator |(const Set& set)const;
	Set operator &(const Set& set)const;
	void add(int newItem);
	friend ostream& operator <<(ostream& outputStream,const Set& set);
	friend istream& operator >>(istream& inputStream,Set& set);
	void print();//test¿ë
private:
	int size, capacity, *itemArray;
	bool isOverlap(int newItem) const;
	void resize(int newCapacity);
};