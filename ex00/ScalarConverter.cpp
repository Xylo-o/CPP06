/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:14:40 by kali              #+#    #+#             */
/*   Updated: 2024/12/12 14:13:55 by kali             ###   ########.fr       */
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
    std::cout << GREEN << "Data converted successfuly: " << NC << std::endl;
    convertChar(input);
    convertInt(input);
    convertFloat(input);
    convertDouble(input);
}

void convertChar(const char* input) {
    char c = 'c';
    if (strlen(input) == 1 && !isdigit(input[0])) {
        c = input[0];
    } else {
        int i = atoi(input);
        if (i >= 32 && i <= 126) {
            c = static_cast<char>(i);
        } else {
            std::cout << YELLOW << "char: " << NC << "Non displayable" << std::endl;
            return;
    }
    }
    if (std::isprint(c)) {
        std::cout << YELLOW << "char: " << NC << c << std::endl;
    } else {
        std::cout << YELLOW << "char: " << NC << "Non displayable" << std::endl;
    }
}

void convertInt(const char* input) {
    int i = 0;
    
    i = atoi(input);
    
    std::cout << CYAN << "int: " << NC << i << std::endl;
}

void convertFloat(const char* input) {
    float f = 0.0f;
    f = atof(input);
    
    std::cout << MAGENTA << "float: " << NC << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void convertDouble(const char* input) {
    double d = 0.0;
    d = std::stod(input);
    
    std::cout << BLUE << "double: " << NC << std::fixed << std::setprecision(1) << d << std::endl;
}