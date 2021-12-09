//
//  Order.hpp
//  CPP_shop
//
//  Created by David Procházka on 04/11/2021.
//

#ifndef Order_hpp
#define Order_hpp

#include <vector>
#include "Item.hpp"
#include "OrderStatus.hpp"

struct Order {
    // time
    std::vector<Item> items;
    OrderStatus status;
};

#endif /* Order_hpp */
