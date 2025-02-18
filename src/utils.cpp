#include <cassert>

unsigned int ceil_log2(unsigned int n) {
    assert(n > 0);  // n must be positive.
    if (n == 1) return 0;

    unsigned int result = 0;
    // Use n-1 so that exact powers of 2 are handled correctly.
    n -= 1;
    while (n > 0) {
        result++;
        n >>= 1;
    }
    return result;
}
