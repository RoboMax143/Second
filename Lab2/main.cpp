#include <iostream>
#include "MyString.hpp"




int main() {

	
	m::string s1("Hello");
	m::string s2("Hello");
	m::string s3 = (s1 + s2);

	if (s1 == s2) std::cout << s1[0] << std::endl;
	

}