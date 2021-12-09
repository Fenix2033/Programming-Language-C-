//
//  Customer.hpp
//  CPP_shop
//
//  Created by David Procházka on 04/11/2021.
//

#ifndef Customer_hpp
#define Customer_hpp

#include <iostream>

struct Customer {
    unsigned int memberId;
    float age;
    bool vipMember;
    std::string name;
    std::string address;
};

#endif /* Customer_hpp */
