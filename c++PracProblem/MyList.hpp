#include "MyList.h"
#include <iostream>

template <typename T>
MyList<T>::MyList()
{
	head = new Node<T>();
	size = 0;
}

template <typename T>
int MyList<T>::getSize()const
{
	return size;
}

template <typename T>
bool  MyList<T>::isEmpty()const
{
	return size == 0;
}

template <typename T>
void MyList<T>::add(T* element)
{
	Node<T>* newNode = new Node<T>(element, nullptr);
	
	Node<T>*cur=nullptr;
	Node<T>* prev = head;

	if(!isEmpty())
	{
		for (cur= head->getNext(); cur != nullptr; cur = cur->getNext(), prev = prev->getNext())
		{
			if (newNode->getElement()->compareTo(*(cur->getElement()))>0)
				break;
		}
	}
	 
	prev->setNext(newNode);
	newNode->setNext(cur);

	size++;
}

template <typename T>
void MyList<T>::print()
{
	Node<T>* cur;
	for (cur = head->getNext(); cur != nullptr; cur = cur->getNext())
		cur->getElement()->print();
}

template <typename T>
MyList<T>::~MyList() 
{
	Node<T>* cur = head;
	Node<T>* next;

	for(cur;cur!=nullptr;cur=next)
	{
		next = cur->getNext();
		delete cur;
	}
}

template <typename T>
void MyList<T>::deleteElement(string deleteKey)
{
	Node<T>* cur = nullptr;
	Node<T>* prev = head;

	for (cur= head->getNext(); cur != nullptr; cur = cur->getNext(), prev = prev->getNext())
	{
		if ((cur->getElement()->getKey()==deleteKey) || (cur->getElement()->getPhoneNumber()==deleteKey))
			break; 
	}

	if (cur == nullptr) //해당 조건에 만족하는 기탁자가 존재하지 않은 경우
	{
		cout << "해당 조건에 만족하는 기탁자가 존재하지 않습니다" << endl;
		return;
	}
	cout << "<삭제> ";
	cur->getElement()->print();//삭제된 정보 출력

	prev->setNext(cur->getNext());
	delete cur;

	size--;
}

template <typename T>
void MyList<T>::updateElement(string updateKey,int updateDonorMoney)
{
	if (isEmpty())
	{
		cout << "등록된 기탁자가 한명도 없습니다";
		return;
	}

	Node<T>* cur = nullptr;
	Node<T>* prev = head;

	for (cur = head->getNext(); cur != nullptr; cur = cur->getNext())
	{
		if ((cur->getElement()->getKey  () == updateKey) || (cur->getElement()->getPhoneNumber() == updateKey))
			break;
		prev = prev->getNext();
	}

	Node<T>* temp = cur->getNext();
	prev->setNext(temp);

	cur->getElement()->plusDonationMoney(updateDonorMoney);
	cur->setNext(nullptr);

	cout << "<변경> ";
	cur->getElement()->print();//변경 정보 출력

	moveNode(cur);//변경된 노드 다시 정렬
}

template <typename T>
void MyList<T>::moveNode(Node<T>* newNode)//노드 정렬
{

	Node<T>* cur = nullptr;
	Node<T>* prev = head;

	for (cur = head->getNext(); cur != nullptr; cur = cur->getNext(), prev = prev->getNext())
	{
		if (newNode->getElement()->compareTo(*(cur->getElement()))>0)
			break;
	}
	
	prev->setNext(newNode);
	newNode->setNext(cur);
}


template <typename T>
void MyList<T>::fileSave(string path)const
{
	ofstream outStream;
	outStream.open(path);

	Node<T>* cur;
	for (cur = head->getNext(); cur != nullptr; cur = cur->getNext())
		outStream << cur->getElement()->toString() << endl;

	outStream.close();
}

template <typename T>
bool MyList<T>::isExist(string findKey)const
{
	for (Node<T>* cur = head->getNext(); cur != nullptr; cur = cur->getNext())
	{
		if ((cur->getElement()->getKey() == findKey) || (cur->getElement()->getPhoneNumber() == findKey))
			return true;
	}
	return false;
}
