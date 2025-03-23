#include "packets/CustomControllerPacket.h"
#include "serialize.h"
uint8_t buffer[50] = {};
CustomControlPacket packet;

int main() {
    init_custom_control_packet(&packet);
    serialize(&packet, buffer, 50);
    return 0;
}
