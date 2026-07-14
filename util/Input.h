/*
Author: Sander Sierra
Input validation utilities using templates to avoid code duplication and
support a wide range of numeric data types. Only numeric types are supported.

Example usage:

    cout << "Enter an integer:\n";
    int input_opt = input_func<long int>();
    cout << input_opt;

    cout << "\nEnter a positive number:\n";
    int input_pos = input_func<unsigned long long int>();
    cout << input_pos;

    cout << "\nEnter a floating point number:\n";
    double input_f_opt = input_func<long double>();
    cout << input_f_opt;
*/
#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <iostream>
#include <string>
#include <type_traits>

using namespace std;

// Removes trailing spaces from a string passed by reference.
inline void remove_trailing_spaces(string &targetString) {
  int no_space_index = targetString.length() - 1;

  // Move the index to the left as long as there are spaces.
  while (no_space_index >= 0 && targetString[no_space_index] == ' ') {
    no_space_index--;
  }

  // Erase from the last non-space index + 1 to the end.
  targetString.erase(no_space_index + 1);
}

// Removes leading spaces from a string passed by reference.
inline void remove_leading_spaces(string &targetString) {
  int no_space_index = 0;

  // Move the index to the right as long as there are spaces.
  while (no_space_index >= 0 && no_space_index < (int)targetString.length() &&
         targetString[no_space_index] == ' ') {
    no_space_index++;
  }

  // Erase from position 0 up to the last leading space index.
  targetString.erase(0, no_space_index);
}

// Receives a string and a dummy value of any type used to differentiate the
// target data type. This function is designed to validate numeric types such
// as float and int, including unsigned modifiers. Returns true if valid,
// otherwise false.
template <typename T> bool validate(const string &refString, T dummy) {
  bool has_decimal_point = false; // Prohibits more than one decimal point.
  int indx_resp = -1;             // Starts from 0.

  for (const char letter : refString) {
    indx_resp++;

    if (letter == '-') {
      if (indx_resp > 0) {
        cout << "[Error] The '-' sign can only appear once at the beginning.\n";
        return false;
      }

      if (refString.length() == 1) {
        cout << "[Error] The '-' sign must be followed by at least one digit.\n";
        return false;
      }

      // is_unsigned verifies whether the type is unsigned. Use ::value to get
      // the boolean result when used in a condition.
      if (is_unsigned<T>::value) {
        cout << "[Error] Negative numbers are not allowed.\n";
        return false;
      }

      continue; // Already known to be '-', skip the rest of the checks.
    }

    if (letter == '.') {
      // is_floating_point verifies whether the type is floating point
      // (i.e. float or double).
      if (!is_floating_point<T>::value) {
        cout << "[Error] Decimal points are not allowed.\n";
        return false;
      }

      if (indx_resp == 0) {
        cout << "[Error] The decimal point cannot be at the beginning.\n";
        return false;
      }
      if (indx_resp == refString.length() - 1) {
        cout << "[Error] The decimal point cannot be at the end.\n";
        return false;
      }
      if (has_decimal_point) {
        cout << "[Error] There cannot be more than one decimal point.\n";
        return false;
      }

      has_decimal_point = true; // The decimal point is valid.

      continue;
    }

    // isdigit validates whether the char is a digit from 0 to 9.
    if (!isdigit(letter)) {
      cout << "[Error] Only numbers are allowed.\n";
      return false;
    }
  }

  return true;
}

// Takes no arguments. Prompts the user for input and validates it. Returns the
// user input once valid; retries indefinitely on invalid input.
// Usage: type var = input_func<type>();
template <typename T> T input_func() {
  string input_user;
  T output;

  do {
    cout << ">> ";
    getline(cin >> ws, input_user);
    remove_trailing_spaces(input_user);

    // Uses the validate function. output is passed only to deduce the type;
    // its value is not modified.
    if (!validate(input_user, output))
      continue;

    // Depending on the data type, a different conversion function is used to
    // transform the string into that type. The largest-capacity conversion is
    // used. A try-catch prevents the program from crashing and reports any
    // error instead.
    try {
      if (is_floating_point<T>::value) {
        output = stold(input_user); // string to long double
      } else if (is_integral<T>::value) {
        // is_integral checks whether the type is part of the set that
        // includes numeric data types.
        if (is_unsigned<T>::value) {
          output = stoull(input_user); // string to unsigned long long
        } else {
          output = stoll(input_user);  // string to long long
        }
      }
      break;
    } catch (const std::out_of_range &) {
      cout << "[Error] The value is out of range for the requested type.\n";
    } catch (...) {
      cout << "[Error] An error occurred while converting the type. Please "
              "try again.\n";
    }
  } while (true);

  return output;
}

// Reads a value of type T and ensures it falls within [min, max] (inclusive).
template <typename T> T input_between(T minimo, T maximo) {
  T num;

  do {
    num = input_func<T>();

    if (num < minimo || num > maximo)
      cout << "Enter a number between " << minimo << " and " << maximo
           << " (inclusive).\n";
    else
      break;
  } while (true);

  return num;
}

#endif
