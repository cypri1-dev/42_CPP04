/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:21:44 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/14 14:20:36 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"


int main() {
	// Création des objets originaux
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();

	// Affiche les types des objets originaux
	std::cout << "Original Ice type: " << ice->getType() << ", Address: " << ice << std::endl;
	std::cout << "Original Cure type: " << cure->getType() << ", Address: " << cure << std::endl;

	// Clone les objets Ice et Cure
	AMateria* iceClone = ice->clone();
	AMateria* cureClone = cure->clone();

	// Affiche les types des clones pour vérifier le clonage
	std::cout << "Cloned Ice type: " << iceClone->getType() << ", Address: " << iceClone << std::endl;
	std::cout << "Cloned Cure type: " << cureClone->getType() << ", Address: " << cureClone << std::endl;

	// Gestion de la mémoire : suppression des objets
	delete ice;
	delete cure;
	delete iceClone;
	delete cureClone;

	return 0;
}
