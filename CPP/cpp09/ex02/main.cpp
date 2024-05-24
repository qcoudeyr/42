/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:52:50 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/24 16:03:35 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>


void printSequence(const std::vector<int>& sequence, const std::string& message) {
	std::cout << message;
	for (size_t i = 0; i < sequence.size() && i < 11; ++i) {
		std::cout << sequence[i] << " ";
	}
	if (sequence.size() > 10)
		std::cout << "[...]";
	std::cout << std::endl;
}

void printSequence(const std::deque<int>& sequence, const std::string& message) {
	std::cout << message;
	for (size_t i = 0; i < sequence.size()  && i < 11 ; ++i) {
		std::cout << sequence[i] << " ";
	}
	if (sequence.size() > 10)
		std::cout << "[...]";
	std::cout << std::endl;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Error: No input provided" << std::endl;
		return 1;
	}

	std::vector<int> vectorSequence;
	std::deque<int> dequeSequence;
	for (int i = 1; i < argc; ++i) {
		int num = std::atoi(argv[i]);
		if (num <= 0) {
			std::cerr << "Error: Invalid input" << std::endl;
			return 1;
		}
		vectorSequence.push_back(num);
		dequeSequence.push_back(num);
	}

	printSequence(vectorSequence, "Before: ");

	PmergeMe sortVector;
	clock_t startVector = clock();
	sortVector.vectorSort(vectorSequence);
	clock_t endVector = clock();

	printSequence(vectorSequence, "After: ");
	double timeVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << vectorSequence.size() << " elements with std::vector: " << timeVector << " s" << std::endl;

	PmergeMe sortDeque;
	clock_t startDeque = clock();
	sortDeque.dequeSort(dequeSequence);
	clock_t endDeque = clock();

	double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << dequeSequence.size() << " elements with std::deque: " << timeDeque << " s" << std::endl;

	return 0;
}

