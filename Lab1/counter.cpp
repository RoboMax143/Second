#include "counter.hpp"
#include <iostream>


Counter::Counter() {
	value_ = 0;
}
Counter::Counter(int startValue) {
	if (startValue < 0) value_ = 0;
	else value_ = startValue;
}
Counter::~Counter() {
	std::cout << "—чЄтчик удален, финальное значение : " << value_ << std::endl;
}

void Counter::count_plus() {
	value_++;
}

void Counter::count_minus() {
	if(value_ > 0) value_--;
} 

int Counter::get_count() const {
	return value_;
}

void Counter::reset_count() {
	value_ = 0;
}

void Counter::set_count(int value) {
	value_ = value;
}

void Counter::multiply_count(int mult) {
	value_ = value_ * mult;
}

bool Counter::is_empty() const {
	if (value_ == 0) return true;
	else return false;
}

