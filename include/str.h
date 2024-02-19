// Copyright 2024 HSE NN
// Author: Lev Pestov

#pragma once

#include <typeinfo>
#include <iostream>
#include <cstring> // for strlen, strcpy, etc.
#include <cctype>

#ifndef CLASS_STRING_STR_H
#define CLASS_STRING_STR_H

class MyString {
 private:
  char *str;

 public:

  MyString(const char *str = nullptr);

  MyString(const MyString &string);

  explicit MyString(const std::string &other);

  MyString(MyString &&other);

  virtual ~MyString();

  char *get() const;

  size_t length();

  MyString &operator=(const MyString &other);

  MyString &operator=(MyString &&other);

  bool operator==(const MyString &other) const;

  bool operator!=(const MyString &other) const;

  MyString operator+(const MyString &other) const;

  MyString operator-(const MyString &other) const;

  MyString operator*(const int factor) const;

  bool operator>(const MyString &other) const;

  bool operator>=(const MyString &other) const;

  bool operator<(const MyString &other) const;

  bool operator<=(const MyString &other) const;

  MyString operator!() const;

  int operator()(const char *sub) const;

  char &operator[](int index);

  friend std::ostream &operator<<(std::ostream &os, MyString &str);

  friend std::istream &operator>>(std::istream &is, MyString &str);
};

#endif //CLASS_STRING_STR_H