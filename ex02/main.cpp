/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:09:56 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/14 17:49:18 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Colors.hpp"

int main (void) {
	Base* base = generate();
	std::cout << BLUE << "Using the pointer: " << NC << std::endl;
	identify(base);
	std::cout << YELLOW << "Using the reference: " << NC << std::endl;
	identify(*base);
	delete base;
	return (0);
}