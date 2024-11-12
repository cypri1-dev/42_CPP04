/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:56:03 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/12 17:43:49 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
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
		delete animals[i];
	}
	
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete i;
		delete j;
	}
	
	const Dog* Olaf = new Dog;
	Olaf->setIdeasDog("I wanna bone!", 0);
	std::cout << Olaf->getIdeasDog(0) << std::endl;
	Olaf->setIdeasDog("I wanna BIG bone!", 0);
	std::cout << Olaf->getIdeasDog(0) << std::endl;
	delete Olaf;

	/*deep copy*/

	const Dog doggo1;
	doggo1.setIdeasDog("Woauf", 0);
	std::cout << doggo1.getIdeasDog(0) << std::endl;
	{
		const Dog doggo2 = doggo1;
		std::cout << doggo2.getIdeasDog(0) << std::endl;
		doggo2.setIdeasDog("MOuaff", 0);
		std::cout << doggo1.getIdeasDog(0) << std::endl;
		std::cout << doggo2.getIdeasDog(0) << std::endl;
	}
	std::cout << doggo1.getIdeasDog(0) << std::endl;
	return 0;
}