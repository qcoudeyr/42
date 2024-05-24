/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:52:50 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/24 15:28:31 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try {
		RPN rpn;
		int result = rpn.evaluate(argv[1]);
		std::cout << result << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	return 0;
}
