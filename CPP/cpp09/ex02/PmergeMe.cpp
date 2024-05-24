#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe( const PmergeMe & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i )
{
	//o << "Value = " << i.getValue();
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void PmergeMe::dequeSort(std::deque<int>& sequence) {
	dequeMergeInsertSort(sequence, 0, sequence.size() - 1);
}

void PmergeMe::dequeMergeInsertSort(std::deque<int>& sequence, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		dequeMergeInsertSort(sequence, left, mid);
		dequeMergeInsertSort(sequence, mid + 1, right);
		dequeMerge(sequence, left, mid, right);
	}
}

void PmergeMe::dequeMerge(std::deque<int>& sequence, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	std::deque<int> leftSeq(n1);
	std::deque<int> rightSeq(n2);

	for (int i = 0; i < n1; ++i) {
		leftSeq[i] = sequence[left + i];
	}
	for (int i = 0; i < n2; ++i) {
		rightSeq[i] = sequence[mid + 1 + i];
	}

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (leftSeq[i] <= rightSeq[j]) {
			sequence[k++] = leftSeq[i++];
		} else {
			sequence[k++] = rightSeq[j++];
		}
	}

	while (i < n1) {
		sequence[k++] = leftSeq[i++];
	}
	while (j < n2) {
		sequence[k++] = rightSeq[j++];
	}
}

void PmergeMe::vectorSort(std::vector<int>& sequence) {
	vectorMergeInsertSort(sequence, 0, sequence.size() - 1);
}

void PmergeMe::vectorMergeInsertSort(std::vector<int>& sequence, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		vectorMergeInsertSort(sequence, left, mid);
		vectorMergeInsertSort(sequence, mid + 1, right);
		vectorMerge(sequence, left, mid, right);
	}
}

void PmergeMe::vectorMerge(std::vector<int>& sequence, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	std::vector<int> leftSeq(n1);
	std::vector<int> rightSeq(n2);

	for (int i = 0; i < n1; ++i) {
		leftSeq[i] = sequence[left + i];
	}
	for (int i = 0; i < n2; ++i) {
		rightSeq[i] = sequence[mid + 1 + i];
	}

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (leftSeq[i] <= rightSeq[j]) {
			sequence[k++] = leftSeq[i++];
		} else {
			sequence[k++] = rightSeq[j++];
		}
	}

	while (i < n1) {
		sequence[k++] = leftSeq[i++];
	}
	while (j < n2) {
		sequence[k++] = rightSeq[j++];
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
