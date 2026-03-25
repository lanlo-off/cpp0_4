#include "Array.hpp"

template<typename T>
Array<T>::Array() : _elements(0), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int const n) : _size(n)
{
	if (_size)
		_elements = new T[_size]();
	else
		_elements = NULL;
}

template<typename T>
Array<T>::Array(const Array& other) : _size(other._size)
{
	if (_size)
	{
		_elements = new T[_size];
		for (size_t i = 0; i < _size; i++){
			try {
				_elements[i] = other._elements[i];
			}
			catch (std::exception& e) {
				delete [] _elements;
				std::cerr << e.what() << std::endl;
				throw ;
			}
		}
	}
	else
		_elements = NULL;
}

template<typename T>
Array<T>::~Array() {
	delete [] _elements;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		if (_size)
			delete [] _elements;
		_size = other._size;
		if (_size)
		{
			_elements = new T[_size];
			for (size_t i = 0; i < _size; i++) {
				try {
					_elements[i] = other._elements[i];
				}
				catch (std::exception& e) {
					delete [] _elements;
					std::cerr << e.what() << std::endl;
					throw ;
				}
			}
		}
		else
			_elements = NULL;
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](size_t const& index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return (_elements[index]);
}

template<typename T>
T const& Array<T>::operator[](size_t const& index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return (_elements[index]);
}

template<typename T>
size_t Array<T>::size() const
{
	return (_size);
}

template<typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index not in the array\n");
}