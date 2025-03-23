#include "packets/CustomControllerPacket.h"
#include "serialize.h"
uint8_t buffer[50] = {};
CustomControlPacket packet = {.cmd = 0x0302};

int main() {
    serialize(&packet, buffer, 50);
    return 0;
}
