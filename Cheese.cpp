/*
  Name: Temitope Oladimeji Samuel Adebayo
  Date: 2023-10-05

  I have done all the coding by myself and only copied the code that my professor provided 
  to complete my workshops and assignments.
*/

#include <iomanip>
#include <iostream>
#include "Cheese.h"

using namespace std;

namespace sdds {
  Cheese::Cheese(const std::string &str){
    string tempStr = str;
    string tempName{};
    string tempWeight{};
    string tempPrice{};
    string tempDesc{};

    // get the name
    tempName = tempStr.substr(0, tempStr.find(','));

    // remove the trailing and leading spaces
    tempName = removeSpaces(tempName);
    
    // remove the name from the string
    tempStr.erase(0, tempStr.find(',') + 1);

    // set the name
    m_name = tempName;

    // get the weight
    tempWeight = tempStr.substr(0, tempStr.find(','));
    tempWeight = removeSpaces(tempWeight);
    tempStr.erase(0, tempStr.find(',') + 1);

    // set the weight with the converted string to unsigned long integer
    m_weight = stoul(tempWeight);

    // get the price
    tempPrice = tempStr.substr(0, tempStr.find(','));
    tempPrice = removeSpaces(tempPrice);
    tempStr.erase(0, tempStr.find(',') + 1);

    // set the price with the converted string to double
    m_price = stod(tempPrice);

    // get the description
  
    // loop till the end of the string and add all the words to the description
    for (size_t i = 0; i < tempStr.length(); i++) {
      if (tempStr.find_first_of(',') < tempStr.length()) {
        // get the word first
        string singleStr = tempStr.substr(0, tempStr.find(','));
        // remove the trailing and leading spaces
        singleStr = removeSpaces(singleStr);
        // add the word to the description
        tempDesc += singleStr += ' ';
        // remove the word from the string
        tempStr.erase(0, tempStr.find(',') + 1);
      } else {
        // get the word first
        string singleStr = tempStr.substr(0, tempStr.length());
        // remove the trailing and leading spaces
        singleStr = removeSpaces(singleStr);
        // add the word to the description
        tempDesc += singleStr += ' ';
        // remove the word from the string
        tempStr.erase(0, tempStr.length());
      }
    }

    // set the description
    m_desc = tempDesc;
  }

  Cheese Cheese::slice(size_t weight){
    if (weight <= m_weight) {
      // create a copy of the current cheese object
      Cheese cheese = *this;

      // update the weight of the copy
      cheese.m_weight = weight;

      // update the weight of the current object
      m_weight -= weight;

      // return the copy
      return cheese;
    } else {
      // create a empty cheese object
      Cheese cheese;
      return cheese;
    }
  }

  std::string Cheese::getName() const{
    return m_name;
  }

  int Cheese::getWeight() const{
    return m_weight;
  }

  double Cheese::getPrice() const{
    return m_price;
  }

  std::string Cheese::getDesc() const{
    return m_desc;
  }

  std::string& Cheese::removeSpaces(std::string &str){
    // first loop till the first non space character and remove the spaces
    while (str[0] == ' ') {
      // remove the space from the string
      str.erase(0, 1);
    }

    // second loop till the last non space character and remove the spaces
    while (str[str.length() - 1] == ' ') {
      // remove the space from the string
      str.erase(str.length() - 1, 1);
    }

    return str;
  }

  std::ostream& Cheese::display(std::ostream &os) const{
    size_t nameLength = 21;
    size_t weightLength = 5;
    size_t priceLength = 5;
    size_t descLength = 34;

    os << '|';
    os << left << setw(nameLength) << m_name;
    os << '|';
    os << setw(weightLength) << m_weight;
    os << '|';
    os << fixed << setprecision(2) << setw(priceLength) << m_price;
    os << '|';
    os << right << setw(descLength) << m_desc;
    os << "|" << endl;
    return os;
  }

  std::ostream& operator<<(std::ostream &os, const Cheese &src){
    src.display(os);
    return os;
  }
}