//
// Created by 王青龙 on 2017/2/11.
//

#include "solution.h"

std::string Solution::multiply(std::string num1, std::string num2) {
    std::string sum(num1.size() + num2.size(), '0');
    for (int i = num1.size() - 1; i >= 0; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; j >= 0; --j) {
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            sum[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        sum[i] += carry;
    }
    size_t startpos = sum.find_first_not_of("0");
    if (std::string::npos != startpos) {
        return sum.substr(startpos);
    } else {
        return "0";
    }
}
