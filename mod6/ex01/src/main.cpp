#include "../includes/Serializer.hpp"
/**
 * @brief On declare une instance d de Data et on en fixe les param
 * On fait pointer ptr vers cette instance d
 * Puis on la transforme en uintptr avec raw
 * Et on le recupere DEPUIS RAW (point majeur) en ptr vers data dans restored ce qui prouve qu'on a bien garde la bonne adresse dans le fond
 * 
 * @return int 
 */
int main()
{
	Data d;
	d.name = "Tonton";
	d.grade = 1;
	d.preferredForm = "Abolition peine capitale";

	Data* ptr = &d;

	uintptr_t raw = Serializer::serialize(ptr);
	Data* restored = Serializer::deserialize(raw);

	std::cout << restored->name << " | " << restored->grade << " | " << restored->preferredForm << std::endl;
	return (0);
}