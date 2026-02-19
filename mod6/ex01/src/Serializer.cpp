#include "../includes/Serializer.hpp"
/**
 * @brief Reinterpret_cast ne convertit pas la donnee.
 * Il garde les memes bits mais sous un autre type.
 * Static_cast ne marche pas car le compilateur ne trouve pas de "convertisseur adapte aux 2 types"
 * 
 * @param ptr 
 * @return uintptr_t 
 */
uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *ptr = reinterpret_cast<Data*>(raw);
	return (ptr);
}
