#include <iostream>
#include <utility>
class RuleOfFive {

public:
	RuleOfFive(int a, int b) :_a{ a }, _b{ new int(b) } {
		std::cout << "initial"<<std::endl;
	}
	RuleOfFive(const RuleOfFive& other):RuleOfFive(other._a,*(other._b)){
		std::cout << "this is copy constructor!"<<std::endl;
	}
	RuleOfFive(RuleOfFive&& other): _a{other._a},_b{other._b}{
		std::cout << "this is move constructor!"<<std::endl;
		other._b = nullptr;
	}
	RuleOfFive& operator = (const RuleOfFive &other) {
		std::cout << "this is copy operator =!!!"<<std::endl;
		
		RuleOfFive temp(other);

		*this = std::move(temp);

		return *this;
	}
	RuleOfFive& operator = (RuleOfFive && other) {
		std::cout << "this is move operator =!!!"<<std::endl;
		
		_a = other._a;
		delete _b;
		_b = other._b;
		other._b = nullptr;
		// the other way to write is:		
		//_b = std::exchange(other._b, nullptr);
		//but if use exchange, should include <utility>
		return *this;

	}
	void show() {
		std::cout << "a is " << _a << ",b* is" << *_b<<std::endl;
	}
	~RuleOfFive() {
		if (_b != nullptr) {
			delete _b;
			std::cout << "free it!" << std::endl;
		}
	}

private:
	int _a;
	int* _b;
};

RuleOfFive test_rule_of_five(int a,int b) {
	std::cout<<"----Enter function ----"<<std::endl;
	RuleOfFive t(a,b);

	std::cout<<"----In function, ready to use copy construct ----"<<std::endl;
	RuleOfFive x = t;// copy construct
	x.show();

	std::cout<<"----Up is copy construct----"<<std::endl;
	RuleOfFive tm(5,6);

	std::cout<<"----In function, ready to use copy operator----"<<std::endl;
	tm = t;// this is copy operator
	tm.show();

	std::cout << "----Ready to use move operator----" << std::endl;
	RuleOfFive moveOperator(7,8);
	tm = std::move(moveOperator);

	std::cout << "----Leave function ----" << std::endl;

	return std::move(tm);// move construct
}

int main() {
	RuleOfFive t = RuleOfFive(1, 2);
	t.show();
	RuleOfFive tm(test_rule_of_five(3,4));
	tm.show();
}
