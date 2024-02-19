// Copyright 2024 HSE NN
// Author: Lev Pestov

#include "str.h"

int main() {
  std::cout << "--< test 1 >--\n";
  MyString str1 = "abc";
  std::cout << str1 << std::endl;//abc

  std::cout << "--< test 2 >--\n";
  MyString str2("1234");
  std::cout << str2 << std::endl; //1234
  std::cout << str2.get()[3] << std::endl;// 4

  std::cout << "--< test 3 >--\n";
  std::cin >> str2;
  std::cout << str2.length() << std::endl; // length in cin


  std::cout << "--< test 4 >--\n";
  str2 = str1;
  std::cout << str2 << std::endl; // abc


  std::cout << "--< test 5 >--\n";
  MyString meow(std::move(MyString("meow")));
  std::cout << meow << std::endl; // meow



  std::cout << "--< test 6 >--\n";
  MyString big_str = str1 + meow + "hello";
  std::cout << big_str << std::endl; // abcmeowhello


  std::cout << "--< test 7 >--\n";
  MyString str_string(std::string("string"));
  std::cout << str_string << std::endl; // string



  std::cout << "--< test 8 >--\n";
  str_string = "no_string";
  std::cout << str_string << std::endl; // no_string



  std::cout << "--< test 9 >--\n";
  str_string = "good string";
  MyString string_new(str_string);
  std::cout << string_new << std::endl; // good string



  std::cout << "--< test 10 >--\n";
  const char *sub = "ab";
  std::cout << str1(sub) << std::endl; // 1
  const char *sub_2 = "abc";
  std::cout << str1(sub_2) << std::endl; // 1
  const char *sub_3 = "ba";
  std::cout << str1(sub_3) << std::endl; // 0




  std::cout << "--< test 11 >--\n";
  bool flag = str1 == big_str;
  std::cout << flag << std::endl; // 0
  flag = str1 != big_str;
  std::cout << flag << std::endl; // 1

  std::cout << "--< test 12 >--\n";
  MyString qwe("qwe");
  MyString rty("rty");
  qwe = qwe + rty;
  std::cout << qwe << std::endl; // qwerty



  std::cout << "--< test 13 >--\n";
  MyString aabad("aabad");
  MyString aab("aab");
  MyString d = aabad - aab;
  std::cout << d << std::endl; // d



  std::cout << "--< test 14 >--\n";
  MyString d3 = d * 3;
  std::cout << d3 << std::endl; // ddd

  std::cout << "--< test 15 >--\n";
  MyString aaab = "aaab";
  MyString aaac = "aaac";
  bool flag_2 = aaab > aaac;
  std::cout << flag_2 << std::endl; // 0

  std::cout << "--< test 16 >--\n";
  bool flag_3 = aaab < aaac;
  std::cout << flag_3 << std::endl; // 1

  std::cout << "--< test 17 >--\n";
  aaac = "aaab";
  bool flag_4 = aaab >= aaac;
  std::cout << flag_4 << std::endl; // 1

  std::cout << "--< test 18 >--\n";
  MyString reg_str = "HELLO_hello";
  reg_str = !reg_str;
  std::cout << reg_str << std::endl; //hello_HELLO

  std::cout << "--< test 19 >--\n";
  MyString ind_str = "yup";
  ind_str[0] = 'h';
  ind_str[1] = 'e';
  ind_str[2] = 'y';
  std::cout << ind_str << std::endl; //hey



  //---Move constructor and operator test---

  //You need you change the *str filed to "public"
  //and make the entire code above a comment and
  // delete the comment below


  /*
  MyString str1 = "abc";
  MyString str2 = "123";

  std::cout << "str1:" << "\t";
  std::cout << &str1.str << "\t";
  printf("%p\t",str1.str);
  std::cout<<str1<<std::endl;

  std::cout << "str2:" << "\t";
  std::cout << &str2.str << "\t";
  printf("%p\t",str2.str);
  std::cout<<str2<<std::endl;


  str1 = std::move(str2);

  std::cout << std::endl;

  std::cout << "str1:" << "\t";
  std::cout << &str1.str << "\t";
  printf("%p\t",str1.str);
  std::cout<<str1<<std::endl;


  std::cout << "str2:" << "\t";
  std::cout << &str2.str << "\t";
  printf("%p\t",str2.str);
  std::cout<<str2<<std::endl;
  */
  return 0;
}
