#ifndef __ZEROOPMOCK_HPP__
#define __ZEROOPMOCK_HPP__

#include "base.hpp"

class ZeroOPMock : public Base {
    public:
        ZeroOPMock(): Base() { }
        virtual double evaluate() { return 0.0; }
        virtual std::string stringify() { return "0.0"; }
};

#endif 
