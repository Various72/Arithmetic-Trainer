#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

// modu(int num, int mod) returns num % mod
// Requires: mod > 0
int modu(int num, int mod) {
    assert(mod > 0);
    if (num <= mod) {
        return num;
    } else {
        return modu(num - mod, mod);
    }
}

// randint(void) generates an integer between lower and upper inclusive.
// Side effects: None
// Requires: lower < upper
int randint(int lower, int upper) {
    assert(lower < upper);
    int range = upper - lower;
    return lower + modu(rand(), range);
}

int main(void) {
    
    // Testing harness
    int low, high;
    while (1) {
    scanf("%d", &low);
    scanf("%d", &high);
    printf("%d", randint(low, high));
}}
