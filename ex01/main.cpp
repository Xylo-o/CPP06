/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:20:25 by adprzyby          #+#    #+#             */
/*   Updated: 2024/12/15 15:02:07 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main (void) {
	Data data;
	Data* dataPtr = &data;
	std::cout << BLUE << "The starting addres is: " << NC << GREEN << dataPtr << NC << std::endl;
	uintptr_t serialized = Serializer::serialize(dataPtr);
	Data* newPtr = Serializer::deserialize(serialized);
	std::cout << BLUE << "The serialized addres is: " << NC << GREEN << newPtr << NC << std::endl;
	return (0);
}