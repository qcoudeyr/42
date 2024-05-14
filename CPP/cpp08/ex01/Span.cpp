#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span()
{
}

Span::Span(unsigned int N):max_size(N) {
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	(void) rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Span::addNumber(int num)
{
	if (numbers.size() >= max_size) {
		throw std::runtime_error("Span is full");
	}
	numbers.push_back(num);
}
int Span::shortestSpan() {
	if (numbers.size() <= 1) {
		throw std::runtime_error("Not enough numbers to find span");
	}
	std::sort(numbers.begin(), numbers.end());
	int shortest = numbers[1] - numbers[0];
	for (size_t i = 2; i < numbers.size(); ++i) {
		shortest = std::min(shortest, numbers[i] - numbers[i - 1]);
	}
	return shortest;
}

// Function to find the longest span
int Span::longestSpan() {
	if (numbers.size() <= 1) {
		throw std::runtime_error("Not enough numbers to find span");
	}
	return *std::max_element(numbers.begin(), numbers.end()) - *std::min_element(numbers.begin(), numbers.end());
}

/* ************************************************************************** */
