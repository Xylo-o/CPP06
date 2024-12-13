/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:14:40 by kali              #+#    #+#             */
/*   Updated: 2024/12/13 16:37:23 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const char* input) {
    std::string type = detectType(input);
    if (type == "unknown") {
        std::cout << RED << "Unknown type" << NC << std::endl;
        return;
    }
    try {
        double d = std::stod(input);
        if (type == "char") {
            char c = input[0];
            if (std::isprint(c)) {
                std::cout << YELLOW << "char: '" << NC << c << YELLOW << "'" << NC << std::endl;
            } else {
                std::cout << YELLOW << "char: " << NC << "Non displayable" << std::endl;
            }
            std::cout << CYAN << "int: " << NC << static_cast<int>(c) << std::endl;
            std::cout << MAGENTA << "float: " << NC << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
            std::cout << BLUE << "double: " << NC << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
        } else if (type == "int") {
			if (std::isnan(d) || std::isinf(d) || d > 2147483647 || d < -2147483648) {
            	std::cout << YELLOW << "char: " << NC << "impossible" << std::endl;
            	std::cout << CYAN << "int: " << NC << "impossible" << std::endl;
				std::cout << MAGENTA << "float: " << NC << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
            	std::cout << BLUE << "double: " << NC << std::fixed << std::setprecision(1) << static_cast<double>(d) << std::endl;
			}
			else {
             	if (d >= 32 && d <= 126) {
                	std::cout << YELLOW << "char: " << NC << "'" << static_cast<char>(d) << "'" << std::endl;
            	} else {
            	    std::cout << YELLOW << "char: " << NC << "Non displayable" << std::endl;
            	}
            		std::cout << CYAN << "int: " << NC << static_cast<int>(d) << std::endl;
            		std::cout << MAGENTA << "float: " << NC << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
            		std::cout << BLUE << "double: " << NC << std::fixed << std::setprecision(1) << static_cast<double>(d) << std::endl;				
			}
        } else {
            if (std::isnan(d) || std::isinf(d)) {
                std::cout << YELLOW << "char: " << NC << "impossible" << std::endl;
                std::cout << CYAN << "int: " << NC << "impossible" << std::endl;
			} 
            std::cout << MAGENTA << "float: " << NC << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
            std::cout << BLUE << "double: " << NC << std::fixed << std::setprecision(1) << static_cast<double>(d) << std::endl;
		}
    } catch (const std::exception&) {
        std::cout << YELLOW << "char: " << NC << "impossible" << std::endl;
        std::cout << CYAN << "int: " << NC << "impossible" << std::endl;
        std::cout << MAGENTA << "float: " << NC << "impossible" << std::endl;
        std::cout << BLUE << "double: " << NC << "impossible" << std::endl;
    }
}

std::string detectType(const char* input) {
    std::regex charRegex("^[a-zA-Z]$");
    std::regex intRegex("^-?\\d+$");
    std::regex floatRegex("^-?\\d*\\.\\d+f$");
    std::regex doubleRegex("^-?\\d*\\.\\d+$");

    if (std::regex_match(input, charRegex)) {
        return "char";
    } else if (std::regex_match(input, intRegex)) {
        return "int";
    } else if (std::regex_match(input, floatRegex)) {
        return "float";
    } else if (std::regex_match(input, doubleRegex)) {
        return "double";
    } else {
        return "unknown";
    }
}