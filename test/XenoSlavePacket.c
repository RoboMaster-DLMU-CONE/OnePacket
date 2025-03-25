#include "serialize.h"
#include "deserialize.h"
#include "packets/XenoSlavePacket.h"

#include <assert.h>

XenoSlavePacket packet;

void setData() {
    packet.lift = 0.1f;
    packet.stretch = 0.2f;
    packet.shift = 0.3f;
    packet.suck_rotate = 40.0f;
    packet.r1 = 50.0f;
    packet.r2 = 60.0f;
    packet.r3 = 70.0f;
}

void testPacket() {
    assert(packet.lift == 0.1f&&
        packet.stretch == 0.2f&&
        packet.shift == 0.3f&&
        packet.suck_rotate == 40.0f&&
        packet.r1 == 50.0f&&
        packet.r2 == 60.0f&&
        packet.r3 == 70.0f&& "Data is being corrupted.");
}

int main() {
    init_xeno_slave_packet(&packet);
    setData();
    uint8_t buffer[30];
    assert(serialize(&packet, buffer, 30) == 1 && "Serialize function does not return 1");

    assert((buffer[0] + (buffer[1] << 8)) == packet.cmd && "CMD is being corrupted.");

    assert((deserialize(buffer, &packet)) && "Deserialize function does not return 1");
    testPacket();


    return 0;
}
