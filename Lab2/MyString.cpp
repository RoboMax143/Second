#include "MyString.hpp"
#include <iostream>


namespace m {
    class string {
    public:
        string() : size_(0), str_(nullptr) {}
        string(const char c, const size_t size) : size_(size), str_(new char[size_]) {
            std::fill(str_, str_ + size_, c);
            std::cerr << "ctor" << std::endl;
        }
        ~string() {
            if (str_ != nullptr) {
                delete[] str_;
            }
            std::cerr << "dtor" << std::endl;
        }

        string(const char* str) : size_(strlen(str)), str_(new char[size_]) {
            std::copy(str, str + size_, str_);

            std::cerr << "ctor" << std::endl;
        }
        string(const string& other) : string(other.str_) {
            std::cerr << "copy ctor" << std::endl;
        }

        //string(const string& other) = delete;

        string& operator=(string& other) {

            if (this != &other) {
                delete[] str_;
                size_ = other.size_;
                str_ = new char[size_];
                std::copy(other.str_, other.str_ + other.size_, str_);
                std::cerr << "copy assigment operator" << std::endl;
            }
            return *this;
        }
        string operator+(const string& other) const {
            size_t new_size = size_ + other.size_;
            char* new_str = new char[new_size];


            std::copy(str_, str_ + size_, new_str);

            std::copy(other.str_, other.str_ + other.size_, new_str + size_);


            string result(new_str);
            result.size_ = new_size;
            result.str_ = new_str;
            return result;
        }

        const char& operator[](size_t index) const {
            return str_[index];
        }

        bool operator==(const string& other) const {
            if (size_ != other.size_) return false;
            return std::equal(str_, str_ + size_, other.str_);
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

        const char* get() const {
            return str_;
        }
    }
