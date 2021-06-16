// Here's an example using a 24LC256 on a GR PEACH
#include "mbed.h"
#include "I2CEEBlockDevice.h"
// Create EEPROM device on I2C bus with 32kbytes of memory
I2CEEBlockDevice i2cee(D14, D15, 0xa0, 32*1024);
int main() {
    printf("i2cee test\n");
    // Initialize the device and print the memory layout
    i2cee.init();
    printf("i2cee size: %llu\n",         i2cee.size());
    printf("i2cee read size: %llu\n",    i2cee.get_read_size());
    printf("i2cee program size: %llu\n", i2cee.get_program_size());
    printf("i2cee erase size: %llu\n",   i2cee.get_erase_size());
    // Write "Hello World!" to the first block
    char *buffer = (char*)malloc(i2cee.get_erase_size());
    sprintf(buffer, "Hello World!\n");
    i2cee.erase(0, i2cee.get_erase_size());
    i2cee.program(buffer, 0, i2cee.get_erase_size());
    // Read back what was stored
    i2cee.read(buffer, 0, i2cee.get_erase_size());
    printf("%s", buffer);
    // Deinitialize the device
    i2cee.deinit();
}