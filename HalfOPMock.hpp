#ifndef __HALFOPMOCK_HPP__
#define __HALFOPMOCK_HPP__

#include "base.hpp"

class HalfOPMock : public Base{

	public:
		HalfOPMock() : Base(){}
		virtual double evaluate(){ return 0.5; }
		virtual std::string stringify(){ return "0.5"; }

};

#endif
