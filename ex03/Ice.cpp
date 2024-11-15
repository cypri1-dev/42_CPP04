/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:54:03 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/15 17:36:36 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "colors.hpp"


/*--------------------------------------------------------ORTHODOX CANONICAL FORM---------------------------------------------------------*/

Ice::Ice() {
	this->_type = "ice 🧊";
	std::cout << BOLD_ON GREEN << "Default (Ice) constructor called!" << BOLD_OFF << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) {
	*this = other;
	std::cout << BOLD_ON YELLOW << "Copy (Ice) constructor called!" << BOLD_OFF << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
	std::cout << BOLD_ON YELLOW << "Copy (Ice) assigment called!" << BOLD_OFF << std::endl;
	if (this != &other) {
		this->_type = other.getType();
	}
	return (*this);
}

Ice::~Ice() {
	std::cout << BOLD_ON RED << "Destuctor (Ice) called!" << BOLD_OFF << std::endl;
}

/*-----------------------------------------------------GETTER - SETTER -----------------------------------------------------------------*/

/*---------------------------------------------------------FUNCTIONS----------------------------------------------------------------------*/

AMateria* Ice::clone()const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << BOLD_ON BLUE << "* shoots an ice bolt at " << target.getName() << "*" << BOLD_OFF << std::endl;
}
