#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// This program generates a list of arithmetic problems and prints them
//   each on a newline. Then prints a ------ seperator, and prints the
//   answers of each problem

// Generates rand int between lower and upper inclusively
// Side effects: None
// Requires: lower < upper
int randint(int lower, int upper) {
    assert(lower < upper);
    int range = upper - lower;
    return lower + (rand() % range);
}

// pickop(void) returns either '*', '/', '+', xor '-'.
char pickop(void) {
    int val = randint(0, 3);
    if (val == 0) {
        return '+';
    } else if (val == 1) {
        return '-';
    } else if (val == 2) {
        return '*';
    } else {
        return '/';
    }
}

int get_answer(int a, char op, int b) {
    if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else if (op == '*') {
        return a * b;
    } else { // division
        if (b == 0) {
            return -1;
        } else {
            return a/b;
        }
    }
}

int main() {
    fprintf(stderr, "Enter number of questions: ");
    // Number of QuestionS
    int nqs = 0;
    int retval = scanf("%d", &nqs);
    if (retval != 1) {
        fprintf(stderr, "Incorrect input, exiting...");
        return 1;
    }
    
    fprintf(stderr, "Enter lower range of numbers: ");
    int low = 0;
    retval = scanf("%d", &low);
    if (retval != 1) {
        fprintf(stderr, "Incorrect input, exiting...");
        return 1;
    }

    fprintf(stderr, "Enter upper range of numbers: ");
    int high = 0;
    retval = scanf("%d", &high);
    if (retval != 1) {
        fprintf(stderr, "Incorrect input, exiting...");
        return 1;
    }
    
    int  a[nqs]; // To store first param of arith question
    char ops[nqs]; // to store operator
    int  b[nqs]; // to store second param
     
    for (int i = 0; i < nqs; i++) {
        a[i] = randint(low, high);
        ops[i] = pickop();
        b[i] = randint(low, high);
        
        printf("%d\t%c %d\t=\n", a[i], ops[i], b[i]); 
        
    }

    // Since there's already a newline from above
    printf("\n\n-----ANSWERS-----\n\n\n");


    for (int i = 0; i < nqs; i++) {
        printf("%d\t%c %d\t= %d\n", a[i], ops[i], b[i], get_answer(a[i], ops[i], b[i]));
        
    }
}


