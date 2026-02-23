#pragma once
#include <iostream>

namespace m {
    class string {
    public:
        string();
       string(const char c, const size_t size);
       ~string();

       string(const char* str);
       string(const string& other);

        //string(const string& other) = delete;

        string& operator=(string& other);
        string operator+(const string& other) const;

        const char& operator[](size_t index) const;

        bool operator==(const string& other) const;
        
        void print() const;
        void set(size_t index, char c);

        const char* get() const;
    private:
        size_t size_;
        char* str_; 
    };
}//m