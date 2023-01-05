#include <fstream>
#include "read_nums.h"
#include "BigInt.h"

std::vector<std::string> read_nums(const std::string &file) {
    std::fstream fileObj;
    std::vector<std::string> nums;
    std::string num;

    fileObj.open(file, std::ios::in);

    if (fileObj.is_open()) {
        while (getline(fileObj, num)) {
            nums.push_back(num);
        }
        fileObj.close();
    }
    return nums;
}
