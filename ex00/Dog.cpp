/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:55:58 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/11 19:13:16 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"

/*--------------------------------------------------------ORTHODOX CANONICAL FORM---------------------------------------------------------*/

Dog::Dog() {
	std::cout << BOLD_ON GREEN << "Default (Dog) constructor called" << BOLD_OFF << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << BOLD_ON YELLOW << "Copy (Dog) constructor called" << BOLD_OFF << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << BOLD_ON YELLOW << "Copy (Dog) assigment called" << BOLD_OFF <<std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << BOLD_ON RED << "Destructor (Dog) called" << RESET << std::endl;
}

/*-----------------------------------------------------GETTER - SETTER -----------------------------------------------------------------*/

/*---------------------------------------------------------FUNCTIONS----------------------------------------------------------------------*/

void Dog::makeSound()const {
	std::cout << BOLD_ON BLUE << "Wouuuuuf 🐶" << RESET << std::endl;
}