//
//  Store.cpp
//  CPP_cviceni6_obchod
//
//  Created by David Prochazka on 11/6/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#include "Store.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include "CustomerException.h"


Store::Store() {
}


void Store::addCustomer(const int memberId, const float age,
                        const std::string name, const std::string address) {
    m_customers.push_back(Customer{memberId, age, false, name, address});
}

void Store::selectActiveCustomer(const int memberId) {
    // std::vector<Customer>::iterator
    auto it = std::find_if(m_customers.begin(), m_customers.end(),
                           [memberId](const Customer &cus) -> bool {
                               return cus.memberId == memberId;
                           });
    if (it != m_customers.end()) {
        m_activeCustomer = it;
    } else {
        throw std::out_of_range("Customer not found");
    }
}

void Store::addItemToBasket(const float price, const std::string description) {
    m_basket.push_back(Item{description, price});
}

void Store::emptyBasket() {
    m_basket.clear();
}

void Store::placeOrder() {
    Order newOrder;
    newOrder.time = std::chrono::system_clock::now();

    newOrder.items.resize(m_basket.size());
    std::copy(m_basket.begin(), m_basket.end(), newOrder.items.begin());

    newOrder.status = OrderStatus::New;

    m_orders.insert(std::pair<Customer *, Order>(&(*m_activeCustomer), newOrder));

    emptyBasket();
    setVipStatus();
}

void Store::sortCustomersByVipStatus() {
    // sort by name
    sort(m_customers.begin(), m_customers.end(),
         [](const Customer &c1, const Customer &c2) -> bool {
             return c1.name > c2.name;
         });

    // sort by VIP status, stable = keep order of equal elements
    stable_sort(m_customers.begin(), m_customers.end(),
                [](const Customer &c1, const Customer &c2) -> bool {
                    return !(!c1.vipMember and c2.vipMember);
                });

    // alternative
    /*
    stable_sort(m_customers.begin(), m_customers.end(),
         [](const Customer &c1, const Customer &c2)->bool{
             if ( (c1.vipMember == false) and (c2.vipMember == true) ){
                 return false;
             } else {
                 return true;
             }
         });
     */
}

void Store::printAllCustomers() const {
    for_each(m_customers.begin(), m_customers.end(),
             [](const Customer &cus) -> void {
                 std::cout << "Jmeno: " << cus.name << "\tvek:" << cus.age
                           << "\tvip: " << cus.vipMember << std::endl;
             });
}


void Store::printDatesOfNewOrders() {
//    int i = 0;
    for_each(m_orders.begin(), m_orders.end(),
             [/*&i*/](const std::pair<Customer *, Order> &pair) /*throw (std::out_of_range)*/ -> void {
                 if (pair.second.status == OrderStatus::New) {
                     std::time_t now = std::chrono::system_clock::to_time_t(pair.second.time - std::chrono::hours(24)); // odečti 24 hodin od nějakého času
                     std::cout << std::ctime(&now);
                 }
//                 if (i == 1) {
//                     throw std::out_of_range("jsem mimo");
//                 }
//                 i += 1;
             });
}


void Store::printBasketInfo() {
    std::cout << "Aktualni zakaznik je " << (*m_activeCustomer).name << std::endl;

    for_each(m_basket.begin(), m_basket.end(),
             [](const Item &it) -> void {
                 std::cout << "Popis: " << it.description
                           << "\tcena: " << std::fixed << std::setprecision(2) << it.price << " EUR" << std::endl;
             });
}


void Store::setVipStatus() {
    m_activeCustomer->vipMember = true;
}





