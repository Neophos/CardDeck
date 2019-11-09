#pragma once

#include <array>
#include <iterator>

namespace CardDeck
{
	// Stacktypen ska vara generisk trots att den enbart används för kort här
	template <typename T, size_t U>
	struct Stack {
	public:
		// Några klassiska egenskaper hos en stack, samt vissa unika för typen
		Stack();
		T* pop();
		const T& peek() const;
		void push(T*);
		int size() const;
		void randomise();
		std::array<T, U> getStack();
		void cleanUp();

	private:
		std::array<T, U> _d;
		const void* firstElement;
		T* lastElement;
		const void* reserve;
	};

	// Stacken består av tre iteratorer, som pekar på början, slutet och slutet på allokeringsrymden
	template <typename T, size_t U>
	Stack<T, U>::Stack() : _d(), firstElement(&_d.front()), lastElement(&_d.front()), reserve(&_d.back())
	{
		
	}

	// Genom att flytta slutiteratorn kan vi simulera att den statiska arrayen minskar i storlek
	template <typename T, size_t U>
	T* Stack<T, U>::pop()
	{
		lastElement--;

		return lastElement;
	}

	// Titta på översta elementet utan att ta bort det
	template <typename T, size_t U>
	const T& Stack<T, U>::peek() const
	{
		return &lastElement;
	}

	// Lägg till ett element
	template <typename T, size_t U>
	void Stack<T, U>::push(T* element)
	{
		*lastElement = *element;
		lastElement++;
	}

	// Returnera storleken i element på högen
	template <typename T, size_t U>
	int Stack<T, U>::size() const
	{
		return U;
	}

	// Blanda högen
	template <typename T, size_t U>
	void Stack<T, U>::randomise()
	{
		std::random_shuffle(_d.begin(), _d.end());
	}

	// Returnera objektet i sig
	template <typename T, size_t U>
	std::array<T, U> Stack<T, U>::getStack()
	{
		return _d;
	}

	// Städa upp leken, återställ dess storlek
	template <typename T, size_t U>
	void Stack<T, U>::cleanUp()
	{

	}
}

