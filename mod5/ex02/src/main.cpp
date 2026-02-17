#include <iostream>
#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main()
{
    std::cout << "===== VALID CREATION =====" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 50);
        Form taxForm("TaxForm", 75, 50);

        std::cout << bob << std::endl;
        std::cout << taxForm << std::endl;

        bob.signForm(taxForm);
        std::cout << taxForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== GRADE TOO LOW TO SIGN =====" << std::endl;
    try
    {
        Bureaucrat jim("Jim", 150);
        Form contract("Contract", 100, 100);

        jim.signForm(contract);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== FORM GRADE TOO HIGH =====" << std::endl;
    try
    {
        Form invalidForm("Invalid", 0, 50);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cerr << "\n===== FORM GRADE TOO LOW =====" << std::endl;
    try
    {
        Form invalidForm("Invalid", 151, 50);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== BUREAUCRAT GRADE TOO HIGH =====" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== BUREAUCRAT GRADE TOO LOW =====" << std::endl;
    try
    {
        Bureaucrat intern("Intern", 151);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== INCREMENT TEST =====" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 2);
        std::cout << alice << std::endl;

        ++alice;
        std::cout << alice << std::endl;

        ++alice;//Exception too high
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
