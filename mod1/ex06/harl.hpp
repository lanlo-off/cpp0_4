#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl;

typedef struct Level {
	std::string	levelName;
	void	(Harl::*function)(void);
}Level;

class Harl {
private:
	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);
	
	Level	_levels[4];
	
public:
	Harl(void);
	~Harl(void);

	void	complain(std::string level);
};

#endif