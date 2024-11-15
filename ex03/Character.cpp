/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:51:27 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/15 16:53:55 by cyferrei         ###   ########.fr       */
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
		this->_inventory[i] = 0;
	}
	for (int i = 0; i < 100; i++) {
		this->_ground[i] = 0;
	}
	std::cout << BOLD_ON GREEN << "Default (Character) constructor called!" << BOLD_OFF << std::endl;
}

Character::Character(std::string const &name) {
	this->_name = name;
	this->_groundCount = 0;
	for(int i = 0; i < 4; i++) {
		this->_inventory[i] = 0;
	}
	for (int i = 0; i < 100; i++) {
		this->_ground[i] = 0;
	}
	std::cout << BOLD_ON BLUE << "Custom (Character) constructor called!" << BOLD_OFF << std::endl;
}

Character::Character(const Character &other) {
	std::cout << BOLD_ON YELLOW << "Copy (Character) constructor called!" << BOLD_OFF << std::endl;
	this->_name = other.getName();
	for(int i = 0; i < 4; i++) {
		if (other._inventory[i] != 0)
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = 0;
	}
	for (int i = 0; i < 100; i++) {
		if (other._ground[i] != 0)
			this->_ground[i] = other._ground[i]->clone();
		else
		 	this->_ground[i] = 0;
	}
}

Character &Character::operator=(const Character &other) {
	if (this != &other) {
	this->_name = other.getName();
	for(int i = 0; i < 4; i++) {
		if (other._inventory[i] != 0)
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = 0;
		}
	}
	for (int i = 0; i < 100; i++) {
		if (other._ground[i] != 0)
			this->_ground[i] = other._ground[i]->clone();
		else
		 	this->_ground[i] = 0;
	}
	return (*this);
	std::cout << BOLD_ON YELLOW << "Copy (Character) assigment called!" << BOLD_OFF << std::endl;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i] != 0)
			delete this->_inventory[i];
	for (int i = 0; i < this->_groundCount; i++) {
		delete this->_ground[i];
	}
	std::cout << BOLD_ON RED << "Destructor (Character) called!" << BOLD_OFF << std::endl;
}

/*---------------------------------------------------------FUNCTIONS----------------------------------------------------------------------*/


std::string const &Character::getName()const {
	return (this->_name);
}


void Character::clearGround() {
	for (int i = 0; i < 100; i++) {
		if (this->_ground[i] != 0) {
			delete this->_ground[i];
			this->_ground[i] = 0;
		}
	}
	this->_groundCount = 0;
}


void Character::placeOnGroundUnequiped(int idx) {
	if (this->_groundCount < 100) {
		for (int i = 0; i < 100; i++) {
			if (this->_ground[i] == 0) {
				this->_ground[i] = this->_inventory[idx];
				this->_inventory[idx] = 0;
				this->_groundCount++;
				std::cout << BOLD_ON YELLOW << "Materia placed on ground (Unequipped!)" << BOLD_OFF << std::endl;
				return;
			}
		}
	}
	else
		this->clearGround();
}


void Character::placeOnGroundFull(AMateria* m) {
	if (this->_groundCount < 100) {
		for (int i = 0; i < 100; i++) {
			if (this->_ground[i] == 0) {
				this->_ground[i] = m;
				this->_groundCount++;
				std::cout << BOLD_ON YELLOW << "Materia placed on ground (No more space in the bag!)" << BOLD_OFF << std::endl;
				return;
			}
		}
	}
	else
		this->clearGround();
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == m) {
			std::cout << BOLD_ON BLUE << "Materia already in inventory!" BOLD_OFF << std::endl;
			return;
		}
		if (this->_inventory[i] == 0) {
			this->_inventory[i] = m;
			std::cout << BOLD_ON BLUE << this->getName() << BOLD_OFF << " equiped " << BOLD_ON << m->getType() << BOLD_OFF << "!" << std::endl;
			return;
		}
	}
	this->placeOnGroundFull(m);
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3) {
		std::cout << BOLD_ON RED << "Wrong idx!" << BOLD_OFF << std::endl;
		return;
	}
	if (this->_inventory[idx] == 0) {
		std::cout << BOLD_ON RED << "Nothing at this idx!" << BOLD_OFF << std::endl;
		return;
	}
	if (this->_inventory[idx]->getType() == "ice 🧊") {
		std::cout << BOLD_ON BLUE << this->_name << BOLD_OFF << " shoots an ice bolt at " << BOLD_ON << target.getName() << BOLD_OFF << std::endl;
		delete this->_inventory[idx];
		this->_inventory[idx] = 0;
	}
	else if (this->_inventory[idx]->getType() == "cure 💊") {
		std::cout << BOLD_ON BLUE << this->_name << BOLD_OFF << " heals " << BOLD_ON << target.getName() << BOLD_OFF << "’s wound" << std::endl;
		delete this->_inventory[idx];
		this->_inventory[idx] = 0;
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
	if (this->_inventory[idx] == 0) {
		std::cout << BOLD_ON RED << "Nothing at this index!" << BOLD_OFF << std::endl;
		return;
	}
	this->placeOnGroundUnequiped(idx);
}

void Character::displayInventory() const {
	std::cout << "Inventory contents:" << std::endl;
	for (int i = 0; i < 4; ++i) {
		if (this->_inventory[i] != 0) {
			std::cout << "  Slot " << i << ": " << this->_inventory[i]->getType() << " at address " << this->_inventory[i] << std::endl;
		} else
			std::cout << "  Slot " << i << ": [empty]" << std::endl;
	}
}


void Character::displayGround() const {
	std::cout << "Ground contents:" << std::endl;
	bool isEmpty = true;
	for (int i = 0; i < 100; ++i) {
		if (this->_ground[i]) {
			std::cout << "  Slot " << i << ": " << this->_ground[i]->getType() << " at address " << this->_ground[i] << std::endl;
			isEmpty = false;
		}
	}
	if (isEmpty)
		std::cout << "  [Ground is empty]" << std::endl;
}
