#ifndef CUSTOMCONTROLLERPACKET_H
#define CUSTOMCONTROLLERPACKET_H
#include <stdint.h>
#include <string.h>

typedef struct __attribute__((packed)) {
    const uint16_t cmd; //cmd = 0x0302
    uint8_t data[30];
} CustomControlPacket;

static void init_custom_control_packet(CustomControlPacket *packet) {
    *((uint16_t *) &packet->cmd) = 0x0302; // Cast away const
    memset(packet->data, 0, sizeof(packet->data));
}
#endif //CUSTOMCONTROLLERPACKET_H
