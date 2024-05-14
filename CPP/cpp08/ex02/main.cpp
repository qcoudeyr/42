/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:18:17 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/14 16:49:00 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main (void){

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "\nUsing MutantStack:" << std::endl;
	std::cout << "Top element: " <<  mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	// Iterate through MutantStack
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Elements in MutantStack:" << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	// Copy MutantStack to std::stack
	std::stack<int> s(mstack);

	std::list<int> l;
	l.push_back(5);
	l.push_back(17);
	std::cout << "\nUsing std::list:" << std::endl;
	std::cout << "Top element: " << l.back() << std::endl;
	l.pop_back();
	std::cout << "Size after pop: " << l.size() << std::endl;
	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	l.push_back(0);

	// Iterate through std::list
	std::cout << "Elements in std::list:" << std::endl;
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << std::endl;
	}

	return 0;
}

