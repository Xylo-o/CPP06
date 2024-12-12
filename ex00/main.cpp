/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:15:18 by kali              #+#    #+#             */
/*   Updated: 2024/12/12 13:36:45 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int argc, char** argv) {
    if (argc != 2) {
        std::cerr << RED << "Invalid number of arguments" << NC << std::endl;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}