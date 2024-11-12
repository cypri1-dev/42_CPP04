/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:55:53 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/12 17:31:07 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"

/*--------------------------------------------------------ORTHODOX CANONICAL FORM---------------------------------------------------------*/

Cat::Cat() : Animal(), brain(new Brain()) {
	std::cout << BOLD_ON GREEN << "Default (Cat) constructor called" << BOLD_OFF << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &other) {
	std::cout << BOLD_ON YELLOW << "Copy (Cat) constructor called" << BOLD_OFF << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << BOLD_ON YELLOW << "Copy (Cat) assigment called" << BOLD_OFF <<std::endl;
	if (this != &other) {
		delete brain;
		brain = new Brain(*other.brain);
		this->_type = other._type;
	}
	return (*this);
}

Cat::~Cat() {
	delete brain;
	std::cout << BOLD_ON RED << "Destructor (Cat) called" << RESET << std::endl;
}

/*-----------------------------------------------------GETTER - SETTER -----------------------------------------------------------------*/

void Cat::setIdeasCat(const std::string str, unsigned int idx)const {
	this->brain->setIdeasBrain(str, idx);
}

std::string Cat::getIdeasCat(unsigned int idx)const {
	return(this->brain->getIdeasBrain(idx));
}

/*---------------------------------------------------------FUNCTIONS----------------------------------------------------------------------*/

void Cat::makeSound()const {
	std::cout << BOLD_ON BLUE << "Miaouuuuuuu 😸" << RESET << std::endl;
}