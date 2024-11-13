/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:01:36 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/11 17:05:46 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#define BOLD_ON "\033[1m"
#define BOLD_OFF "\033[0m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"

#include <iostream>

class WrongAnimal {
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal & operator=(const WrongAnimal &other);
		virtual ~WrongAnimal();

		void makeSound()const; // no virtual here ! will refere to this function

		std::string getType()const;
};

#endif