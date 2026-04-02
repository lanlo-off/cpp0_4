/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbsolutelyNotAVector.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubois <ldubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:09:03 by ldubois           #+#    #+#             */
/*   Updated: 2026/03/16 20:38:35 by ldubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSOLUTELYNOTAVECTOR_HPP

#define ABSOLUTELYNOTAVECTOR_HPP

template <typename T> class AbsolutelyNotAVector
{
	private:
		std::size_t _size;
		std::size_t _capacity;
		T*			_ptr;

		void grow();

	public:
		AbsolutelyNotAVector();
		explicit AbsolutelyNotAVector(std::size_t n);
		AbsolutelyNotAVector(const AbsolutelyNotAVector& other);
		AbsolutelyNotAVector& operator=(const AbsolutelyNotAVector& rhs);
		~AbsolutelyNotAVector();

		std::size_t size() const;
		void		push_back(const T& element);

		T&		 operator[](std::size_t n);
		const T& operator[](std::size_t n) const;
};

#include "AbsolutelyNotAVector.tpp"

#endif
