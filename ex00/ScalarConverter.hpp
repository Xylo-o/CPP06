/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:14:36 by kali              #+#    #+#             */
/*   Updated: 2024/12/12 14:32:29 by kali             ###   ########.fr       */
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
#include "Colors.hpp"

class ScalarConverter {
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        void static convert(const char* input);
};

void convertChar(const char* input);
void convertInt(const char* input);
void convertFloat(const char* input);
void convertDouble(const char* input);