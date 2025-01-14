/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:10:56 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/14 17:30:22 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Data {
	public:
		Data();
		Data(int id, int data);
		Data(const Data& other);
		Data& operator=(const Data& other);
		~Data();

		int getId();
		int getData();
	private:
		int id;
		int data;
};