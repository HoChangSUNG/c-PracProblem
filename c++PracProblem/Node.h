#pragma once

template <typename T>
class Node
{
public:
	Node(T* e,  Node<T>* n);
	Node();
	~Node();
	T* getElement()const;
	void setElement(T* d);
	Node<T>* getNext()const;
	void setNext( Node* n);

private:
	T* element=nullptr;
	Node<T>* next = nullptr;

};