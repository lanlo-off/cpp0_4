#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>


int main()
{
	 std::srand(std::time(NULL));

    try
    {
        Intern someRandomIntern;

        Bureaucrat boss("Boss", 1);
        Bureaucrat employee("Employee", 140);

        std::cout << "\n--- Creating Shrubbery ---\n";
        AForm* shrub = someRandomIntern.makeForm("Shrubbery form", "home");
		std::cout << *shrub;
        boss.signForm(*shrub);
        boss.executeForm(*shrub);
        delete shrub;

        std::cout << "\n--- Creating Robotomy ---\n";
        AForm* robot = someRandomIntern.makeForm("Robotomy form", "Bender");
		std::cout << *robot;
        boss.signForm(*robot);
        boss.executeForm(*robot);
        delete robot;

        std::cout << "\n--- Creating Presidential ---\n";
        AForm* presidential = someRandomIntern.makeForm("Presidential form", "Marvin");
		std::cout << *presidential;
        boss.signForm(*presidential);
        boss.executeForm(*presidential);
        delete presidential;

        std::cout << "\n--- Creating Unknown Form ---\n";
        AForm* unknown = someRandomIntern.makeForm("Unknown form", "Target");
		std::cout << *unknown;
        delete unknown;//ne sera jamais atteint car exception mais le new de make form n'est pas fait non plus !
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

	return 0;
}
