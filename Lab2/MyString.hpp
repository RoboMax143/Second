#pragma once
#include <iostream>

class MyString {
public:
	MyString() : size_(0), str_(nullptr) {
		str_ = new char[1];
		str_[0] = '\0';
	}

	MyString(const char c, const size_t size) : size_(size), str_(new char[size_]) {
		std::fill(str_, str_ + size, c);
		std::cerr << "ctor" << std::endl;
	}

	MyString(const char* str) : size_(strlen(str)), str_(new char[size_]) {
		std::copy(str, str + size_, str_);

		std::cerr << "ctor" << std::endl;
	}
	MyString(const MyString& other) {
		size_ = other.size_;
		str_ = new char[size_];
		std::copy(other.str_, other.str_ + other.size_, str_);
		std::cerr << "copy ctor" << std::endl;
	}

	~MyString() {
		if (str_ != nullptr) delete[] str_;
		std::cerr << "dtor" << std::endl;
	}





	void print() const {
		for (size_t i = 0; i < size_; ++i) {
			std::cout << str_[i];
		}
		std::cout << std::endl;
	}

	void set(size_t index, char c) {
		str_[index] = c;
	}


	MyString& operator=(MyString& other) {
		MyString tmp = other;
		std::swap(tmp.size_, size_);
		std::swap(tmp.str_, str_);

		return *this;
	}

	MyString& operator+(MyString& other){
		size_t newSize = size_ + other.size_;
		char* newStr = new char[newSize];

		std::copy(str_, str_ + size_, newStr);
		std::strcat(newStr, other.str_);

		MyString New = MyString(newStr);
		
		return New;
	}



private:
	size_t size_;
	char* str_;
};