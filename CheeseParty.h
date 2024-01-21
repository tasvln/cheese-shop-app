/*
  Name: Temitope Oladimeji Samuel Adebayo
  Date: 2023-10-06

  I have done all the coding by myself and only copied the code that my professor provided 
  to complete my workshops and assignments.
*/

#ifndef SDDS_CHEESEPARTY_H
#define SDDS_CHEESEPARTY_H

#include <iostream>
#include "Cheese.h"

namespace sdds {
  class CheeseParty {
    const Cheese** m_pCheeses = nullptr;
    size_t m_size{};
  public:
    CheeseParty(){};

    // Copy Constructor and Copy Assignment Operator
    CheeseParty(const CheeseParty& src);
    CheeseParty& operator=(const CheeseParty& src);

    // Move Constructor and Move Assignment Operator
    CheeseParty(CheeseParty&& src);
    CheeseParty& operator=(CheeseParty&& src);

    ~CheeseParty();

    CheeseParty& addCheese(const Cheese& src);

    CheeseParty& removeCheese();

    std::ostream& display(std::ostream& os) const;

    void removeAndResize(size_t index);
  };

  std::ostream& operator<<(std::ostream& os, const CheeseParty& src);
}

#endif