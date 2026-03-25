/*
Fonction retournant un pointeur : void *f(arg)
Pointeur vers une fonction : void (*f)(ParamType)

Plus globalement pour passer un pointeur de fonction en argument d'une fonction on fait :
void myFunc(ReturnType (*f)(ParamTypes)); = void iter(*arg1, arg2, void (*f)(arg1)) dans notre cas
 */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void	iter(T *array, size_t const& len, void (*f)(T const&))
{
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

template<typename T>
void	iter(T *array, size_t const& len, void (*f)(T&))
{
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

/* Fonctions a utiliser en guise d'argument d'iter*/
// Affichage
template <typename T>
void printElement(const T& x)
{
    std::cout << x << " ";
}

// Affichage mais
//Fonction NON-CONST T& (force la 2e surcharge)
template <typename T>
void printNonConstRef(T& x)
{
	std::cout << x << " ";
	x++;  // On peut modifier car T& est non-const
}

// Compare à une valeur donnée (via static cast)
template <typename T>
void compareWith42(const T& x)
{
	if (x == static_cast<T>(42))
		std::cout << x << " equals 42 | ";
}

// Vérifie supérieur à une valeur
template <typename T>
void greaterThanZero(const T& x)
{
	if (x > static_cast<T>(0))
		std::cout << x << " > 0 | ";
}
#endif