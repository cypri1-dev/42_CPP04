/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:51:27 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/14 17:32:43 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "colors.hpp"

/*--------------------------------------------------------ORTHODOX CANONICAL FORM---------------------------------------------------------*/

Character::Character() {
	this->_name = "DefaultCharacter 🧌";
	this->_groundCount = 0;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = nullptr;
	}
	for (int i = 0; i < 100; i++) {
		this->_ground[i] = nullptr;
	}
	std::cout << BOLD_ON GREEN << "Default (Character) constructor called!" << BOLD_OFF << std::endl;
}

Character::Character(std::string const &name) {
	this->_name = name;
	this->_groundCount = 0;
	for(int i = 0; i < 4; i++) {
		this->_inventory[i] = nullptr;
	}
	for (int i = 0; i < 100; i++) {
		this->_ground[i] = nullptr;
	}
	std::cout << BOLD_ON BLUE << "Custom (Character) constructor called!" << BOLD_OFF << std::endl;
}

Character::Character(const Character &other) {
	std::cout << BOLD_ON YELLOW << "Copy (Character) constructor called!" << BOLD_OFF << std::endl;
	this->_name = other.getName();
	for(int i = 0; i < 4; i++) {
		if (other._inventory[i] != nullptr)
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = nullptr;
	}
	for (int i = 0; i < 100; i++) {
		if (other._ground[i] != nullptr)
			this->_ground[i] = other._ground[i]->clone();
		else
		 	this->_ground[i] = nullptr;
	}
}

Character &Character::operator=(const Character &other) {
	if (this != &other) {
	this->_name = other.getName();
	for(int i = 0; i < 4; i++) {
		if (other._inventory[i] != nullptr)
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = nullptr;
		}
	}
	for (int i = 0; i < 100; i++) {
		if (other._ground[i] != nullptr)
			this->_ground[i] = other._ground[i]->clone();
		else
		 	this->_ground[i] = nullptr;
	}
	return (*this);
	std::cout << BOLD_ON YELLOW << "Copy (Character) assigment called!" << BOLD_OFF << std::endl;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i] != nullptr)
			delete this->_inventory[i];
	for (int i = 0; i < this->_groundCount; i++) {
		delete this->_ground[i];
	}
	std::cout << BOLD_ON RED << "Destructor (Character) called!" << BOLD_OFF << std::endl;
}

/*---------------------------------------------------------FUNCTIONS----------------------------------------------------------------------*/

void	place_on_ground(AMateria* ground[], int &ground_count, AMateria* unequiped) {
	if (ground_count < 100) {
		ground[ground_count] = unequiped;
		ground_count++;
		std::cout << BOLD_ON GREEN << "Materia unequipped and placed on the ground!" << BOLD_OFF << std::endl;
	}
	else {
		for (int i = 0; i < 100; i++) {
			if (ground[i] != nullptr) {
				delete ground[i];
				ground[i] = nullptr;
			}
		}
	}
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == nullptr) {
			this->_inventory[i] = m;
			break;
		}
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3) {
		std::cout << BOLD_ON RED << "Wrong idx!" << BOLD_OFF << std::endl;
		return;
	}
	if (this->_inventory[idx]->getType() == "ice") {
		std::cout << BOLD_ON BLUE << this->_name << BOLD_OFF << " shoots an ice bolt at " << BOLD_ON << target.getName() << BOLD_OFF << std::endl;
		delete this->_inventory[idx];
	}
	else if (this->_inventory[idx]->getType() == "cure") {
		std::cout << BOLD_ON BLUE << this->_name << BOLD_OFF << " heals " << BOLD_ON << target.getName() << BOLD_OFF << "’s wound" << std::endl;
		delete this->_inventory[idx];
	}
	else {
		std::cout << BOLD_ON RED << "Wrong type!" << BOLD_OFF << std::endl;
		return;
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		std::cout << BOLD_ON RED << "Wrong idx!" << BOLD_OFF << std::endl;
		return;
	}
	
}
