//
//  Engine.hpp
//  Test
//
//  Created by Vitalii Kudla on 27/10/2021.
//

#ifndef Engine_hpp
#define Engine_hpp

#include <string>
#include "Matici.hpp"

class Engine {
private:
    std::string m_maticiFileName;
    Matici* m_matici;
    void printIntroduction() const;
    void printOptions() const;
    void printEnd() const;
    void processInput(char input);

public:
    void start();
    Engine(const std::string& maticiFileName);
    ~Engine();

private:
    Position waitForInput() const;
    bool checkFiveInRow(Position position) const;
};
#endif /* Engine_hpp */
