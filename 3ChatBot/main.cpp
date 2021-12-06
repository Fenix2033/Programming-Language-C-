//
//  main.cpp
//  Chatbot
//
//  Created by David Procházka on 11/10/2018.
//  Copyright © 2018 MENDELU. All rights reserved.
//

#include <iostream>
#include "Loader.hpp"
#include "Chatbot.hpp"

class A {
public:
    void a() {
        std::cout<<"a"<<std::endl;
    }
};

class B {
public:
    void b(A a) {
        std::cout<<"b"<<std::endl;
        a.a();
    }
};

int main(int argc, const char * argv[]) {
// --- zkousim samostatne loader ---
//    Loader pokus;
//    std::vector<Conversation> conversations = pokus.getConversations("chat.txt");
//
//    for(auto conv : conversations){
//        std::cout << "R: " << conv.response << std::endl;
//    }

// -- staticka instance: --
    Chatbot chatbot("chat.txt");
    chatbot.chat();

// -- staticka instance varianta B: --
//    Chatbot chatbot = Chatbot("chat.txt");
//    chatbot.chat();

// -- dyn. instance: --
//    Chatbot* chatbot = new Chatbot("chat.txt");
//    chatbot->chat();
//    delete chatbot;

// -- nefunkcni, mix obojiho: --
//    Chatbot* chatbot("chat.txt");
//    chatbot->chat();
//    delete chatbot;

// -- predani staticke kopie jako parametr metody, udela se kopie! --
// -- jak to vypada v pameti:
// stack: a, heap: nic
//    A a;
//    B b;
//    b.b(a);

// --- ruzne zpusoby pristupu k dynamicke instanci ---
//    A* a = new A();

// --- jak to vypada v pameti: ---
// [a] - instance a je zabalena v odkazu []
// stack: [], heap: a
// odkaz ve stacku smeruje na instanci v heapu
// [] -> a

// --- klasicky pristup ---
//    a->a();

// --- nejprve zabalim do odkazu pomoci &, pak opet rozbalim pomoci *
//    (*(&a))->a();

// --- operator `->` je vlastne to same jako `*` dohromady s `.` ---
//    (*a).a();

// --- nezapomenout vzdy smazat dyn. instanci na konci! ---
//    delete a;
    
    return 0;
}
