/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:21:44 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/15 17:43:51 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "colors.hpp"

int main() {
	std::cout << BOLD_ON << "----------CREATION AND CLONING MATERIAS------------" << BOLD_OFF << std::endl << std::endl;
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	AMateria* iceD = new Ice();
	AMateria* cureD = new Cure();

	std::cout << "Original Ice type: " << ice->getType() << ", Address: " << ice << std::endl;
	std::cout << "Original Cure type: " << cure->getType() << ", Address: " << cure << std::endl;
	std::cout << "Original IceD type: " << iceD->getType() << ", Address: " << iceD << std::endl;
	std::cout << "Original CureD type: " << cureD->getType() << ", Address: " << cureD << std::endl;
	
	AMateria* iceClone = ice->clone();
	AMateria* cureClone = cure->clone();
	AMateria* iceCloneD = iceD->clone();
	AMateria* cureCloneD = cureD->clone();

	std::cout << "Cloned Ice type: " << iceClone->getType() << ", Address: " << iceClone << std::endl;
	std::cout << "Cloned Cure type: " << cureClone->getType() << ", Address: " << cureClone << std::endl;
	std::cout << "Cloned IceD type: " << iceCloneD->getType() << ", Address: " << iceCloneD << std::endl;
	std::cout << "Cloned CureD type: " << cureCloneD->getType() << ", Address: " << cureCloneD << std::endl;

	std::cout << std::endl << BOLD_ON << "----------CHARCTERS CREATION------------" << BOLD_OFF << std::endl << std::endl;
	Character character("Hero");
	Character character1("Dragon");

	std::cout << std::endl << BOLD_ON << "----------EQUIP FUNCTION------------" << BOLD_OFF << std::endl << std::endl;
	character.equip(ice);
	character.equip(cure);
	character1.equip(iceD);
	character1.equip(cureD);

	std::cout << "After equipping Ice and Cure:" << std::endl;
	character.displayInventory();
	character1.displayInventory();
	
	std::cout << std::endl << BOLD_ON << "----------USE FUNCTION------------" << BOLD_OFF << std::endl << std::endl;
	ice->use(character1);
	cureCloneD->use(character);
	character.use(0, character1);
	character1.use(1, character);

	std::cout << std::endl << BOLD_ON << "----------UNEQUIP FUNCTION------------" << BOLD_OFF << std::endl << std::endl;
	character.unequip(1);
	character1.unequip(1);
	std::cout << "After unequip:" << std::endl;
	character.displayInventory();
	character.displayGround();
	character1.displayInventory();
	character1.displayGround();
	
	std::cout << std::endl << BOLD_ON << "----------EQUIP CLONED MATERIA FUNCTION------------" << BOLD_OFF << std::endl << std::endl;
	character.equip(iceClone);
	character.equip(cureClone);
	character1.equip(iceCloneD);
	character1.equip(cureCloneD);
	std::cout << "After equipping cloned Ice and Cure:" << std::endl;
	character.displayInventory();
	character1.displayInventory();

	std::cout << std::endl << BOLD_ON << "----------IMATERIA CREATION - NEW MATERIAS------------" << BOLD_OFF << std::endl << std::endl;
	IMateriaSource* source = new MateriaSource();
	AMateria* iceTest = new Ice();
	AMateria* cureTest = new Cure();
	AMateria* iceTest1 = new Ice();
	AMateria* cureTest1 = new Cure();
	AMateria* cureTest2 = new Cure();
	
	std::cout << std::endl << BOLD_ON << "----------LEARN FUNCTION------------" << BOLD_OFF << std::endl << std::endl;
	source->learnMateria(iceTest);
	source->learnMateria(cureTest);
	source->learnMateria(iceTest1);
	source->learnMateria(cureTest1);
	source->learnMateria(cureTest2);
	
	std::cout << std::endl << BOLD_ON << "----------CREATE FUNCTION------------" << BOLD_OFF << std::endl << std::endl;
	AMateria* newIce = source->createMateria("ice 🧊");
	if (newIce) {
		std::cout << "Created Materia: " << newIce->getType() << std::endl;
		delete newIce;
	}

	AMateria* newCure = source->createMateria("cure 💊");
	if (newCure) {
		std::cout << "Created Materia: " << newCure->getType() << std::endl;
		delete newCure;
	}

	AMateria* random = source->createMateria("fire");
	if (random) {
		std::cout << "Created Materia: " << random->getType() << std::endl;
		delete random;
	}

	delete iceTest;
	delete cureTest;
	delete iceTest1;
	delete cureTest1;
	delete cureTest2;
	delete source;

	return 0;
}
