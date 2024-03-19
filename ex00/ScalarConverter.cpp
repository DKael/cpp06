/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:09:21 by hyungdki          #+#    #+#             */
/*   Updated: 2024/03/19 17:36:39 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string input) {
  char c_type;
  int i_type;
  float f_type;
  double d_type;

  if (input.length() == 1 && ((32 <= input[0] && input[0] <= 47) ||
                              (58 <= input[0] && input[0] <= 126))) {
    c_type = input[0];
    i_type = static_cast<int>(c_type);
    f_type = static_cast<float>(c_type);
    d_type = static_cast<double>(c_type);
    std::cout << "char: " << c_type << '\n' << "int: " << i_type << '\n';
    std::cout.precision(1);
    std::cout << std::fixed << "float: " << f_type << "f\n"
              << "double: " << d_type << '\n';
  }
}