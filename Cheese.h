/*
  Name: Temitope Oladimeji Samuel Adebayo
  Date: 2023-10-05

  I have done all the coding by myself and only copied the code that my professor provided 
  to complete my workshops and assignments.
*/

#ifndef SDDS_CHEESE_H
#define SDDS_CHEESE_H

#include <iostream>

namespace sdds {
  class Cheese {
    std::string m_name = "NaC";
    unsigned m_weight{};
    double m_price{};
    std::string m_desc{};
  public:
    // default constructor 
    Cheese(){};

    // one argument constructor
    Cheese(const std::string &str);

    // a modifier that receives as a parameter a weight/amount of cheese to slice from the current cheese object.
    Cheese slice(size_t weight);

    // queries to retrieve the value of each attribute of the cheese
    std::string getName() const;
    int getWeight() const;
    double getPrice() const;
    std::string getDesc() const;

    // a function to remove the trailing and leading spaces from a string and return the string without spaces
    std::string& removeSpaces(std::string &str);

    std::ostream& display(std::ostream &os) const;
  };

  // helper functions
  std::ostream& operator<<(std::ostream &os, const Cheese &src);
}

#endif