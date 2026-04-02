/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbsolutelyNotAVector.tpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubois <ldubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:13:16 by ldubois           #+#    #+#             */
/*   Updated: 2026/03/16 20:38:26 by ldubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSOLUTELYNOTAVECTOR_TPP

#define ABSOLUTELYNOTAVECTOR_TPP

template <typename T>
AbsolutelyNotAVector<T>::AbsolutelyNotAVector(void)
	: _size(0), _capacity(0), _ptr(0)
{
}

template <typename T>
AbsolutelyNotAVector<T>::AbsolutelyNotAVector(std::size_t n)
	: _size(n), _capacity(n), _ptr(n ? new T[n]() : 0)
{
}

template <typename T>
AbsolutelyNotAVector<T>::AbsolutelyNotAVector(
		const AbsolutelyNotAVector<T>& other)
	: _size(other._size), _capacity(other._capacity),
	  _ptr(other._capacity ? new T[other._capacity] : 0)
{
	for (std::size_t i = 0; i < _size; ++i)
		_ptr[i] = other._ptr[i];
}

template <typename T>
AbsolutelyNotAVector<T>& AbsolutelyNotAVector<T>::operator=(
		const AbsolutelyNotAVector<T>& rhs)
{
	if (this != &rhs)
	{
		T* copy = rhs._capacity ? new T[rhs._capacity] : 0;
		try
		{
			for (std::size_t i = 0; i < rhs._size; ++i)
				copy[i] = rhs._ptr[i];
		}
		catch (...)
		{
			delete[] copy;
			throw;
		}
		delete[] _ptr;
		_ptr = copy;
		_size = rhs._size;
		_capacity = rhs._capacity;
	}
	return *this;
}

template <typename T> AbsolutelyNotAVector<T>::~AbsolutelyNotAVector(void)
{
	delete[] _ptr;
}

template <typename T> std::size_t AbsolutelyNotAVector<T>::size(void) const
{
	return _size;
}

template <typename T> void AbsolutelyNotAVector<T>::grow(void)
{
	const std::size_t n = (_capacity ? _capacity * 2 : 1);

	T* storage = new T[n];
	try
	{
		for (std::size_t i = 0; i < _size; ++i)
			storage[i] = _ptr[i];
	}
	catch (...)
	{
		delete[] storage;
		throw;
	}
	delete[] _ptr;
	_ptr = storage;
	_capacity = n;
}

template <typename T> void AbsolutelyNotAVector<T>::push_back(const T& element)
{
	if (_size == _capacity)
		grow();
	_ptr[_size++] = element;
}

template <typename T> T& AbsolutelyNotAVector<T>::operator[](std::size_t n)
{
	return _ptr[n];
}

template <typename T>
const T& AbsolutelyNotAVector<T>::operator[](std::size_t n) const
{
	return _ptr[n];
}

#endif
