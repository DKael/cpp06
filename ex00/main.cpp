/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:10:19 by hyungdki          #+#    #+#             */
/*   Updated: 2024/03/19 17:22:12 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <typeinfo>

#include "ScalarConverter.hpp"

int main() {
  //   std::string test = "test";
  //   char test_c;
  //   test_c = 'c';

  //   std::cout << typeid(test[0]).name() << ' '
  //             << typeid(static_cast<char>(test[0])).name() << ' ';
  //   std::cout << typeid(test_c).name();
  ScalarConverter::convert(" ");
  ScalarConverter::convert("w");
  ScalarConverter::convert("W");
  ScalarConverter::convert("!");
  ScalarConverter::convert("~");
  ScalarConverter::convert("3");
}
