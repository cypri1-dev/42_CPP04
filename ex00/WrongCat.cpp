/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:01:38 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/11 17:05:03 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*--------------------------------------------------------ORTHODOX CANONICAL FORM---------------------------------------------------------*/

WrongCat::WrongCat() {
	std::cout << BOLD_ON GREEN << "Default (WrongCat) constructor called" << BOLD_OFF << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) {
	std::cout << BOLD_ON YELLOW << "Copy (WrongCat) constructor called" << BOLD_OFF << std::endl;
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << BOLD_ON YELLOW << "Copy (WrongCat) assigment called" << BOLD_OFF <<std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << BOLD_ON RED << "Destructor (WrongCat) called" << RESET << std::endl;
}

/*-----------------------------------------------------GETTER - SETTER -----------------------------------------------------------------*/

/*---------------------------------------------------------FUNCTIONS----------------------------------------------------------------------*/

void WrongCat::makeSound()const {
	std::cout << BOLD_ON BLUE << "Miaouuuuuuu 😸" << RESET << std::endl;
}