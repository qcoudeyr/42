#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>

// Function to add a range of numbers using iterators

class Span
{

	public:

		Span();
		Span(unsigned int N);
		Span( Span const & src );
		~Span();

		Span &		operator=( Span const & rhs );
		void	addNumber(int num);
		int		shortestSpan();
		int		longestSpan();

		template <typename InputIterator>
		void addRange(InputIterator first, InputIterator last) {
			while (first != last) {
				addNumber(rand_r(reinterpret_cast<unsigned int*>(&first)));
				++first;
			}
		}

	private:
		unsigned int		max_size;
		std::vector<int>	numbers;

};

#endif /* ************************************************************ SPAN_H */
