/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:56:03 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/11 17:33:36 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;
	}
	
	{
	const WrongAnimal* wrong = new WrongAnimal;
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrong->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	wrong->makeSound();
	wrongCat->makeSound();
	delete wrong;
	delete wrongCat;
	}
	return (0);
}