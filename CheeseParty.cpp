/*
  Name: Temitope Oladimeji Samuel Adebayo
  Date: 2023-10-05

  I have done all the coding by myself and only copied the code that my professor provided 
  to complete my workshops and assignments.
*/

#include "CheeseParty.h"

using namespace std;

namespace sdds {
  CheeseParty::CheeseParty(const CheeseParty& src) {
    *this = src;
  }

  CheeseParty& CheeseParty::operator=(const CheeseParty& src) {
    if (this != &src) {
      m_size = src.m_size;

      delete[] m_pCheeses;
      m_pCheeses = new const Cheese*[m_size];

      for (auto i = 0u; i < m_size; i++) {
        m_pCheeses[i] = src.m_pCheeses[i];
      }
    }
    return *this;
  }

  CheeseParty::CheeseParty(CheeseParty&& src) {
    *this = std::move(src);
  }

  CheeseParty& CheeseParty::operator=(CheeseParty&& src) {
    if (this != &src) {
      delete[] m_pCheeses;

      m_size = src.m_size;
      m_pCheeses = src.m_pCheeses;

      src.m_size = 0;
      src.m_pCheeses = nullptr;
    }
    return *this;
  }

  CheeseParty::~CheeseParty() {
    delete[] m_pCheeses;
  }

  CheeseParty& CheeseParty::addCheese(const Cheese& src) {
    // search in the array of already stored cheeses to find if the parameter is already in there (compare the address of the 
    // parameter with the addresses stored in the array).
    bool found = false;

    for (auto i = 0u; i < m_size; i++) {
      if (m_pCheeses[i] == &src) {
        found = true;
      }
    }

      // if the parameter is not in the array, this function resizes the array to make room for the parameter 
      // (if necessary) and stores the address of the parameter in the array (your function should not make a copy of the parameter).
    if (!found)
    {
      const Cheese** temp = new const Cheese*[m_size + 1];

      for (auto i = 0u; i < m_size; i++) {
        temp[i] = m_pCheeses[i];
      }

      // add the new cheese to the end of the array
      temp[m_size++] = &src;

      delete[] m_pCheeses;

      m_pCheeses = temp;
    }

    return *this;
  }

  void CheeseParty::removeAndResize(size_t index) {
    // if the index is valid, this function removes the cheese at the index and resizes the array to remove the empty space.
    if (index < m_size) {
      const Cheese** temp = new const Cheese*[m_size - 1];
      
      // copy all the cheeses before the index
      for (auto i = 0u; i < index; i++) {
        temp[i] = m_pCheeses[i];
      }

      // copy all the cheeses after the index
      for (auto i = index; i < m_size - 1; i++) {
        temp[i] = m_pCheeses[i + 1];
      }

      delete[] m_pCheeses;

      m_pCheeses = temp;

      m_size--;
    }
  }

  // CheeseParty& removeCheese(): a modifier that removes any cheeses from the array that have a 0 weight.
  CheeseParty& CheeseParty::removeCheese() {
    if (m_size > 0) {
      for (auto i = 0u; i < m_size; i++) {
        if (m_pCheeses[i]->getWeight() == 0) {
          removeAndResize(i);
        }
      }
    }

    return *this;
  }

  std::ostream& CheeseParty::display(std::ostream& os) const {
    os << "--------------------------" << endl;
    os << "Cheese Party" << endl;
    os << "--------------------------" << endl;

    if (m_size == 0) {
      os << "This party is just getting started!" << endl;
      os << "--------------------------" << endl; 
    } else {
      for (auto i = 0u; i < m_size; i++) {
        os << *m_pCheeses[i];
      }
      os << "--------------------------" << endl;
    }

    return os;
  }

  std::ostream& operator<<(std::ostream& os, const CheeseParty& src) {
    return src.display(os);
  }
}