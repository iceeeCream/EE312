#include <cstdint>
#include <assert.h>
#include <stdio.h>

bool sumsTo(uint32_t x[], uint32_t n, uint32_t k, uint32_t v){
    // Base cases
    if (k == 0 && v == 0){
        return 1;
    } if (k == 0 && v != 0){
        return 0;
    } if (k > n || n == 0){ // extra base case, where you run out of terms to add while k > 0
        return 0;
    }

    bool case1 = sumsTo(x + 1, n - 1, k, v); // sum does not include x[0]
    bool case2 = 0;
    if (v >= x[0]){
        case2 = sumsTo(x + 1, n - 1, k - 1, v - x[0]); // sum includes x[0]
    }
    if (case1 || case2){
        return 1;
    }
    return 0;
}

// Testing stuff
//printf("x[0], n, k, v: %d, %d, %d, %d \n", x[0], n, k, v);
/*int main() {
    uint32_t a[5] = {4, 5, 3, 2, 9};
    assert(1 == sumsTo(a, 5, 2, 9));
    return 0;
}*/