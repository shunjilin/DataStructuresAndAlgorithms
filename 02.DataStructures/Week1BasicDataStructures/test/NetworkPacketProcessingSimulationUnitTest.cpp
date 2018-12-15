#include <gmock/gmock.h>
#include "NetworkPacketProcessingSimulation.hpp"

using namespace testing;

TEST(NetworkPacketProcessingSimulation, noPacket) {
    std::queue<Packet> packets;
    uint buffer_capacity = 1;
    ASSERT_EQ(processPackets(packets, buffer_capacity),
              std::vector<int>());
}

TEST(NetworkPacketProcessingSimulation, onePacket) {
    std::queue<Packet> packets{{Packet{0, 0}}};
    uint buffer_capacity = 1;
    ASSERT_EQ(processPackets(packets, buffer_capacity), std::vector<int>({0}));
}

TEST(NetworkPacketProcessingSimulation, twoPackets) {
    std::queue<Packet> packets{{Packet{0, 1}, Packet{1, 1}}};
    uint buffer_capacity = 1;
    ASSERT_EQ(processPackets(packets, buffer_capacity),
              std::vector<int>({0, 1}));
}

TEST(NetworkPacketProcessingSimulation, twoPacketsWithDropped) {
    std::queue<Packet> packets{{Packet{0, 1}, Packet{0, 1}}};
    uint buffer_capacity = 1;
    ASSERT_EQ(processPackets(packets, buffer_capacity),
              std::vector<int>({0, -1}));
}

TEST(NetworkPacketProcessingSimulation, sixPackets) {
    std::queue<Packet> packets{
        {Packet{0, 2}, Packet{1, 2}, Packet{2, 2}, Packet{3, 2}, Packet{4, 2}, Packet{5, 2}}};
    uint buffer_capacity = 3;
    ASSERT_EQ(processPackets(packets, buffer_capacity),
              std::vector<int>({0, 2, 4, 6, 8, -1}));
}

int main(int argc, char *argv[]) {
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
