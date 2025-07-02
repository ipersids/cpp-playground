#include <iostream>

#include "data.hpp"
#include "Serializer.hpp"

#ifndef COLORS
#define COLORS
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"
#endif  // COLORS

int main(void) {
  std::cout << GREEN << "\n------------- INIT DATA STRUCTURE -------------"
            << RESET << std::endl;

  Data data = { 2025, 07, 03 };

  std::cout << BLUE << "\n---> Fields of data structure:" << RESET << std::endl;
  std::cout << "\t- year: " << data.year << std::endl;
  std::cout << "\t- month: " << data.month << std::endl;
  std::cout << "\t- day: " << data.day << std::endl;

  std::cout << BLUE << "\n---> Pointer to data structure:" << RESET << std::endl;
  std::cout << "\t- value: " << &data << std::endl;

  std::cout << GREEN << "\n-------------- SERIALIZE POINTER --------------"
            << RESET << std::endl;
  
  std::uintptr_t serialized_ptr = Serializer::serialize(&data);

  std::cout << BLUE << "\n---> serialized uintptr_t of data structire:" << RESET << std::endl;
  std::cout << "\t- value: " << serialized_ptr << std::endl;

  std::cout << GREEN << "\n------------- DESERIALIZE POINTER -------------" << RESET << std::endl;

  Data* deserialized_ptr = Serializer::deserialize(serialized_ptr);

  std::cout << BLUE << "\n---> deserialized Data* of data structire:" << RESET << std::endl;
  std::cout << "\t- value: " << deserialized_ptr << std::endl;

  std::cout << GREEN << "\n------ COMPARE ORIGINAL AND DESERIALIZED ------" << RESET << std::endl;

  std::cout << "\noriginal (" << &data << ") == deserialized (" << deserialized_ptr << "):" << std::endl;
  std::cout << "\t- result: " << ((&data == deserialized_ptr) ? MAGENTA"TRUE" : RED"FALSE") << RESET << std::endl;

  std::cout << BLUE << "\n---> Fields of deserialized data structure:" << RESET << std::endl;
  std::cout << "\t- year: " << deserialized_ptr->year << std::endl;
  std::cout << "\t- month: " << deserialized_ptr->month << std::endl;
  std::cout << "\t- day: " << deserialized_ptr->day << "\n" << std::endl;

  return 0;
}