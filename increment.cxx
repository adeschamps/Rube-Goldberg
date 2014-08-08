#include "increment.hxx"

#include "numeric_representation.hxx"

#include <fstream>

namespace ad
{
  void increment (int & number)
  {
    std::string command ("./get-next \"" + ad::int_to_string(number) + "\"");
    system (command.c_str());
    std::ifstream infile ("result_file");
    infile >> number;
  }
}
