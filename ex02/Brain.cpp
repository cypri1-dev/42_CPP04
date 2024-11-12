/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:29:59 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/12 15:37:56 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"

/*--------------------------------------------------------ORTHODOX CANONICAL FORM---------------------------------------------------------*/

Brain::Brain() {
	std::cout << BOLD_ON GREEN << "Default (Brain) constructor called!" << BOLD_OFF << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << BOLD_ON YELLOW << "Copy constructor (Brain) called!" << BOLD_OFF << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = other.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << BOLD_ON YELLOW << "Copy assigment (Brain) called!" << BOLD_OFF << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << BOLD_ON RED << "Destructor (Brain) called!" << BOLD_OFF << std::endl;
}

/*-----------------------------------------------------GETTER - SETTER -----------------------------------------------------------------*/

void Brain::setIdeasBrain(std::string str, unsigned int idx) {
	this->ideas[idx] = str;
}
std::string Brain::getIdeasBrain(unsigned int idx)const {
	return (this->ideas[idx]);
}