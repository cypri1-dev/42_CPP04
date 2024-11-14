/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:51:27 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/13 22:15:46 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "colors.hpp"

/*--------------------------------------------------------ORTHODOX CANONICAL FORM---------------------------------------------------------*/

Character::Character() {
	this->_name = "DefaultCharacter 🧌";
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = 0;
	}
	std::cout << BOLD_ON GREEN << "Default (Character) constructor called!" << BOLD_OFF << std::endl;
}

Character::Character(std::string const &name) {
	this->_name = name;
	for(int i = 0; i < 4; i++) {
		this->_inventory[i] = 0;
	}
	std::cout << BOLD_ON BLUE << "Custom (Character) constructor called!" << BOLD_OFF << std::endl;
}

Character::Character(const Character &other) {
	std::cout << BOLD_ON YELLOW << "Copy (Character) constructor called!" << BOLD_OFF << std::endl;
	this->_name = other.getName();
	for(int i = 0; i < 4; i++) {
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = 0;
	}
}

Character &Character::operator=(const Character &other) {
	if (this != &other) {
	this->_name = other.getName();
	for(int i = 0; i < 4; i++) {
		if (this->_inventory[i] != 0)
			delete this->_inventory[i];
		this->_inventory[i] = other._inventory[i];
		}
	}
	return (*this);
	std::cout << BOLD_ON YELLOW << "Copy (Character) assigment called!" << BOLD_OFF << std::endl;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i] != 0)
			delete this->_inventory[i];
	std::cout << BOLD_ON RED << "Destructor (Character) called!" << BOLD_OFF << std::endl;
}