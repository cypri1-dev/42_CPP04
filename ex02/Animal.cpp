/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:55:48 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/11 16:45:44 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*--------------------------------------------------------ORTHODOX CANONICAL FORM---------------------------------------------------------*/

Animal::Animal() {
	std::cout << BOLD_ON GREEN << "Default (ANIMAL) constructor called" << BOLD_OFF << std::endl;
	this->_type = "defaultType";
}

Animal::Animal(const Animal &other) {
	std::cout << BOLD_ON YELLOW << "Copy (ANIMAL) constructor called" << BOLD_OFF << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << BOLD_ON YELLOW << "Copy (ANIMAL) assigment called" << BOLD_OFF <<std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << BOLD_ON RED << "Destructor (ANIMAL) called" << RESET << std::endl;
}

/*-----------------------------------------------------GETTER - SETTER -----------------------------------------------------------------*/

std::string Animal::getType()const {
	return (this->_type);
}

/*---------------------------------------------------------FUNCTIONS----------------------------------------------------------------------*/

void Animal::makeSound()const {
	std::cout << BOLD_ON BLUE << "Undifined sound" << RESET << std::endl;
}