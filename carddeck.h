#pragma once

#include <array>
#include <iterator>

namespace CardDeck
{
	// Stacktypen ska vara generisk trots att den enbart anv�nds f�r kort h�r
	template <typename T, size_t U>
	struct Stack {
	public:
		// N�gra klassiska egenskaper hos en stack, samt vissa unika f�r typen
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

	// Stacken best�r av tre iteratorer, som pekar p� b�rjan, slutet och slutet p� allokeringsrymden
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

	// Titta p� �versta elementet utan att ta bort det
	template <typename T, size_t U>
	const T& Stack<T, U>::peek() const
	{
		return &lastElement;
	}

	// L�gg till ett element
	template <typename T, size_t U>
	void Stack<T, U>::push(T* element)
	{
		*lastElement = *element;
		lastElement++;
	}

	// Returnera storleken i element p� h�gen
	template <typename T, size_t U>
	int Stack<T, U>::size() const
	{
		return U;
	}

	// Blanda h�gen
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

	// St�da upp leken, �terst�ll dess storlek
	template <typename T, size_t U>
	void Stack<T, U>::cleanUp()
	{

	}
}

