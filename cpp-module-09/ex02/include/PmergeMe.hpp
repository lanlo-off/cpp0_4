/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:45:58 by ldubois           #+#    #+#             */
/*   Updated: 2026/03/31 13:41:01 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP

#define PMERGEME_HPP

#include <string>
#include <memory>
#include <utility>

template <template <class, class> class C, class T> class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& rhs);
		~PmergeMe();

	public:
		typedef C<T, std::allocator<T> > container_type;
		typedef C<std::pair<T, T>, std::allocator<std::pair<T, T> > >
														pair_container;
		typedef typename container_type::iterator		iterator;
		typedef typename pair_container::iterator		pair_iterator;
		typedef typename container_type::const_iterator const_iterator;
		typedef typename pair_container::const_iterator const_pair_iterator;

		static container_type parseSequence(const char* const* args,
											const std::size_t  size);
		static container_type parseSequence(const std::string& args);
		static void			  sortSequence(container_type& sequence);
		static void			  benchSort(const std::size_t k);
};

#include "PmergeMe.tpp"

#endif
