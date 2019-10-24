#include "carddeck.h"

template<typename T>
CardDeck::Stack<T>::Stack()
{
	
}

template<typename T>
T CardDeck::Stack<T>::pop()
{
	return 0;
}

template<typename T>
T CardDeck::Stack<T>::peek()
{
	return 0;
}

template<typename T>
void CardDeck::Stack<T>::push(T &element)
{
	_d.push_back(element);
}

template<typename T>
int CardDeck::Stack<T>::size()
{
	return 0;
}

template<typename T>
void CardDeck::Stack<T>::sort()
{

}

template<typename T>
void CardDeck::Stack<T>::randomise()
{

}

template<typename T>
void CardDeck::Stack<T>::insert(int position)
{

}
