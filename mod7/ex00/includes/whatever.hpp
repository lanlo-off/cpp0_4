/*1- Le template ne s'applique qu'a la declaration immediatement suivante.
On doit donc le reecrire pour chaque fonction / utilisation.
Possible de definir un template en declarant une classe juste apres.
Ce qui permet a toutes les methodes de la classe d'utiliser le template.

Lors de l'utilisation d'un template, c'est le compilateur qui genere le code pour le bon type de donnees
selon les appels fonctions effectues. C'est pour ca que les templates de fonction doivent etre declares en .hpp.
Il peut y avoir des erreurs de linkage si fait dans les .cpp.
 */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void	swap(T& a, T& b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T	min(T a, T b)
{
	return (a <= b ? a : b);
}

template<typename T>
T	max(T a, T b)
{
	return (a >= b ? a : b);
}

#endif