/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:29:59 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/11 20:51:04 by cyferrei         ###   ########.fr       */
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
	*this = other;
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << BOLD_ON YELLOW << "Copy assigment (Brain) called!" << BOLD_OFF << std::endl;
}