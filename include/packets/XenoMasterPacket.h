#ifndef XENOMASTERPACKET_H
#define XENOMASTERPACKET_H
#include <stdint.h>

enum uint8_t XenoMasterStatus {
    MasterReady = 1,
    MasterUnstable = 2,
    MasterCrashed = 3,
};

typedef struct __attribute__((packed)) {
    const uint16_t cmd;
    uint8_t headerCRC8{};

    enum XenoMasterStatus status;

    uint16_t tailCRC16{};
} XenoMasterPacket;

static void init_xeno_master_packet(XenoMasterPacket *packet) {
    *((uint16_t *) &packet->cmd) = 0x0101;
}

#endif //XENOMASTERPACKET_H
