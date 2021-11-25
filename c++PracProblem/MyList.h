#pragma once
#include "Node.hpp"
#include <fstream>
using namespace std;
template <typename T>
class MyList
{
public:
	MyList();
	~MyList();
	int getSize()const;
	bool isEmpty()const;

	void add( T* person);
	void print();
	void deleteElement(string deleteKey);
	void updateElement(string updateKey,int updateDonorMoney);
	void fileSave(string path)const;
	bool isExist(string findKey)const;
	void moveNode(Node<T>* newNode);
private:
	Node<T>* head;
	int size;
};