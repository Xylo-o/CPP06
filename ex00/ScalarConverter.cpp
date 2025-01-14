/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:14:40 by kali              #+#    #+#             */
/*   Updated: 2025/01/14 17:24:24 by adprzyby         ###   ########.fr       */
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
    if (type == "char") {
        char c = input[0];
        double d = static_cast<double>(c);
        printConversions(d, false);
        return;
    }
    if (type == "special") {
        bool isFloat = false;
        std::string valStr(input);

        if (!valStr.empty() && valStr.back() == 'f')
            isFloat = true;

        double value = 0.0;
        try {
            if (isFloat)
                value = std::stof(valStr);
            else
                value = std::stod(valStr);

            printConversions(value, isFloat);
        }
        catch (...) {
            std::cout << YELLOW << "char: " << NC << "impossible" << std::endl;
            std::cout << CYAN << "int: " << NC << "impossible" << std::endl;
            std::cout << MAGENTA << "float: " << NC << "impossible" << std::endl;
            std::cout << BLUE << "double: " << NC << "impossible" << std::endl;
        }
        return;
    }
    try {
        double d = 0.0;
        if (type == "float")
            d = std::stof(input);
        else
            d = std::stod(input);
        printConversions(d, (type == "float"));
    }
    catch (const std::exception&) {
        std::cout << YELLOW << "char: " << NC << "impossible" << std::endl;
        std::cout << CYAN << "int: " << NC << "impossible" << std::endl;
        std::cout << MAGENTA << "float: " << NC << "impossible" << std::endl;
        std::cout << BLUE << "double: " << NC << "impossible" << std::endl;
    }
}

static void printConversions(double value, bool isFloat) {
    if (std::isnan(value) || std::isinf(value) ||
        value < static_cast<double>(std::numeric_limits<char>::min()) ||
        value > static_cast<double>(std::numeric_limits<char>::max())) {
        std::cout << YELLOW << "char: " << NC << "impossible" << std::endl;
    }
    else {
        char c = static_cast<char>(value);
        if (std::isprint(c))
            std::cout << YELLOW << "char: " << NC << "'" << c << "'" << std::endl;
        else
            std::cout << YELLOW << "char: " << NC << "Non displayable" << std::endl;
    }
    if (std::isnan(value) || std::isinf(value) ||
        value < static_cast<double>(std::numeric_limits<int>::min()) ||
        value > static_cast<double>(std::numeric_limits<int>::max())) {
        std::cout << CYAN << "int: " << NC << "impossible" << std::endl;
    }
    else {
        int i = static_cast<int>(value);
        std::cout << CYAN << "int: " << NC << i << std::endl;
    }
    {
        float fVal = static_cast<float>(value);
        if (std::isnan(fVal))
            std::cout << MAGENTA << "float: " << NC << "nanf" << std::endl;
        else if (std::isinf(fVal))
            std::cout << MAGENTA << "float: " << NC << ((fVal < 0) ? "-inff" : "+inff") << std::endl;
        else
            std::cout << MAGENTA << "float: " << NC << std::fixed << std::setprecision(1) << fVal << "f" << std::endl;
    }
    {
        if (std::isnan(value))
            std::cout << BLUE << "double: " << NC << "nan" << std::endl;
        else if (std::isinf(value))
            std::cout << BLUE << "double: " << NC << ((value < 0) ? "-inf" : "+inf") << std::endl;
        else
            std::cout << BLUE << "double: " << NC << std::fixed << std::setprecision(1) << value << std::endl;
    }
}

std::string detectType(const char* input) {
    std::regex charRegex("^[a-zA-Z]$");
    std::regex intRegex("^-?\\d+$");
    std::regex floatRegex("^-?\\d*\\.\\d+f$");
    std::regex doubleRegex("^-?\\d*\\.\\d+$");
	std::regex specialFloatRegex("^[+-]?(inf|inff|nan|nanf)$");

    if (std::regex_match(input, charRegex)) {
        return "char";
    } else if (std::regex_match(input, intRegex)) {
        return "int";
    } else if (std::regex_match(input, floatRegex)) {
        return "float";
    } else if (std::regex_match(input, doubleRegex)) {
        return "double";
	} else if (std::regex_match(input, specialFloatRegex)) {
		return "special";
	}
	else {
        return "unknown";
    }
}