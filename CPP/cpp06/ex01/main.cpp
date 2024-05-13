/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:18:17 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/12 21:21:31 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	// Create a Data object
	Data data;
	data.id = 1;
	data.name = "Test";
	data.value = 3.14;

	// Serialize the address of the Data object
	uintptr_t serializedPtr = Serializer::serialize(&data);

	// Deserialize the serialized pointer
	Data* deserializedPtr = Serializer::deserialize(serializedPtr);

	// Check if the deserialized pointer is equal to the original pointer
	if (deserializedPtr == &data) {
		std::cout << "Deserialization successful. Pointers match." << std::endl;
	} else {
		std::cout << "Deserialization failed. Pointers do not match." << std::endl;
	}

	return 0;
}
