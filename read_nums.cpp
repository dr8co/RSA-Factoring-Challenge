#include <iostream>
#include <fstream>
#include "read_nums.h"

std::vector<long long> read_nums(const std::string &file) {
    std::fstream fileObj;
    std::vector<long long> nums;
    std::string num;

    fileObj.open(file, std::ios::in);

    if (fileObj.is_open()) {
        while (getline(fileObj, num)) {
            nums.push_back(std::strtoll(num.c_str(), nullptr, 10));
        }
        fileObj.close();
    }
    return nums;
}
