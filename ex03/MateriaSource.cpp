/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:43:17 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/15 15:42:52 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "colors.hpp"

/*--------------------------------------------------------ORTHODOX CANONICAL FORM---------------------------------------------------------*/

MateriaSource::MateriaSource() {
	for(int i = 0; i < 4; i++) {
		this->_stock[i] = 0;
	}
	std::cout << BOLD_ON GREEN << "Default (MateriaSource) constuctor called!" << BOLD_OFF << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	for (int i = 0; i < 4; i++) {
		if (other._stock[i] != 0)
			this->_stock[i] = other._stock[i]->clone();
		else
			this->_stock[i] = 0;
	}
	std::cout << BOLD_ON YELLOW << "Copy (MateriaSource) constuctor called!" << BOLD_OFF << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (other._stock[i] != 0)
				this->_stock[i] = other._stock[i]->clone();
			else
				this->_stock[i] = 0;
		}
	}
	std::cout << BOLD_ON YELLOW << "Copy (MateriaSource) assigment called!" << BOLD_OFF << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->_stock[i] != 0)
			delete this->_stock[i];
	}
	std::cout << BOLD_ON RED << "Destructor (MateriaSource) called!" << BOLD_OFF << std::endl;
}

/*---------------------------------------------------------FUNCTIONS----------------------------------------------------------------------*/

void MateriaSource::learnMateria(AMateria *m) {
	if (!m) {
		std::cout << BOLD_ON RED << "No Materia to learn!" << BOLD_OFF << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (this->_stock[i] == 0) {
			this->_stock[i] = m->clone();
			std::cout << "Materia " << m->getType() << " learned in slot " << i << "." << std::endl;
			return;
		}
	}
	std::cout << "MateriaSource is full, cannot learn more Materias." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (this->_stock[i] && this->_stock[i]->getType() == type) {
			std::cout << "Creating Materia of type " << type << "." << std::endl;
			return this->_stock[i]->clone();
		}
	}
	std::cout << "Unknown Materia type: " << type << "." << std::endl;
	return 0;
}