#include <fstream>
#include "read_nums.h"

std::vector<long long> read_nums(const char *file) {
    std::fstream fileObj;
    std::vector<long long> nums;
    std::string num;
    long long long_num;

    fileObj.open(file, std::ios::in);

    if (fileObj.is_open()) {
        while (getline(fileObj, num)) {
            long_num = std::strtoll(num.c_str(), nullptr, 10);
            nums.emplace_back(std::abs(long_num));
        }
    }
    fileObj.close();

    return nums;
}
