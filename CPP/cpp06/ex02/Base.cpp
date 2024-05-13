/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:23:03 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/12 21:32:34 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base* Base::generate() {
	srand(time(NULL));

	int randomNumber = rand() % 3;

	switch (randomNumber) {
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}
