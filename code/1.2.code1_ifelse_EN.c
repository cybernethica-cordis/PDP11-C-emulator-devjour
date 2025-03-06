#include <stdio.h>
#include <stdint.h>

int main() {
    /* Memory initialization: 256 cells of 8 bits. Registers A, B, C, D are at addresses 5-8 */
    uint8_t reg[256] = {0};
    int opcode;

    /* Main loop: read and interpret instructions */
    while (scanf("%d", &opcode) == 1) {
        if (opcode == 0) {
            // HLT: Stop execution
            break;
        } else if (opcode == 1) {
            // ADD r1 r2: A[r1] = (A[r1] + A[r2]) % 256
            int r1, r2;
            scanf("%d %d", &r1, &r2);
            reg[r1] = (uint8_t)(reg[r1] + reg[r2]);
        } else if (opcode == 2) {
            // SUB r1 r2: A[r1] = (A[r1] - A[r2]) % 256
            int r1, r2;
            scanf("%d %d", &r1, &r2);
            reg[r1] = (uint8_t)(reg[r1] - reg[r2]);
        } else if (opcode == 3) {
            // MOV r num: A[r] = num (limited to 8 bits)
            int r, num;
            scanf("%d %d", &r, &num);
            reg[r] = (uint8_t)num;
        } else if (opcode == 4) {
            // IR: Output the values of registers A, B, C, D
            printf("%d %d %d %d\n", reg[5], reg[6], reg[7], reg[8]);
        }
    }

    return 0;
}

