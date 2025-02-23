#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
    /* Initialize memory: 256 bytes (8-bit each) */
    // Registers A, B, C, D are located at addresses 5, 6, 7, and 8 respectively
    uint8_t reg[256] = {0};
    int opcode;

    while (1) {
        if (scanf("%d", &opcode) != 1) {
            fprintf(stderr, "Opcode input error.\n");
            exit(EXIT_FAILURE);
        }

        switch (opcode) {
            case 0: // HLT: Terminate the program
                return 0;

            case 1: { // ADD: Add the values in registers
                int r1, r2;
                if (scanf("%d %d", &r1, &r2) != 2) {
                    fprintf(stderr, "ADD arguments input error.\n");
                    exit(EXIT_FAILURE);
                }
                reg[r1] = (uint8_t)(reg[r1] + reg[r2]);
                break;
            }

            case 2: { // SUB: Subtract the value in one register from another
                int r1, r2;
                if (scanf("%d %d", &r1, &r2) != 2) {
                    fprintf(stderr, "SUB arguments input error.\n");
                    exit(EXIT_FAILURE);
                }
                reg[r1] = (uint8_t)(reg[r1] - reg[r2]);
                break;
            }

            case 3: { // MOV: Move a number into a register
                int r, num;
                if (scanf("%d %d", &r, &num) != 2) {
                    fprintf(stderr, "MOV arguments input error.\n");
                    exit(EXIT_FAILURE);
                }
                reg[r] = (uint8_t)num;
                break;
            }

            case 4: // IR: Output the contents of all registers
                printf("%d %d %d %d\n", reg[5], reg[6], reg[7], reg[8]);
                break;

            default:
                fprintf(stderr, "Unknown opcode: %d\n", opcode);
                exit(EXIT_FAILURE);
        }
    }

    return 0;
}

