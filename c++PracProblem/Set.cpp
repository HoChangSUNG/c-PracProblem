#include <iostream>
#include "Set.h"
using namespace std;

Set::Set() 
{
	const int INIT_CAPACITY = 4;
	itemArray = new int[INIT_CAPACITY];
	size = 0; capacity = INIT_CAPACITY;
}

Set::Set(int* newItemArray, int newSize, int newCapacity):itemArray(newItemArray),size(newSize),capacity(newCapacity)
{
}

Set::~Set()
{
	if (itemArray!=NULL)
		delete[] itemArray;
}
void Set::add(int newItem) 
{
	if (!isOverlap(newItem))
	{
		if (size == capacity)
			resize(2 * capacity);
		itemArray[size++] = newItem;
	}
	else
		cout << newItem << "는 중복원소이므로 제거" << endl;
}

void Set::resize(int newCapacity) 
{
	int *tempArr = new int[newCapacity];
	for (int i = 0; i < size; i++)
	{
		tempArr[i] = itemArray[i];
	}
	delete[] itemArray;
	itemArray = tempArr;

	capacity = newCapacity;
}

Set Set::operator &(const Set& set)const 
{
	Set tempSet;
	int* newItemArr;
	for (int i = 0; i < size; i++)
	{
		if (set.isOverlap(itemArray[i]))
			tempSet.add(itemArray[i]);
	}
	newItemArr = tempSet.itemArray;
	tempSet.itemArray = NULL;

	return Set(newItemArr,tempSet.size, tempSet.capacity);
}

Set Set::operator |(const Set& set)const 
{
	Set tempSet;
	int* newItemArr;
	for (int i = 0; i < size; i++)
		tempSet.add(itemArray[i]);
	for(int i=0;i<set.size;i++)
	{
		if(!isOverlap(set.itemArray[i]))
			tempSet.add(set.itemArray[i]);
	}
	newItemArr = tempSet.itemArray;
	tempSet.itemArray = NULL;

	return Set(newItemArr, tempSet.size, tempSet.capacity);
}

bool Set::isOverlap(int newItem) const
{
	for(int i=0;i<size;i++)
	{
		if (itemArray[i] == newItem)
			return true;
	}
	return false;
}

ostream& operator <<(ostream& outputStream, const Set& set)
{
	for (int i = 0; i < set.size; i++)
	{
		outputStream << set.itemArray[i]<<" ";
		
	}
	
	return outputStream;
}

istream& operator >>(istream& inputStream,Set& set)
{
	int curItem;
	inputStream >> curItem;
	while (curItem > -1)
	{
		set.add(curItem);
		inputStream >> curItem;
	}
	return inputStream;
}