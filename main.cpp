#include <iostream>
#include <cstdlib>
#include <numeric>
#include <chrono>
#include "read_nums.h"

long long multiply_mod(long long a, long long b, long long mod) {
    long long result = 0;
    while (b) {
        if (b & 1)
            result = (result + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return result;
}

long long f(long long x, long long c, long long mod) {
    return (multiply_mod(x, x, mod) + c) % mod;
}

long long brent(long long n, long long x0 = 2, long long c = 1) {
    long long x = x0;
    long long g = 1;
    long long q = 1;
    long long xs, y;

    int m = 128;
    int l = 1;
    while (g == 1) {
        y = x;
        for (int i = 1; i < l; ++i)
            x = f(x, c, n);
        int k = 0;
        while (k < l && g == 1) {
            xs = x;
            for (int i = 0; i < m && i < l - k; ++i) {
                x = f(x, c, n);
                q = multiply_mod(q, std::abs(y - x), n);
            }
            g = std::gcd(q, n);
            k += m;
        }
        l <<= 1; // l *= 2;
    }
    if (g == n) {
        do {
            xs = f(xs, c, n);
            g = std::gcd(std::abs(xs - y), n);
        } while (g == 1);
    }
    return g;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <FILE>" << std::endl;
        return 1;
    }
    std::vector<long long> nums{0};
    long long fact;

    nums = read_nums(argv[1]);

    auto start = std::chrono::high_resolution_clock::now();

    for (const auto &i: nums) {
        fact = brent(i);
        std::cout << i << " = " << fact << " * " << i / fact << std::endl;
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "\nTime: " << duration.count() << " milliseconds." << std::endl;

    return 0;
}
