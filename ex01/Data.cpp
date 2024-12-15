/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:10:42 by adprzyby          #+#    #+#             */
/*   Updated: 2024/12/15 15:04:22 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : id(0), data(0) {}
Data::Data(int id, int data) : id(id), data(data) {}
Data::Data(const Data& other) : id(other.id), data(other.data) {}
Data& Data::operator=(const Data& other) {
	if (this != &other) {
		this->id = other.id;
		this->data = other.data;
	}
	return *this;
}
Data::~Data() {}

int Data::getId() {
	return id;
}
int Data::getData() {
	return data;
}