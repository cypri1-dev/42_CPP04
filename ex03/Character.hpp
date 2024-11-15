/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:51:29 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/15 13:30:35 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		AMateria* _inventory[4];
		std::string _name;
		AMateria* _ground[100];
		int _groundCount;
	public:
		Character();
		Character(std::string const &name);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();

		std::string const &getName()const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
		void placeOnGroundFull(AMateria *m);
		void placeOnGroundUnequiped(int idx);
		void clearGround();
		void displayInventory() const;
		void displayGround() const;
};

#endif