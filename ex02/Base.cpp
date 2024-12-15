/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:08:20 by adprzyby          #+#    #+#             */
/*   Updated: 2024/12/15 17:06:20 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes.hpp"

Base::~Base() {}

Base* generate(void) {
	std::srand(std::time(0));
	int random = std::rand() % 3;
	
	switch (random) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return nullptr;
	}
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << GREEN "The type exists and it's: " << NC << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << GREEN "The type exists and it's: " << NC << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << GREEN "The type exists and it's: " << NC << "C" << std::endl;
    } else {
        std::cout << RED << "Unknown type" << NC << std::endl;
    }
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << GREEN "The type exists and it's: " << NC << "A" << std::endl;
    } catch (std::bad_cast&) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << GREEN "The type exists and it's: " << NC << "B" << std::endl;
    } catch (std::bad_cast&) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << GREEN "The type exists and it's: " << NC << "C" << std::endl;
    } catch (std::bad_cast&) {}
}