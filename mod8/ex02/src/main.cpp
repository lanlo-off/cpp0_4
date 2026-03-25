#include "../includes/MutantStack.hpp"
#include <iostream>
#include <ctime>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "Beginning (bottom) of the stack is : " << *mstack.begin() << std::endl;
	std::cout << "End (top) of the stack is : " << mstack.top() << std::endl;
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);//Pour prouver que le copy constructeur fonctionne sur un std::stack aussi

	std::cout << "\n--- Additional copy-independence test ---" << std::endl;
	MutantStack<int> copied(mstack);
	std::cout << "original top before pop: " << mstack.top() << std::endl;
	std::cout << "copied top before pop: " << copied.top() << std::endl;
	mstack.pop();
	std::cout << "original top after pop: " << mstack.top() << std::endl;
	std::cout << "copied top after original pop (must stay unchanged): " << copied.top() << std::endl;
	std::cout << "original size: " << mstack.size() << " | copied size: " << copied.size() << std::endl;

	return 0;
}