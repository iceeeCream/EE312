#include <cstdint>

bool subsetSum(uint32_t x[], uint32_t n, uint32_t k, uint32_t v){
    // Base cases
    if (k == 0 && v == 0){ // when you've added k terms that add up to v
        return 1;
    } if (k == 0 && v != 0){ // when you've added k terms that do not add up to v
        return 0;
    } if (n == 0){ // when you run out of terms to add while k > 0
        return 0;
    }

    bool case1 = 0;
    if (n > k) // if n <= k, x[0] must be included in sum, so case1 isn't even evaluated
        case1 = subsetSum(x + 1, n - 1, k, v); // sum does not include x[0]
    if (case1) // if case 1 == true, no need to check case 2
        return 1;

    bool case2 = 0;
    if (v >= x[0]) // shouldn't include x[0] in sum if it is bigger than v
        case2 = subsetSum(x + 1, n - 1, k - 1, v - x[0]); // sum includes x[0]
    if (case2)
        return 1;

    return 0;
}