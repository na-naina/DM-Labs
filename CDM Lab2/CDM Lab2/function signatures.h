#pragma once
#include <iostream>
#include <iterator>
#include <sstream>



std::string infixToPostfix(std::string s);
char boolNot(char x);
int prec(char c);
char boolConj(char x, char y);
char boolDisj(char x, char y);