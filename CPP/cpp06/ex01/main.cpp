/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:18:17 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/16 09:32:41 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {


	Data data;
	data.id = 1;
	data.name = "Test";
	data.value = 3.14;

	std::cout << "Serialize the address of the Data object" << std::endl;
	uintptr_t serializedPtr = Serializer::serialize(&data);

	std::cout << "Deserialize the serialized pointer" << std::endl;
	Data* deserializedPtr = Serializer::deserialize(serializedPtr);

	std::cout << "Check if the deserialized pointer is equal to the original pointer:" << std::endl;
	if (deserializedPtr == &data) {
		std::cout << "Deserialization successful. Pointers match." << std::endl;
	} else {
		std::cout << "Deserialization failed. Pointers do not match." << std::endl;
	}

	return 0;
}
