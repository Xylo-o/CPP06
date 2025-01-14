/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:14:36 by kali              #+#    #+#             */
/*   Updated: 2025/01/14 16:36:49 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <limits>
#include <regex>
#include "Colors.hpp"

class ScalarConverter {
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        void static convert(const char* input);
};

std::string detectType(const char* input);
static void printConversions(double value, bool isFloat);