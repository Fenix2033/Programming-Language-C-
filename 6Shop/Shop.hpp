//
//  Shop.hpp
//  CPP_shop
//
//  Created by David Procházka on 04/11/2021.
//

#ifndef Shop_hpp
#define Shop_hpp

#include <map>
#include "Order.hpp"
#include "Customer.hpp"

class Shop {
    std::vector<Customer> m_customers;
    std::vector<Customer>::iterator m_activeCustomer;
    std::vector<Item> m_basket;
    std::multimap<Customer*, Order> m_orders;
public:
    Shop();
    Shop(const Shop& original); // musime udelat nebo zakazat kopirovani
    void addCustomer(const unsigned int memberId,
                     const float age,
                     const std::string name,
                     const std::string address);
    void selectActiveCustomer(const unsigned int memberId);
    void addItemToBasket(const float price, const std::string description);
    void printBasket() const;
    void emptyBasket();
    
    void placeOrder();
    void sortCustomersByVipStatus();
    void printNewOrders();
};

#endif /* Shop_hpp */
