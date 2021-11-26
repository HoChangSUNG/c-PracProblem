#pragma once
#include "Node.h"

template <typename T>
Node<T>::Node(T* e, Node<T>* n)
{
	element = e;
	next = n;
}

template <typename T>
Node<T>::Node()
{}

template <typename T>
Node<T>::~Node()
{
	if (element != nullptr)
		delete element;
}


template <typename T>
 T* Node<T>::getElement()const
{
	return element;
}

template <typename T>
 Node<T>* Node<T>::getNext()const
{
	return next;
}

template <typename T>
void Node<T>::setNext( Node* n)
{
	next = n;
}

template <typename T>
void Node<T>::setElement(T* d)
{
	element = d;
}