#pragma once

#include <array>

namespace CardDeck
{
	// Stacktypen ska vara generisk trots att den enbart anv�nds f�r kort h�r
	template <typename T, size_t U>
	struct Stack {
	public:
		// Klassiska egenskaper hos en stack
		Stack();
		T pop();
		T peek();
		void push(T&& element);
		int size();
		void sort();
		void randomise();
		std::array<T, U> getDeck();
		void cleanUp();

	private:
		std::array<T, U> _d;
		const void* firstElement;
		void* lastElement;
		const void* reserve;
	};

	// Stacken best�r av tre iteratorer, som pekar p� b�rjan, slutet och slutet p� allokeringsrymden
	template <typename T, size_t U>
	Stack<T, U>::Stack() : firstElement(&_d.front()), lastElement(&_d.front()), reserve(&_d.back())
	{
		
	}

	// Genom att flytta slutiteratorn kan vi simulera att den statiska arrayen minskar i storlek
	template <typename T, size_t U>
	T Stack<T, U>::pop()
	{
		auto temp = (int*)lastElement--;

		return temp;
	}

	// Titta p� �versta elementet utan att ta bort det
	template <typename T, size_t U>
	T Stack<T, U>::peek()
	{
		return *lastElement;
	}

	// L�gg till ett element
	template <typename T, size_t U>
	void Stack<T, U>::push(T&& element)
	{
		// TODO
	}

	// Returnera storleken i element p� h�gen
	template <typename T, size_t U>
	int Stack<T, U>::size()
	{
		return U;
	}

	// Sortera h�gen enligt new deck order som Bicycle anv�nder
	template <typename T, size_t U>
	void Stack<T, U>::sort()
	{
		// TODO
	}

	// Blanda h�gen
	template <typename T, size_t U>
	void Stack<T, U>::randomise()
	{
		std::random_shuffle(_d.begin(), _d.end());
	}

	// Returnera objektet i sig
	template <typename T, size_t U>
	std::array<T, U> Stack<T, U>::getDeck()
	{
		return _d;
	}

	// St�da upp leken, �terst�ll dess storlek
	template <typename T, size_t U>
	void Stack<T, U>::cleanUp()
	{
		lastElement = reserve;
	}
}

