#include "serialize.h"
#include "deserialize.h"
#include "packets/XenoMasterPacket.h"

#include <assert.h>

XenoMasterPacket packet;

int main() {
    init_xeno_master_packet(&packet);
    packet.status = MasterReady;
    uint8_t buffer[30];
    assert(serialize(&packet, buffer, 30) && "Serialize function does not return 1");
    return 0;
}
