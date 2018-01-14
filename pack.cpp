#include "header.hpp"

using namespace YAML;

void GetData(Person &st)
{
  std::cout << "Enter data to fields of the Person structure.\n";
  std::cout << "First name:\n";
  std::cin >> st.first_name;

  std::cout << "Last name\n";
  std::cin >> st.last_name;

  std::string email;
  std::cout << "Email:\n";
  std::cin >> email;

  int ind = email.find('@');
  std::string name(email.begin(), email.begin()+ind);
  st.email.nickname = name;

  std::string serve(email.begin()+ind+1, email.end());
  st.email.server = serve;

  std::cout << "Age\n";
  std::cin >> st.age;

  std::string fake;
  std::cout << "Phone\n";
  std::getline(std::cin, fake);
  std::getline(std::cin, st.phone);

}

void SaveFile(const Person &st, const char *path)
{
  std::ofstream file(path);
  Emitter out;
  out << BeginMap;
  out << Key << "person";
  out << BeginMap;
  out << Key << "firstname" << Value << st.first_name;
  out << Key << "lastname" << Value << st.last_name;
  out << Key << "email";
  std::string email(st.email.nickname);
  email += '@';
  email += st.email.server;
  out << Value << email;
  out << Key << "age" << Value << st.age;
  out << Key << "phone" << Value << st.phone;
  out << EndMap;
  out << EndMap;
  out << Newline;

  file << out.c_str();
  file.close();
}


int main(int argc, char* argv[])
{
   char* pathfile = argv[1];

   Person student;
   GetData(student);

   SaveFile(student, pathfile);
   return 0;
}
