#ifndef XENOSLAVEPACKET_H
#define XENOSLAVEPACKET_H

#include <stdint.h>

typedef struct __attribute__((packed)) {
    const uint16_t cmd;
    // unit: mm
    float lift; // z-axis
    float stretch; //y-axis
    float shift; // x-axis
    // unit: degree/s
    float suck_rotate; // rotate speed of end effector
    // unit: degree
    float r1;
    float r2;
    float r3;
} XenoSlavePacket;

static void init_xeno_slave_packet(XenoSlavePacket *packet) {
    *((uint16_t *) &packet->cmd) = 0x0201;
}

#endif //XENOSLAVEPACKET_H
