#include "harl.hpp"

Harl::Harl(void)
{
	_levels[0].levelName = "DEBUG";
	_levels[0].function = &Harl::_debug;
	_levels[1].levelName = "INFO";
	_levels[1].function = &Harl::_info;
	_levels[2].levelName = "WARNING";
	_levels[2].function = &Harl::_warning;
	_levels[3].levelName = "ERROR";
	_levels[3].function = &Harl::_error;
}

Harl::~Harl(void)
{
	return;
}

void	Harl::_debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void	Harl::_info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void	Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n";
}

void	Harl::_error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
		if (level == _levels[i].levelName)
		{
			(this->*_levels[i].function)();
			return ;
		}
	std::cout << "Ce niveau ne correspond a aucun niveau de plainte\n";
}
