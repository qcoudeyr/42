#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
#include <vector>
#include <deque>
#include <algorithm>

class PmergeMe
{
	public:

		PmergeMe();
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe &		operator=( PmergeMe const & rhs );

		template <typename Container>
		void fordJohnsonSort(Container& sequence);

		template <typename Container>
		void merge(Container& sequence, int left, int mid, int right);

		template <typename Container>
		void binaryInsert(Container& sequence, int left, int right, typename Container::value_type value);

	private:

};


std::ostream &			operator<<( std::ostream & o, PmergeMe const & i );

#endif /* ******************************************************** PMERGEME_H */
