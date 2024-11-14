/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:35:44 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/13 17:47:57 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"

/*--------------------------------------------------------ORTHODOX CANONICAL FORM---------------------------------------------------------*/

Cure::Cure() {
	this->_type = "cure 💊";
	std::cout << BOLD_ON GREEN << "Default (Cure) constructor called!" << BOLD_OFF << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other) {
	*this = other;
	std::cout << BOLD_ON YELLOW << "Copy (Cure) constructor called!" << BOLD_OFF << std::endl;
}

Cure &Cure::operator=(const Cure &other) {
	std::cout << BOLD_ON YELLOW << "Copy (Cure) assigment called!" << BOLD_OFF << std::endl;
	if (this != &other) {
		this->_type = other.getType();
	}
	return (*this);
}

Cure::~Cure() {
	std::cout << BOLD_ON RED << "Destuctor (Cure) called!" << BOLD_OFF << std::endl;
}

/*-----------------------------------------------------GETTER - SETTER -----------------------------------------------------------------*/

/*---------------------------------------------------------FUNCTIONS----------------------------------------------------------------------*/

AMateria* Cure::clone()const {
	return new Cure(*this);
}