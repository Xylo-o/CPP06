/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:14:40 by kali              #+#    #+#             */
/*   Updated: 2024/12/12 15:24:43 by kali             ###   ########.fr       */
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
    std::cout << GREEN << "Data converted successfully: " << NC << std::endl;
    convertChar(input);
    convertInt(input);
    convertFloat(input);
    convertDouble(input);
}

void convertChar(const char* input) {
    char c = 'c';
    double d = 0.0;
    try {
        d = std::stod(input);
    } catch (const std::invalid_argument& e) {
        if (strlen(input) == 1 && std::isalpha(input[0])) {
            c = input[0];
            std::cout << YELLOW << "char: " << NC << c << std::endl;
        } else {
            std::cout << YELLOW << "char: " << NC << "IMPOSSIBIBLE" << std::endl;
        }
        return;
    } catch (const std::out_of_range& e) {
        std::cout << YELLOW << "char: " << NC << "IMPOSSIBIBLE" << std::endl;
        return;
    }
    if (std::isnan(d) || std::isinf(d)) {
        std::cout << YELLOW << "char: " << NC << "IMPOSSIBIBLE" << std::endl;
        return;
    }
    int i = static_cast<int>(d);
    if (i >= 32 && i <= 126) {
        c = static_cast<char>(i);
    } else {
        std::cout << YELLOW << "char: " << NC << "Non displayable" << std::endl;
        return;
    }
    if (std::isprint(c)) {
        std::cout << YELLOW << "char: " << NC << c << std::endl;
    } else {
        std::cout << YELLOW << "char: " << NC << "Non displayable" << std::endl;
    }
}

void convertInt(const char* input) {
    int i = 0;
    double d = 0.0;
    try {
        d = std::stod(input);
    } catch (const std::invalid_argument& e) {
        std::cout << CYAN << "int: " << NC << "IMPOSSIBIBLE" << std::endl;
        return;
    } catch (const std::out_of_range& e) {
        std::cout << CYAN << "int: " << NC << "IMPOSSIBIBLE" << std::endl;
        return;
    }
    if (std::isnan(d) || std::isinf(d)) {
        std::cout << CYAN << "int: " << NC << "IMPOSSIBIBLE" << std::endl;
        return;
    }
    i = static_cast<int>(d);
    std::cout << CYAN << "int: " << NC << i << std::endl;
}

void convertFloat(const char* input) {
    float f = 0.0f;
    try {
        f = std::stof(input);
    } catch (const std::invalid_argument& e) {
        std::cout << MAGENTA << "float: " << NC << "IMPOSSIBIBLE" << std::endl;
        return;
    } catch (const std::out_of_range& e) {
        std::cout << MAGENTA << "float: " << NC << "IMPOSSIBIBLE" << std::endl;
        return;
    }
    std::cout << MAGENTA << "float: " << NC << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void convertDouble(const char* input) {
    double d = 0.0;
    try {
        d = std::stod(input);
    } catch (const std::invalid_argument& e) {
        std::cout << BLUE << "double: " << NC << "IMPOSSIBIBLE" << std::endl;
        return;
    } catch (const std::out_of_range& e) {
        std::cout << BLUE << "double: " << NC << "IMPOSSIBIBLE" << std::endl;
        return;
    }
    std::cout << BLUE << "double: " << NC << std::fixed << std::setprecision(1) << d << std::endl;
}