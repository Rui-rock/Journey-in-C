/*

Assignment: Break (weak) RSA Key

*/

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint64_t break_RSA(uint64_t c, uint64_t n, int e)
{
    for (uint64_t X = 2; X < n; X++) {
        uint64_t k = 1;
        uint64_t prod = 1;

        do {
            prod *= X;       // STILL potentially overflows!
            k++;

            prod %= n;

            if ((prod == X) && (k % e == 0)) {
                return X;
            }

            printf("prod = %" PRIu64 ", X = %" PRIu64
                   ", k = %" PRIu64 "\n", prod, X, k);

        } while (k < n || prod == 1);
    }

    return 0;
}

int main(void)
{
    uint64_t c = UINT64_C(16034337012869442858);
    uint64_t n = UINT64_C(2559026984989481737);
    int e = 65537;

    uint64_t X = break_RSA(c, n, e);

    printf("%" PRIu64 "\n", X);

    return 0;
}
