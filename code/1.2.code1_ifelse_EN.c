#include <stdio.h>
#include <stdint.h>

int main() {
    /* Initialize the memory of machine "Q": 256 bytes (8-bit each) */
    // Registers A, B, C, D are located at addresses 5, 6, 7, and 8 respectively
    uint8_t reg[256] = {0};
    int opcode;
    
    /* Main loop for processing the bytecode */
    // Read the opcode and execute the corresponding instruction
    while (scanf("%d", &opcode) == 1) {
        if (opcode == 0) {
            // HLT: Terminate the program
            break;
        } else if (opcode == 1) {
            // ADD: Add the values of the registers
            // Read the register addresses: r1 (where to store the sum) and r2 (from which to take the second operand)
            int r1, r2;
            scanf("%d %d", &r1, &r2);
            // Perform addition modulo 256
            reg[r1] = (uint8_t)(reg[r1] + reg[r2]);
        } else if (opcode == 2) {
            // SUB: Subtract the value of the second register from the first
            int r1, r2;
            scanf("%d %d", &r1, &r2);
            // Perform subtraction with modulo 256 arithmetic
            reg[r1] = (uint8_t)(reg[r1] - reg[r2]);
        } else if (opcode == 3) {
            // MOV: Move a number into the specified register
            // Read the register address and the number to be written
            int r, num;
            scanf("%d %d", &r, &num);
            reg[r] = (uint8_t)num;
        } else if (opcode == 4) {
            // IR: Output the contents of registers A, B, C, D
            // Register A is at address 5, B at 6, C at 7, and D at 8
            printf("%d %d %d %d\n", reg[5], reg[6], reg[7], reg[8]);
        }
    }
    
    return 0;
}

