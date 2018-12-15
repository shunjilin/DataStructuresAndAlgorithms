#ifndef NETWORK_PACKET_PROCESSING_SIMULATION_HPP
#define NETWORK_PACKET_PROCESSING_SIMULATION_HPP

#include <deque>
#include <queue>
#include <vector>

struct Packet {
    int arrival_time;
    int processing_time;
    int finish_time;
    Packet(int arrival_time, int processing_time) :
        arrival_time(arrival_time), processing_time(processing_time) {}
    void setFinishTime(int start_process_time) {
        finish_time = start_process_time + processing_time;
    }
};

// return processing start times of packets, given packets and buffer capacity,
// assumes only 1 packet can be processed at a time.
// processing start time = -1 for dropped packet
std::vector<int>
processPackets(std::queue<Packet> & packets, uint buffer_capacity) {
    int time = 0;

    std::vector<int> start_process_times;
    std::deque<Packet> buffer;

    while (!packets.empty()) {
        auto packet = packets.front();
        if (packet.arrival_time > time) {
            time = packet.arrival_time;
        }
        // remove processed packets
        while (!buffer.empty() && buffer.front().finish_time <= time) {
            buffer.pop_front();
        }

        if (buffer.size() < buffer_capacity) {
            uint start_process_time = time;
            if (!buffer.empty()) {
                // process starts after last packet in buffer
                start_process_time = buffer.back().finish_time;
            }
            start_process_times.push_back(start_process_time);
            packet.setFinishTime(start_process_time);
            buffer.emplace_back(packet);
        } else {
            start_process_times.push_back(-1);
        }
        packets.pop();
    }
    return start_process_times;
}

#endif
