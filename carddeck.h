#pragma once

#include <vector>
#include <array>
#include "card.h"

namespace CardDeck
{
	template <typename T>
	struct Stack {
	public:
		Stack();
		T pop();
		T peek();
		void push(T &element);
		int size();
		void sort();
		void randomise();
		void insert(int position);

	private:
		std::array<Card::Card, 52> _d;
	};
}