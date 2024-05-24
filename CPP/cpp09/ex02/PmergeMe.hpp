#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
#include <vector>
#include <deque>

class PmergeMe
{

	public:

		PmergeMe();
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe &		operator=( PmergeMe const & rhs );

		void dequeSort(std::deque<int>& sequence);

		void vectorSort(std::vector<int>& sequence);

	private:
		void vectorMergeInsertSort(std::vector<int>& sequence, int left, int right);
		void vectorMerge(std::vector<int>& sequence, int left, int mid, int right);

		void dequeMergeInsertSort(std::deque<int>& sequence, int left, int right);
		void dequeMerge(std::deque<int>& sequence, int left, int mid, int right);
};


std::ostream &			operator<<( std::ostream & o, PmergeMe const & i );

#endif /* ******************************************************** PMERGEME_H */
