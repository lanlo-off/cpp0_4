#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <unistd.h>


int main()
{
	std::srand(std::time(NULL));//genere une "seed" de rand par ms car rand sinon renvoie la meme suite a chaque fois
	
	try
    {
        std::cout << "===== CREATION DES BUREAUCRATS =====" << std::endl;

        Bureaucrat high("Boss", 1);
        Bureaucrat mid("Manager", 50);
        Bureaucrat low("Intern", 150);
        // Bureaucrat wrong("Wrong", 0);

        std::cout << high << std::endl;
        std::cout << mid << std::endl;
        std::cout << low << std::endl;

        std::cout << "\n===== TEST SHRUBBERY =====" << std::endl;

        ShrubberyCreationForm shrub("home");

        low.signForm(shrub);// devrait échouer
        mid.signForm(shrub);// devrait réussir
        mid.executeForm(shrub);// devrait réussir

        std::cout << "\n===== TEST ROBOTOMY =====" << std::endl;

        RobotomyRequestForm robot("Bender");

        mid.signForm(robot);// devrait réussir
        mid.executeForm(robot);// devrait echouer
        high.executeForm(robot);// devrait réussir (50% succès)
		std::cout << "\n===== BOUCLE ROBOTOMY =====" << std::endl;
		for (int i = 0; i < 10; i++)
		{
			high.executeForm(robot);
			std::cout << "\n";
		}
        std::cout << "\n===== TEST PRESIDENTIAL =====" << std::endl;

        PresidentialPardonForm pardon("Arthur Dent");

        mid.signForm(pardon);// devrait échouer
        high.signForm(pardon);// devrait réussir
        mid.executeForm(pardon);// devrait échouer
        high.executeForm(pardon);// devrait réussir

        std::cout << "\n===== TEST FORM NON SIGNE =====" << std::endl;

        ShrubberyCreationForm test("garden");
        high.executeForm(test);// doit throw car non signé
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	return 0;
}
