/*
  Name: Temitope Oladimeji Samuel Adebayo
  Date: 2023-10-06

  I have done all the coding by myself and only copied the code that my professor provided 
  to complete my workshops and assignments.
*/

#ifndef SDDS_CHEESESHOP_H
#define SDDS_CHEESESHOP_H

#include <iostream>
#include "Cheese.h"

namespace sdds {
  class CheeseShop {
    std::string m_shopName{};
    const Cheese** m_pCheeses = nullptr;
    size_t m_size = 0;
  public:
    // Default Constructor
    CheeseShop(){};

    // One Argument Constructor
    CheeseShop(const std::string& name = "No Name");

    // Copy Constructor and Copy Assignment Operator
    CheeseShop(const CheeseShop& src);
    CheeseShop& operator=(const CheeseShop& src);

    // Move Constructor and Move Assignment Operator
    CheeseShop(CheeseShop&& src);
    CheeseShop& operator=(CheeseShop&& src);

    // Destructor
    ~CheeseShop();

    CheeseShop& addCheese(const Cheese&);

    std::ostream& display(std::ostream& os) const;
  };

  std::ostream& operator<<(std::ostream& os, const CheeseShop& src);
}


#endif