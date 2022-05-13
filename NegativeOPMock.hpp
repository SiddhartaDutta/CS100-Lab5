#ifndef __NEGATIVEOPMOCK_HPP__
#define __NEGATIVEOPMOCK_HPP__

#include "base.hpp"

class NegativeOPMock : public Base {

	public:
		NegativeOPMock() : Base(){}
		virtual double evaluate(){ return -987.325; }
		virtual std::string stringify(){ return "-987.325"; }

};

#endif
