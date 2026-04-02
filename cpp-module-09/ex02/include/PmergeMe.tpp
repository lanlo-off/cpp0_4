/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubois <ldubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:51:07 by ldubois           #+#    #+#             */
/*   Updated: 2026/03/16 20:57:21 by ldubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP

#define PMERGEME_TPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <deque>
#include <ctime>

template <typename C> struct ContainerName;

template <typename T, typename Alloc>
struct ContainerName<std::vector<T, Alloc> >
{
		static const char* name() { return "std::vector"; }
};

template <typename T, typename Alloc>
struct ContainerName<std::deque<T, Alloc> >
{
		static const char* name() { return "std::deque"; }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& rhs)
{
	for (typename std::vector<T>::const_iterator it = rhs.begin();
		 it != rhs.end(); ++it)
		out << (it != rhs.begin() ? " " : "") << +*it;
	return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::deque<T>& rhs)
{
	for (typename std::deque<T>::const_iterator it = rhs.begin();
		 it != rhs.end(); ++it)
		out << (it != rhs.begin() ? " " : "") << +*it;
	return out;
}

template <template <class, class> class C, class T>
PmergeMe<C, T>::PmergeMe(void)
{
}

template <template <class, class> class C, class T>
PmergeMe<C, T>::PmergeMe(const PmergeMe& other)
{
	(void)other;
}

template <template <class, class> class C, class T>
PmergeMe<C, T>& PmergeMe<C, T>::operator=(const PmergeMe<C, T>& rhs)
{
	(void)rhs;
	return *this;
}

template <template <class, class> class C, class T>
PmergeMe<C, T>::~PmergeMe(void)
{
}

template <template <class, class> class C, class T>
typename PmergeMe<C, T>::container_type PmergeMe<C, T>::parseSequence(
		const char* const* args, const std::size_t size)
{
	container_type sequence;
	char*		   end;

	for (std::size_t i = 0; i < size; ++i)
	{
		unsigned long value = std::strtoul(args[i], &end, 10);
		if (end == args[i] || *end
			|| value > static_cast<unsigned long>(
					   std::numeric_limits<T>::max()))
			throw std::runtime_error("'" + std::string(args[i])
									 + "' is not a valid number");
		if (!std::numeric_limits<T>::is_integer
			|| std::numeric_limits<T>::is_signed)
			throw std::runtime_error(
					"storage type is either non-integer or signed");
		sequence.push_back(static_cast<T>(value));
	}
	if (sequence.empty())
		throw std::runtime_error("empty sequence");
	return sequence;
}

template <template <class, class> class C, class T>
typename PmergeMe<C, T>::container_type PmergeMe<C, T>::parseSequence(
		const std::string& args)
{
	std::istringstream ss(args);
	container_type	   sequence;
	std::string		   token;
	char*			   end;

	while (ss >> token)
	{
		unsigned long value = std::strtoul(token.c_str(), &end, 10);
		if (end == token.c_str() || *end
			|| value > static_cast<unsigned long>(
					   std::numeric_limits<T>::max()))
			throw std::runtime_error("'" + token + "' is not a valid number");
		if (!std::numeric_limits<T>::is_integer
			|| std::numeric_limits<T>::is_signed)
			throw std::runtime_error(
					"storage type is either non-integer or signed");
		sequence.push_back(static_cast<T>(value));
	}
	if (sequence.empty())
		throw std::runtime_error("empty sequence");
	return sequence;
}

template <template <class, class> class C>
C<std::size_t, std::allocator<std::size_t> > jacobsthalSet(std::size_t n)
{
	C<std::size_t, std::allocator<std::size_t> > set;

	if (!n)
		return set;
	set.push_back(1);
	for (std::size_t prev = 1, current = 3, next; prev < n;)
	{
		std::size_t k = (current < n ? current : n);
		for (std::size_t i = k; i > prev; --i)
			set.push_back(i);
		next = current + 2 * prev;
		prev = current;
		current = next;
	}
	return set;
}

template <template <class, class> class C, class T>
void PmergeMe<C, T>::sortSequence(
		typename PmergeMe<C, T>::container_type& sequence)
{
	pair_container pairs;
	container_type sorted;
	const_iterator start = sequence.begin();
	bool		   has_unique = false;
	T			   unique;

	if (sequence.size() <= 1)
		return;
	for (const_iterator it = start; it != sequence.end(); ++it)
	{
		const T& first = *it++;
		if (it == sequence.end())
		{
			has_unique = true;
			unique = first;
			break;
		}
		const T& second = *it;
		bool	 ordered = first < second;
		pairs.push_back(std::make_pair(ordered ? first : second,
									   ordered ? second : first));
	}
	for (const_pair_iterator it = pairs.begin(); it != pairs.end(); ++it)
		sorted.push_back(it->second);
	sortSequence(sorted);
	if (!pairs.empty())
	{
		for (pair_iterator it = pairs.begin(); it != pairs.end(); ++it)
		{
			if (it->second == *sorted.begin())
			{
				std::iter_swap(pairs.begin(), it);
				break;
			}
		}
		sorted.insert(sorted.begin(), pairs.begin()->first);
	}
	const C<std::size_t, std::allocator<std::size_t> > order
			= jacobsthalSet<C>(pairs.size());
	for (typename C<std::size_t, std::allocator<std::size_t> >::const_iterator
				 it
		 = ++order.begin();
		 it != order.end(); ++it)
	{
		std::size_t i = *it - 1;
		const T&	a_i = pairs[i].first;
		const T&	b_i = pairs[i].second;
		iterator	limit = std::lower_bound(sorted.begin(), sorted.end(), b_i);
		iterator	pos = std::lower_bound(sorted.begin(), limit, a_i);
		sorted.insert(pos, a_i);
	}
	if (has_unique)
		sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), unique),
					  unique);
	sequence.swap(sorted);
}

template <template <class, class> class C, class T>
void PmergeMe<C, T>::benchSort(const std::size_t k)
{
	container_type random;

	for (std::size_t i = 0; i < k; ++i)
		random.push_back(static_cast<T>(std::rand()));
	clock_t start = clock();
	sortSequence(random);
	clock_t end = clock();
	double	elapsed
			= static_cast<double>(end - start) * 1000000 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << k << " elements with "
			  << std::left << std::setw(11)
			  << ContainerName<container_type>::name() << " : " << elapsed
			  << " μs\n";
}

#endif
