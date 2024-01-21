/*
  Name: Temitope Oladimeji Samuel Adebayo
  Date: 2023-10-06

  I have done all the coding by myself and only copied the code that my professor provided 
  to complete my workshops and assignments.
*/

#include "CheeseShop.h"

using namespace std;

namespace sdds {
  CheeseShop::CheeseShop(const std::string& name) {
    m_shopName = name;
    m_size = 0;
    m_pCheeses = nullptr;
  }

  CheeseShop::CheeseShop(const CheeseShop& src) {
    *this = src;
  }

  CheeseShop& CheeseShop::operator=(const CheeseShop& src) {
    if (this != &src) {
      // deallocate the dynamic memory for each Cheese
      for (auto i = 0u; i < m_size; i++) {
        delete m_pCheeses[i];
      }
      delete[] m_pCheeses;

      // shallow copy
      m_shopName = src.m_shopName;
      m_size = src.m_size;

      // allocate dynamic memory for m_pCheeses
      m_pCheeses = new const Cheese*[m_size];
      for (auto i = 0u; i < m_size; ++i) {
        m_pCheeses[i] = new Cheese(*src.m_pCheeses[i]);
      }
    }
    return *this;
  }

  CheeseShop::CheeseShop(CheeseShop&& src) {
    *this = std::move(src);
  }

  CheeseShop& CheeseShop::operator=(CheeseShop&& src) {
    if (this != &src) {
      for (auto i = 0u; i < m_size; i++) {
        delete m_pCheeses[i];
      }
      delete[] m_pCheeses;

      m_shopName = src.m_shopName;
      m_size = src.m_size;
      m_pCheeses = src.m_pCheeses;
      
      src.m_shopName = "";
      src.m_pCheeses = nullptr;
      src.m_size = 0;
    }
    return *this;
  }

  CheeseShop::~CheeseShop() {
    // deallocate the dynamic memory for each Cheese
    for (auto i = 0u; i < m_size; ++i) {
      delete m_pCheeses[i];
    }

    // deallocate the dynamic memory for m_pCheeses
    delete[] m_pCheeses;
  }

  CheeseShop& CheeseShop::addCheese(const Cheese& cheese) {
    // a temporary array of pointers to Cheese
    const Cheese** temp = new const Cheese*[m_size + 1];

    // copy all the elements from m_pCheeses to temp 
    for (auto i = 0u; i < m_size; ++i) {
      temp[i] = m_pCheeses[i];
    }

    // add the new cheese to the end of temp
    temp[m_size] = new Cheese(cheese);

    // deallocate the dynamic memory for m_pCheeses
    delete[] m_pCheeses;

    // assign temp to m_pCheeses
    m_pCheeses = temp;

    // increment m_size
    m_size++;

    return *this;
  }

  std::ostream& CheeseShop::display(std::ostream& os) const {
    os << "--------------------------" << endl;
    os << m_shopName << endl;
    os << "--------------------------" << endl;

    if (m_size == 0) {
      os << "This shop is out of cheese!" << endl;
      os << "--------------------------" << endl; 
    } else {
      for (auto i = 0u; i < m_size; i++) {
        os << *m_pCheeses[i];
      }
      os << "--------------------------" << endl;
    }

    return os;
  }

  std::ostream& operator<<(std::ostream& os, const CheeseShop& src) {
    return src.display(os);
  }
}