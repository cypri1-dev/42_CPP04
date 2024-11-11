/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:01:33 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/11 17:05:54 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*--------------------------------------------------------ORTHODOX CANONICAL FORM---------------------------------------------------------*/

WrongAnimal::WrongAnimal() {
	std::cout << BOLD_ON GREEN << "Default (WrongAnimal) constructor called" << BOLD_OFF << std::endl;
	this->_type = "defaultType(W)";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	std::cout << BOLD_ON YELLOW << "Copy (WrongAnimal) constructor called" << BOLD_OFF << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << BOLD_ON YELLOW << "Copy (WrongAnimal) assigment called" << BOLD_OFF <<std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << BOLD_ON RED << "Destructor (WrongAnimal) called" << RESET << std::endl;
}

/*-----------------------------------------------------GETTER - SETTER -----------------------------------------------------------------*/

std::string WrongAnimal::getType()const {
	return (this->_type);
}

/*---------------------------------------------------------FUNCTIONS----------------------------------------------------------------------*/

void WrongAnimal::makeSound()const {
	std::cout << BOLD_ON BLUE << "Undifined sound" << RESET << std::endl;
}