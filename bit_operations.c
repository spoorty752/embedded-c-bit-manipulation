#include <stdio.h>
#include <stdint.h>

/*
 * Embedded C Bit Manipulation
 * Author: Spoorthi
 *
 * Demonstrates:
 * - Set bit
 * - Clear bit
 * - Toggle bit
 * - Read bit
 */

#define SET_BIT(reg, bit)       ((reg) |=  (1U << (bit)))
#define CLEAR_BIT(reg, bit)     ((reg) &= ~(1U << (bit)))
#define TOGGLE_BIT(reg, bit)    ((reg) ^=  (1U << (bit)))
#define READ_BIT(reg, bit)      (((reg) >> (bit)) & 1U)

void print_binary(uint8_t value)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (value >> i) & 1U);
    }

    printf("\n");
}

int main(void)
{
    uint8_t register_value = 0;

    printf("Initial register: ");
    print_binary(register_value);

    SET_BIT(register_value, 3);
    printf("After SET bit 3:  ");
    print_binary(register_value);

    SET_BIT(register_value, 5);
    printf("After SET bit 5:  ");
    print_binary(register_value);

    CLEAR_BIT(register_value, 3);
    printf("After CLEAR bit 3:");
    printf(" ");
    print_binary(register_value);

    TOGGLE_BIT(register_value, 5);
    printf("After TOGGLE bit 5:");
    printf(" ");
    print_binary(register_value);

    printf("Bit 5 status: %u\n", READ_BIT(register_value, 5));

    return 0;
}
