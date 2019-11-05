#pragma once

#include <array>

namespace CardDeck
{
	// Stacktypen ska vara generisk trots att den enbart används för kort här
	template <typename T, size_t U>
	struct Stack {
	public:
		// Klassiska egenskaper hos en stack
		Stack();
		T pop();
		T peek();
		void push(T& element);
		int size();
		void sort();
		void randomise();
		std::array<T, U> getDeck();

	private:
		std::array<T, U> _d;
	};

	template <typename T, size_t U>
	Stack<T, U>::Stack()
	{
		
	}

	template <typename T, size_t U>
	T Stack<T, U>::pop()
	{
		auto e = std::find(_d.begin(), _d.end(), !NULL);

		return T();
	}

	template <typename T, size_t U>
	T Stack<T, U>::peek()
	{
		return T();
	}

	template <typename T, size_t U>
	void Stack<T, U>::push(T& element)
	{
		
	}

	template <typename T, size_t U>
	int Stack<T, U>::size()
	{
		return U;
	}

	template <typename T, size_t U>
	void Stack<T, U>::sort()
	{

	}

	template <typename T, size_t U>
	void Stack<T, U>::randomise()
	{
		std::random_shuffle(_d.begin(), _d.end());
	}

	template <typename T, size_t U>
	std::array<T, U> Stack<T, U>::getDeck()
	{
		return _d;
	}
}

