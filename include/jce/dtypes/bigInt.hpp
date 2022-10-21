// C++ program to implement
// the above approach
// from https://www.geeksforgeeks.org/bigint-big-integers-in-c-with-example/
#pragma once
#include <bits/stdc++.h>
 
using namespace std;

namespace jce{
    class BigInt{
        string digits;
    public:
    
        //Constructors:
        BigInt(unsigned long long n = 0);
        BigInt(string &);
        BigInt(const char *);
        BigInt(BigInt &);
        BigInt(BigInt&&);
    
        //Helper Functions:
        void static divide_by_2(BigInt &a);
        bool static Null(const BigInt &);
        int static Length(const BigInt &);
        int operator[](const int)const;
        void divide_by_2();
    
                   /* * * * Operator Overloading * * * */
    
        //Direct assignment
        BigInt &operator=(const BigInt &);
    
        //Post/Pre - Incrementation
        BigInt &operator++();
        BigInt operator++(int temp);
        BigInt &operator--();
        BigInt operator--(int temp);
    
        //Addition and Subtraction
        friend BigInt &operator+=(BigInt &, const BigInt &);
        friend BigInt operator+(const BigInt &, const BigInt &);
        friend BigInt operator-(const BigInt &, const BigInt &);
        friend BigInt &operator-=(BigInt &, const BigInt &);
    
        //Comparison operators
        friend bool operator==(const BigInt &, const BigInt &);
        friend bool operator!=(const BigInt &, const BigInt &);
    
        friend bool operator>(const BigInt &, const BigInt &);
        friend bool operator>=(const BigInt &, const BigInt &);
        friend bool operator<(const BigInt &, const BigInt &);
        friend bool operator<=(const BigInt &, const BigInt &);
    
        //Multiplication and Division
        friend BigInt &operator*=(BigInt &, const BigInt &);
        friend BigInt operator*(const BigInt &, const BigInt &);
        friend BigInt &operator/=(BigInt &, const BigInt &);
        friend BigInt operator/(const BigInt &, const BigInt &);
    
        //Modulo
        friend BigInt operator%(const BigInt &, const BigInt &);
        friend BigInt &operator%=(BigInt &, const BigInt &);
    
        //Power Function
        friend BigInt &operator^=(BigInt &,const BigInt &);
        friend BigInt operator^(BigInt &, const BigInt &);

        //Square Root Function
        friend BigInt sqrt(BigInt &a);
    
        //Read and Write
        friend ostream &operator<<(ostream &,const BigInt &);
        friend istream &operator>>(istream &, BigInt &);
    
        //Others
        friend BigInt NthCatalan(int n);
        friend BigInt NthFibonacci(int n);
        friend BigInt Factorial(int n);
    };

    //Addition and Subtraction
    BigInt &operator+=(BigInt &, const BigInt &);
    BigInt operator+(const BigInt &, const BigInt &);
    BigInt operator-(const BigInt &, const BigInt &);
    BigInt &operator-=(BigInt &, const BigInt &);
    
    //Comparison operators
    bool operator==(const BigInt &, const BigInt &);
    bool operator!=(const BigInt &, const BigInt &);

    bool operator>(const BigInt &, const BigInt &);
    bool operator>=(const BigInt &, const BigInt &);
    bool operator<(const BigInt &, const BigInt &);
    bool operator<=(const BigInt &, const BigInt &);

    //Multiplication and Division
    BigInt &operator*=(BigInt &, const BigInt &);
    BigInt operator*(const BigInt &, const BigInt &);
    BigInt &operator/=(BigInt &, const BigInt &);
    BigInt operator/(const BigInt &, const BigInt &);

    //Modulo
    BigInt operator%(const BigInt &, const BigInt &);
    BigInt &operator%=(BigInt &, const BigInt &);

    //Power Function
    BigInt &operator^=(BigInt &,const BigInt &);
    BigInt operator^(BigInt &, const BigInt &);

    //Square Root Function
    BigInt sqrt(BigInt &a);

    //Read and Write
    ostream &operator<<(ostream &,const BigInt &);
    istream &operator>>(istream &, BigInt &);

    //Others
    BigInt NthCatalan(int n);
    BigInt NthFibonacci(int n);
    BigInt Factorial(int n);
}