#include <iostream>
#include <cstdlib>
#include <numeric>
#include <chrono>
#include "../read_nums.h"

BigInt multiply_mod(BigInt a, BigInt b, BigInt mod) {
    BigInt result = 0;
    while (!Null(b)) {
        if (b & 1)
            result = (result + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return result;
}

BigInt f(BigInt x, BigInt c, BigInt mod) {
    return (multiply_mod(x, x, mod) + c) % mod;
}

BigInt brent(BigInt n, BigInt x0 = 2, BigInt c = 1) {
    BigInt x = x0;
    BigInt g = 1;
    BigInt q = 1;
    BigInt xs, y;

    int m = 128;
    int l = 1;
    while (g == 1) {
        y = x;
        for (int i = 1; i < l; i++)
            x = f(x, c, n);
        int k = 0;
        while (k < l && g == 1) {
            xs = x;
            for (int i = 0; i < m && i < l - k; i++) {
                x = f(x, c, n);
                q = multiply_mod(q, std::abs(y - x), n);
            }
            g = std::gcd(q, n);
            k += m;
        }
        l *= 2;
    }
    if (g == n) {
        do {
            xs = f(xs, c, n);
            g = std::gcd(std::abs(xs - y), n);
        } while (g == 1);
    }
    return g;
}

int main([[maybe_unused]] int argc, char **argv) {
    BigInt factor;
    std::vector<BigInt> nums;

    nums = read_nums(std::string(argv[1]));
    auto start = std::chrono::high_resolution_clock::now();
    for (auto num : nums) {
        factor = brent(num);
        std::cout << num << " = " << factor << "*" << num / factor << std::endl;
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
    return 0;
}
