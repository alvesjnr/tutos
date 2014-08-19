#include "utils.h"

static inline void set_bit(unsigned int *x, int bit) {
        *x |= (1L << bit);
}

static inline void clear_bit(unsigned int *x, int bit) {
        *x &= ~(1L << bit);
}

static inline void toggle_bit(unsigned int *x, int bit){
        *x ^= (1L << bit);
}


