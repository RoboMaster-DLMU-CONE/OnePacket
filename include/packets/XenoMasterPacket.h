#ifndef XENOMASTERPACKET_H
#define XENOMASTERPACKET_H
#include <stdint.h>

typedef enum __attribute__((packed)) {
    MasterReady = 1,
    MasterUnstable = 2,
    MasterCrashed = 3,
} XenoMasterStatus;

typedef struct __attribute__((packed)) {
    const uint16_t cmd;
    XenoMasterStatus status;
} XenoMasterPacket;

static void init_xeno_master_packet(XenoMasterPacket *packet) {
    *((uint16_t *) &packet->cmd) = 0x0101;
}

#endif //XENOMASTERPACKET_H
