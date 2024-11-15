/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:21:44 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/15 15:48:47 by cyferrei         ###   ########.fr       */
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
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();

	std::cout << "Original Ice type: " << ice->getType() << ", Address: " << ice << std::endl;
	std::cout << "Original Cure type: " << cure->getType() << ", Address: " << cure << std::endl;
	
	AMateria* iceClone = ice->clone();
	AMateria* cureClone = cure->clone();

	std::cout << "Cloned Ice type: " << iceClone->getType() << ", Address: " << iceClone << std::endl;
	std::cout << "Cloned Cure type: " << cureClone->getType() << ", Address: " << cureClone << std::endl;

	Character character("Hero");
	Character character1("Dragon");

	character.equip(ice);
	character.equip(cure);

	std::cout << "After equipping Ice and Cure:" << std::endl;
	character.displayInventory();

	character.use(0, character1);
	character1.use(0, character);

	character.unequip(0);
	std::cout << "After unequipping Ice:" << std::endl;
	character.displayInventory();
	character.displayGround();

	character.equip(iceClone);
	character.equip(cureClone);
	std::cout << "After equipping cloned Ice and Cure:" << std::endl;
	character.displayInventory();

	AMateria* extra = new Ice();
	character.equip(extra);
	character.displayGround();

	IMateriaSource* source = new MateriaSource();
	AMateria* iceTest = new Ice();
	AMateria* cureTest = new Cure();
	AMateria* iceTest1 = new Ice();
	AMateria* cureTest1 = new Cure();
	AMateria* cureTest2 = new Cure();
	
	source->learnMateria(iceTest);
	source->learnMateria(cureTest);
	source->learnMateria(iceTest1);
	source->learnMateria(cureTest1);
	source->learnMateria(cureTest2);
	
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
