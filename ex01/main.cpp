/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:20:25 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/14 17:35:23 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main (void) {
	Data data;
	Data* dataPtr = &data;
	std::cout << BLUE << "The starting addres is: " << NC << GREEN << dataPtr << NC << std::endl;
	uintptr_t serialized = Serializer::serialize(dataPtr);
	std::cout << YELLOW << "The serialized addres is: " << NC << GREEN << &serialized << NC << std::endl;
	Data* newPtr = Serializer::deserialize(serialized);
	std::cout << BLUE << "The deserialized addres is: " << NC << GREEN << newPtr << NC << std::endl;
	return (0);
}