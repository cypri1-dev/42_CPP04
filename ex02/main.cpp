/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:56:03 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/12 17:59:43 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	const int size = 10;
	const Animal* animals[size];

	for (int i = 0; i < size; i++) {
		if (i < size / 2) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}

	for (int i = 0; i < size; i++) {
		std::cout << "Animal " << i + 1 << " : ";
		animals[i]->makeSound();
	}
	
	for (int i = 0; i < size; i++) {
		delete animals[i];
	}

	const Dog doggo1;
	doggo1.setIdeasDog("Woauf", 0);
	std::cout << "doggo1: " << doggo1.getIdeasDog(0) << std::endl;

	{
		const Dog doggo2 = doggo1;
		std::cout << "doggo2: " << doggo2.getIdeasDog(0) << std::endl;
		doggo2.setIdeasDog("MOuaff", 0);
		std::cout << "doggo1 après modification de doggo2: " << doggo1.getIdeasDog(0) << std::endl;
		std::cout << "doggo2 après modification: " << doggo2.getIdeasDog(0) << std::endl;
	}

	return 0;
}