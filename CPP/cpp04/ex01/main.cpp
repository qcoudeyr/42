/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:45:23 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/29 10:46:31 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main() {

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout<< "\nConstutor test ended now let's test destructor\n"<< std::endl;
	delete j;
	delete i;

	std::cout<< "\nDestructor test ended now let's test Brain on = operator\n"<< std::endl;

	Cat copy;
	Cat cat;

	cat.setIdeas("Miaou Miaou");
	copy.setIdeas("Test Test");
	copy = cat;

	for (int i = 0; i < 100; i++)
		std::cout << copy.getBrain()->getIdea(i);

	std::cout<<std::endl<< "Check that Copy constructor work as exepted in the subject"<<std::endl;
	Cat test(cat);

	for (int i = 0; i < 100; i++)
		std::cout << test.getBrain()->getIdea(i);
	std::cout<<std::endl;

	test.setIdeas("A A");

	for (int i = 0; i < 100; i++)
		std::cout << test.getBrain()->getIdea(i);
	std::cout<<std::endl;

	return (0);
}
