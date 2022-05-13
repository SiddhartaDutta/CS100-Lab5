#ifndef __ZEROOPMOCK_HPP__
#define __ZEROOPMOCK_HPP__

#include "base.hpp"

class NineOPMock : public Base {
    public:
        NineOPMock(): Base() { }
        virtual double evaluate() { return 9; }
        virtual std::string stringify() { return "9.0"; }
};

#endif 
