/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:09:03 by adprzyby          #+#    #+#             */
/*   Updated: 2024/12/15 15:18:50 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Includes.hpp"

class Base {
	public:
		virtual ~Base();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);