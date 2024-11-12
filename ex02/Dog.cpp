/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:55:58 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/12 17:26:18 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

/*--------------------------------------------------------ORTHODOX CANONICAL FORM---------------------------------------------------------*/

Dog::Dog() : Animal(), brain(new Brain()) {
	std::cout << BOLD_ON GREEN << "Default (Dog) constructor called" << BOLD_OFF << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &other) {
	std::cout << BOLD_ON YELLOW << "Copy (Dog) constructor called" << BOLD_OFF << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << BOLD_ON YELLOW << "Copy (Dog) assigment called" << BOLD_OFF <<std::endl;
	if (this != &other) {
		Brain* newBrain = new Brain(*other.brain);
		brain = newBrain;
		this->_type = other._type;
	}
	return (*this);
}

Dog::~Dog() {
	delete brain;
	std::cout << BOLD_ON RED << "Destructor (Dog) called" << RESET << std::endl;
}

/*-----------------------------------------------------GETTER - SETTER -----------------------------------------------------------------*/

void Dog::setIdeasDog(const std::string str, unsigned int idx)const {
	this->brain->setIdeasBrain(str, idx);
}

std::string Dog::getIdeasDog(unsigned int idx)const {
	return(this->brain->getIdeasBrain(idx));
}

/*---------------------------------------------------------FUNCTIONS----------------------------------------------------------------------*/

void Dog::makeSound()const {
	std::cout << BOLD_ON BLUE << "Wouuuuuf 🐶" << RESET << std::endl;
}