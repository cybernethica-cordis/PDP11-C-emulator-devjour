#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
    /* Memory initialization: 256 cells of 8 bits */
    // Registers A, B, C, D are located at addresses 5, 6, 7, 8
    uint8_t reg[256] = {0};
    int opcode;

    while (1) {
        if (scanf("%d", &opcode) != 1) {
            fprintf(stderr, "Input error: Invalid opcode.\n");
            exit(EXIT_FAILURE);
        }

        switch (opcode) {
            case 0: // HLT: Terminate program execution
                return 0;

            case 1: { // ADD: Addition of registers
                int r1, r2;
                if (scanf("%d %d", &r1, &r2) != 2) {
                    fprintf(stderr, "Input error: Invalid operands for ADD.\n");
                    exit(EXIT_FAILURE);
                }
                reg[r1] = (uint8_t)(reg[r1] + reg[r2]);
                break;
            }

            case 2: { // SUB: Subtraction
                int r1, r2;
                if (scanf("%d %d", &r1, &r2) != 2) {
                    fprintf(stderr, "Input error: Invalid operands for SUB.\n");
                    exit(EXIT_FAILURE);
                }
                reg[r1] = (uint8_t)(reg[r1] - reg[r2]);
                break;
            }

            case 3: { // MOV: Write a number to a register
                int r, num;
                if (scanf("%d %d", &r, &num) != 2) {
                    fprintf(stderr, "Input error: Invalid operands for MOV.\n");
                    exit(EXIT_FAILURE);
                }
                reg[r] = (uint8_t)num;
                break;
            }

            case 4: // IR: Output the contents of registers
                printf("%d %d %d %d\n", reg[5], reg[6], reg[7], reg[8]);
                break;

            default:
                fprintf(stderr, "Unknown opcode: %d\n", opcode);
                exit(EXIT_FAILURE);
        }
    }

    return 0;
}

