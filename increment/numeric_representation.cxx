#include "numeric_representation.hxx"

#include <sstream>

#include <iostream>

namespace ad
{
  std::string int_to_string (int number)
  {
    std::string result;

    if (number >= 1000000)
      return int_to_string(number / 1000000) + " million " + int_to_string(number % 1000000);

    if (number >= 1000)
      return int_to_string(number / 1000) + " thousand " + int_to_string(number % 1000);

    if (number >= 100)
      return int_to_string(number / 100) + " hundred " + int_to_string(number % 100);

    // The lambda is extraneous.
    if (number >= 20)
      {
	std::string prefix = [] (int n) {
	  switch (n / 10)
	    {
	    case 2: return "twenty ";
	    case 3: return "thirty ";
	    case 4: return "forty ";
	    case 5: return "fifty ";
	    case 6: return "sixty ";
	    case 7: return "seventy ";
	    case 8: return "eighty ";
	    case 9: return "ninety ";
	    default: return "";
	    }
	}
	(number);

	return prefix + int_to_string(number % 10);
      }

    switch (number)
      {
      case 0: return "";
      case 1: return "one";
      case 2: return "two";
      case 3: return "three";
      case 4: return "four";
      case 5: return "five";
      case 6: return "six";
      case 7: return "seven";
      case 8: return "eight";
      case 9: return "nine";
      case 10: return "ten";
      case 11: return "eleven";
      case 12: return "twelve";
      case 13: return "thirteen";
      case 14: return "fourteen";
      case 15: return "fifteen";
      case 16: return "sixteen";
      case 17: return "seventeen";
      case 18: return "eighteen";
      case 19: return "nineteen";
      }

    return result;
  }

  int string_to_int (std::string number)
  {
    int result = 0;
    int result_part = 0;

    std::stringstream ss (number);

    std::string fragment;
    char c;
    bool loop_over = false;
    while (loop_over == false)
      {
	if ( ! ss.get(c))
	  loop_over = true;

	if (std::string(" -,").find(c) != std::string::npos || loop_over)
	  {
	    if (fragment == "zero") return result;
	    else if (fragment == "one")       result_part += 1;
	    else if (fragment == "two")       result_part += 2;
	    else if (fragment == "three")     result_part += 3;
	    else if (fragment == "four")      result_part += 4;
	    else if (fragment == "five")      result_part += 5;
	    else if (fragment == "six")       result_part += 6;
	    else if (fragment == "seven")     result_part += 7;
	    else if (fragment == "eight")     result_part += 8;
	    else if (fragment == "nine")      result_part += 9;
	    else if (fragment == "ten")       result_part += 10;
	    else if (fragment == "eleven")    result_part += 11;
	    else if (fragment == "twelve")    result_part += 12;
	    else if (fragment == "thirteen")  result_part += 13;
	    else if (fragment == "fourteen")  result_part += 14;
	    else if (fragment == "fifteen")   result_part += 15;
	    else if (fragment == "sixteen")   result_part += 16;
	    else if (fragment == "seventeen") result_part += 17;
	    else if (fragment == "eighteen")  result_part += 18;
	    else if (fragment == "nineteen")  result_part += 19;
	    else if (fragment == "twenty")    result_part += 20;
	    else if (fragment == "thirty")    result_part += 30;
	    else if (fragment == "forty")     result_part += 40;
	    else if (fragment == "fifty")     result_part += 50;
	    else if (fragment == "sixty")     result_part += 60;
	    else if (fragment == "seventy")   result_part += 70;
	    else if (fragment == "eighty")    result_part += 80;
	    else if (fragment == "ninety")    result_part += 90;
	    else if (fragment == "hundred")   result_part *= 100;
	    else if (fragment == "thousand")
	      {
		result += 1000 * result_part;
		result_part = 0;
	      }
	    else if (fragment == "million")
	      {
		result += 1000000 * result_part;
		result_part = 0;
	      }

	    fragment.clear();
	  }
	else
	  {
	    fragment.push_back(tolower(c));
	  }
      }

    result += result_part;
    return result;
  }
}
