//
//  Shop.cpp
//  CPP_shop
//
//  Created by David Procházka on 04/11/2021.
//

#include "Shop.hpp"

Shop::Shop(){
    m_activeCustomer = m_customers.end();
}

Shop::Shop(const Shop& original){
    throw std::exception();
}

void Shop::addCustomer(const unsigned int memberId,
                       const float age,
                       const std::string name,
                       const std::string address){
    m_customers.push_back(Customer{memberId, age, false, name, address});
}

void Shop::selectActiveCustomer(const unsigned int memberId){
    auto foundCustomer = std::find_if(m_customers.begin(), m_customers.end(),
            [memberId](const Customer &cus)->bool{ return cus.memberId == memberId; });
    
    if(foundCustomer == m_customers.end()){
        std::cerr << "Customer not found" << std::endl;
    } else {
        m_activeCustomer = foundCustomer;
    }
}

void Shop::addItemToBasket(const float price, const std::string description){
    m_basket.push_back(Item{description, price});
}

void Shop::printBasket() const{
    std::for_each(m_basket.begin(), m_basket.end(),
                  [](const Item &itm)->void{
        std::cout << "Desc: " << itm.description << ", ";
        std::cout << "price: " << itm.price << std::endl;
    });
}

void Shop::emptyBasket(){
    m_basket.clear();
}

void Shop::placeOrder(){
    // prida novy zaznam do orders (pro aktualniho zakaznika udela order z kosiku)
    m_orders.insert(std::pair<Customer*, Order>(
                                                &(*m_activeCustomer),
                                                Order{m_basket, OrderStatus::New})
                    );
    // vyprazdni kosik
    emptyBasket();
    // pokud dotycny zakaznik ma alespon 10 objednavek, tak dostane VIP status
    // udelat metodu, ktera spocita pocet objednavek daneho zakaznika
}

void Shop::sortCustomersByVipStatus(){
    // seradi zakazniky, nejdrive VIP, v ramci skupiny abecedne
    std::sort(m_customers.begin(), m_customers.end(),
              [](const Customer& c1, const Customer& c2)->bool{
        return c1.name < c2.name;
    });
    
    std::stable_sort(m_customers.begin(), m_customers.end(),
              [](const Customer& c1, const Customer& c2)->bool{
        return !((c1.vipMember == false) and (c2.vipMember == true));
    });
}

void Shop::printNewOrders(){
    // vypise pouze nove objednavky
    std::for_each(m_orders.begin(), m_orders.end(),
                  [](const std::pair<Customer*, Order> &ord)->void{
        if(ord.second.status == OrderStatus::New){
            std::cout << "Customer: " << ord.first->name << std::endl;
        }
    });
}
