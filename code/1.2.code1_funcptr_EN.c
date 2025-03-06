#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Memory initialization: 256 cells of 8 bits */
uint8_t reg[256] = {0};

/* Functions corresponding to operations */
void hlt() {
    exit(0);
}

void add() {
    int r1, r2;
    if (scanf("%d %d", &r1, &r2) != 2) {
        fprintf(stderr, "Input error: Invalid operands for ADD.\n");
        exit(EXIT_FAILURE);
    }
    reg[r1] = (uint8_t)(reg[r1] + reg[r2]);
}

void sub() {
    int r1, r2;
    if (scanf("%d %d", &r1, &r2) != 2) {
        fprintf(stderr, "Input error: Invalid operands for SUB.\n");
        exit(EXIT_FAILURE);
    }
    reg[r1] = (uint8_t)(reg[r1] - reg[r2]);
}

void mov() {
    int r, num;
    if (scanf("%d %d", &r, &num) != 2) {
        fprintf(stderr, "Input error: Invalid operands for MOV.\n");
        exit(EXIT_FAILURE);
    }
    reg[r] = (uint8_t)num;
}

void ir() {
    printf("%d %d %d %d\n", reg[5], reg[6], reg[7], reg[8]);
}

/* Array of function pointers */
void (*operations[5])() = {hlt, add, sub, mov, ir};

/* Main program function */
int main() {
    int opcode;

    while (scanf("%d", &opcode) == 1) {
        if (opcode < 0 || opcode > 4) {
            fprintf(stderr, "Unknown opcode: %d\n", opcode);
            exit(EXIT_FAILURE);
        }
        operations[opcode](); // Call corresponding function
    }

    return 0;
}

