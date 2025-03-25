#include "serialize.h"
#include "deserialize.h"
#include "packets/CustomControllerPacket.h"
#include <assert.h>
CustomControlPacket packet;

void setData() {
    for (uint8_t i = 0; i < 30; i++) {
        packet.data[i] = i;
    }
}

void testHeader(const uint8_t *buffer) {
    assert(buffer[0] == 0xA5 && buffer[1] == 39 && buffer[2] == 0 && "Wrong serialized frame header.");
    assert(buffer[5] == 0x02 && buffer[6] == 0x03 && "Wrong serialized cmd_id");
}

void testData(const uint8_t *buffer) {
    for (uint8_t i = 0; i < 30; i++) {
        assert(buffer[i] == i && "Packet's data being corrupt during serialization.");
    }
}

void testPacket() {
    assert(packet.cmd == 0x0302 && "Packet's cmd is wrong");
    for (uint8_t i = 0; i < 30; i++) {
        assert(packet.data[i] == i && "Packet's data being corrupt during deserialization.");
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
    testHeader(buffer);
    testData(&buffer[7]);
    // Structure Deserialize test
    deserialize(buffer, &packet);
    testPacket();

    return 0;
}
