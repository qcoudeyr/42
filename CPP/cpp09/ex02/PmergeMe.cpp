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

template <typename Container>
void fordJohnsonSort(Container& sequence) {
	int n = sequence.size();

	if (n < 2) {
		return;
	}

	// Step 1: Pair up elements and sort each pair
	Container maxElements;
	Container minElements;

	for (int i = 0; i < n - 1; i += 2) {
		if (sequence[i] > sequence[i + 1]) {
			maxElements.push_back(sequence[i]);
			minElements.push_back(sequence[i + 1]);
		} else {
			maxElements.push_back(sequence[i + 1]);
			minElements.push_back(sequence[i]);
		}
	}

	// If there's an odd number of elements, add the last one to maxElements
	if (n % 2 != 0) {
		maxElements.push_back(sequence[n - 1]);
	}

	// Step 2: Sort the maxElements array
	std::sort(maxElements.begin(), maxElements.end());

	// Step 3: Insert minElements into the sorted maxElements array
	for (const auto& minElement : minElements) {
		binaryInsert(maxElements, 0, maxElements.size() - 1, minElement);
	}

	// Copy the sorted sequence back to the original array
	sequence = maxElements;
}

template <typename Container>
void binaryInsert(Container& sequence, int left, int right, typename Container::value_type value) {
	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (sequence[mid] == value) {
			sequence.insert(sequence.begin() + mid, value);
			return;
		} else if (sequence[mid] < value) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	sequence.insert(sequence.begin() + left, value);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
