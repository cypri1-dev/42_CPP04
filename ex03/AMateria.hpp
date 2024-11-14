/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:17:06 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/14 15:27:58 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#pragma once

#include <string>
#include <iostream>

class AMateria {
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria();

		std::string const &getType()const; //Returns the materia type

		virtual AMateria* clone()const = 0;
		// virtual void use(ICharacter& target);
};

#endif