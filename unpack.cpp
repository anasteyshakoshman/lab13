#include "header.hpp"

using namespace YAML;

int main(int argc, char const *argv[]) 
{
  Node file = LoadFile(argv[1]);
  const Node &per = file["person"];

  std::cout << "[Person]\n";
  std::cout << "First name: " << per["firstname"].as<std::string>() << '\n';
  std::cout << "Last name: " << per["lastname"].as<std::string>() << '\n';
  std::cout << "Email: " << per["email"].as<std::string>() << '\n';
  std::cout << "Age " << per["age"].as<std::string>() << '\n';

  return 0;
}
