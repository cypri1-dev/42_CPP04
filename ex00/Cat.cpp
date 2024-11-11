/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:55:53 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/11 19:12:28 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

/*--------------------------------------------------------ORTHODOX CANONICAL FORM---------------------------------------------------------*/

Cat::Cat() {
	std::cout << BOLD_ON GREEN << "Default (Cat) constructor called" << BOLD_OFF << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << BOLD_ON YELLOW << "Copy (Cat) constructor called" << BOLD_OFF << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << BOLD_ON YELLOW << "Copy (Cat) assigment called" << BOLD_OFF <<std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << BOLD_ON RED << "Destructor (Cat) called" << RESET << std::endl;
}

/*-----------------------------------------------------GETTER - SETTER -----------------------------------------------------------------*/

/*---------------------------------------------------------FUNCTIONS----------------------------------------------------------------------*/

void Cat::makeSound()const {
	std::cout << BOLD_ON BLUE << "Miaouuuuuuu 😸" << RESET << std::endl;
}