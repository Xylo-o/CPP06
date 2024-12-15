/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:09:56 by adprzyby          #+#    #+#             */
/*   Updated: 2024/12/15 17:06:26 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes.hpp"

int main (void) {
	Base* base = generate();
	std::cout << BLUE << "Using the pointer: " << NC << std::endl;
	identify(base);
	std::cout << YELLOW << "Using the reference: " << NC << std::endl;
	identify(*base);
	return (0);
}