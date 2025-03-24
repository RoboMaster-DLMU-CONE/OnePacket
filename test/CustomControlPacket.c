#include "serialize.h"
#include "packets/CustomControllerPacket.h"
#include <assert.h>
#include <stdbool.h>

CustomControlPacket packet;

void setData() {
    for (uint8_t i = 0; i < 30; i++) {
        packet.data[i] = i;
    }
}

void testData(const uint8_t *buffer) {
    for (uint8_t i = 0; i < 30; i++) {
        assert(buffer[i] == i && "Packet's data being corrupt during serialization.");
    }
}

int main() {
    //Structure init test
    init_custom_control_packet(&packet);
    setData();
    assert(packet.cmd == 0x0302 && "Packet's init cmd is not correct.");
    //Structure Serialize test
    uint8_t buffer[CustomControllerPacketBufferLength];
    assert(serialize(&packet, buffer, CustomControllerPacketBufferLength) == 1 && "Serialize function returned error.");
    assert(buffer[0] == 0xA5 && buffer[1] == 39 && buffer[2] == 0 && "Wrong serialized frame header.");
    assert(buffer[5] == 0x02 && buffer[6] == 0x03 && "Wrong serialized cmd_id");
    testData(&buffer[7]);
    //Structure Deserialize test

    return 0;
}
