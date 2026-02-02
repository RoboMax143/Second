#include <iostream>
#include "MyString.hpp"




int main() {

	
	MyString s1("Hello");
	MyString s2(" World");
	s1 = s2;
	s1.print();

}