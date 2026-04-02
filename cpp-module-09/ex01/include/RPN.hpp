/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubois <ldubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:44:36 by ldubois           #+#    #+#             */
/*   Updated: 2026/03/12 14:52:26 by ldubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP

#define RPN_HPP

#include <string>

class RPN
{
	private:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& rhs);
		~RPN();

	public:
		static int evaluate(const std::string& expression);
};

#endif
