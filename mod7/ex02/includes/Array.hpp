/*
Pour un template de classe, soit on definit directement dans la classe les fonctions (y compris constructeurs etc)
Mais pas tres clean.
Soit on ecrit en dessous dans le .hpp en reecrivant template<typename T> a chaque fonction

Soit on inclut le .tpp a la fin du header dans lequel on ecrit les fonctions avec template<typename T>

!!!!!! Il faut absolument mettre Classname<T>:: et pas seulement Classname:: !!!!!

Impossible de calculer la taille de l'array donc il faut la stocker et la faire evoluer progressivement


*/

#ifndef Array_HPP
#define Array_HPP

#include <iostream>
#include <exception>

template<typename T>
class Array
{
private:
	T* _elements;
	size_t	_size;

public:
	Array();
	Array(unsigned int const n);
	Array(const Array& other);
	~Array();

	Array& operator=(const Array& other);
	T& operator[](size_t const& index);
	T const& operator[](size_t const& index) const;

	class OutOfBoundsException: public std::exception
	{
	public:
		const char* what() const throw();
	};

	size_t size() const;
};

#include "Array.tpp"

#endif