/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:17:04 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/15 17:42:25 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "colors.hpp"

/*--------------------------------------------------------ORTHODOX CANONICAL FORM---------------------------------------------------------*/

AMateria::AMateria() {
	this->_type = "DefalutAMateria 🪄";
	std::cout << BOLD_ON GREEN << "Default (AMateria) constructor called!" << BOLD_OFF << std::endl;
}

AMateria::AMateria(std::string const &type) {
	this->_type = type;
	std::cout << BOLD_ON BLUE << "Custom (AMateria) constructor called!" << BOLD_OFF << std::endl;
}

AMateria::AMateria(const AMateria &other) {
	std::cout << BOLD_ON YELLOW << "Copy (AMateria) constructor called!" << BOLD_OFF << std::endl;
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other) {
	if (this != &other) {
		this->_type = other.getType();
	}
	std::cout << BOLD_ON YELLOW << "Copy (AMateria) assigment called!" << BOLD_OFF << std::endl;
	return (*this);
}

AMateria::~AMateria() {
	std::cout << BOLD_ON RED << "Destructor (AMateria) called!" << BOLD_OFF << std::endl;
}

/*-----------------------------------------------------GETTER - SETTER -----------------------------------------------------------------*/
 
std::string const &AMateria::getType()const {
	return (this->_type);
}

/*---------------------------------------------------------FUNCTIONS----------------------------------------------------------------------*/

void AMateria::use(ICharacter& target) {
	std::cout << BOLD_ON BLUE << "does nothing to " << target.getName() << BOLD_OFF << std::endl;
}