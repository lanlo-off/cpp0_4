#include "../includes/iter.hpp"

int main()
{
	std::cout << "===== TEST INT =====" << std::endl;
	int intArray[] = {1, 42, -5, 10};
	size_t intSize = sizeof(intArray) / sizeof(int);

	iter(intArray, intSize, printElement);//Possible de rajouter <int> apres printElement pour preciser qu'on force la version de printElement sur les int dans ce cas
	std::cout << std::endl;

	iter(intArray, intSize, printElement<int>);//Possible de rajouter <int> apres printElement pour preciser qu'on force la version de printElement sur les int dans ce cas
	std::cout << std::endl;

	iter(intArray, intSize, compareWith42);
	std::cout << std::endl;

	iter(intArray, intSize, greaterThanZero);
	std::cout << std::endl << std::endl;


	std::cout << "===== TEST DOUBLE =====" << std::endl;
	double doubleArray[] = {0.5, 42.0, -1.1};
	size_t doubleSize = sizeof(doubleArray) / sizeof(double);

	iter(doubleArray, doubleSize, printElement);
	std::cout << std::endl;

	iter(doubleArray, doubleSize, compareWith42);
	std::cout << std::endl;

	iter(doubleArray, doubleSize, greaterThanZero);
	std::cout << std::endl << std::endl;


	std::cout << "===== TEST STRING =====" << std::endl;
	std::string strArray[] = {"hello", "world"};
	size_t strSize = sizeof(strArray) / sizeof(std::string);

	iter(strArray, strSize, printElement);
	std::cout << std::endl << std::endl;

	/*les autres fonctions ne compilent pas avec les strings a cause du static_cast<string>(42) dedans qui n'existe pas*/
	return (0);
}

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   const int len = 5;

//   iter( tab, len, print<const int> );
//   iter( tab2, len, print<Awesome> );

//   return 0;
// }