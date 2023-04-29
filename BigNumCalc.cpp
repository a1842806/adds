#include <list>
#include <string>
#include "BigNumCalc.h"

std::list<int> BigNumCalc::buildBigNum(std::string numString) {
    std::list<int> num;
    for (int i = 0; i < numString.length(); ++i)
        num.push_back(int(numString[i] - '0'));
    return num;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
    std::string sum = "";
    int tmp = 0;

    for (auto it1 = num1.rbegin(), it2 = num2.rbegin(); it1 != num1.rend() || it2 != num2.rend(); ) {
        int dig1, dig2;
        if (it1 == num1.rend()) dig1 = 0;
        else dig1 = *it1, it1++;
        if (it2 == num2.rend()) dig2 = 0;
        else dig2 = *it2, it2++;
        int digit = dig1 + dig2 + tmp;
        tmp = digit / 10;
        digit %= 10;
        sum = char(digit + '0') + sum;
    }
    if (tmp) sum = '1' + sum;
    return this->buildBigNum(sum);
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
    std::string diff = "";
    int tmp = 0;

    for (auto it1 = num1.rbegin(), it2 = num2.rbegin(); it1 != num1.rend() || it2 != num2.rend(); ) {
        int dig1, dig2;
        if (it1 == num1.rend()) dig1 = 0;
        else dig1 = *it1, it1++;
        if (it2 == num2.rend()) dig2 = 0;
        else dig2 = *it2, it2++;
        int digit = dig1 - dig2 - tmp;
        tmp = (digit < 0);
        digit += 10 * tmp;
        diff = char(digit + '0') + diff;
    }

    return this->buildBigNum(diff);
}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
    std::string t = "";
    std::list<int> prod;

    for (auto it1 = num1.rbegin(); it1 != num1.rend(); ++it1) {
        std::string sum = t;
        int tmp = 0;
        for (auto it2 = num2.rbegin(); it2 != num2.rend(); ++it2) {
            int digitProduct = (*it1) * (*it2) + tmp;
            tmp = digitProduct / 10;
            digitProduct %= 10;
            sum = char(digitProduct + '0') + sum;
        }
        if (tmp) sum = char(tmp + '0') + sum;
        prod = this->add(prod, buildBigNum(sum));
        t += '0';
    }

    return prod;
}