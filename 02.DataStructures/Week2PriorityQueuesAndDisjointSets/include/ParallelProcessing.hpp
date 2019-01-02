#ifndef PARALLEL_PROCESSING_HPP
#define PARALLEL_PROCESSING_HPP

#include <vector>
#include <utility>
#include <algorithm>

// thread_id, time job processed pair
using JobTimestamp = std::pair<size_t, unsigned long>;

// thread keeps track of cumulative time spent on job
struct Thread {
    size_t index;
    unsigned long time = 0;
    Thread(size_t index) : index(index) {}
    // for min heap, highest priority is thread with lowest time, if tie,
    // pick thread with lowest index
    bool operator > (const Thread& other) const {
        if (time == other.time ) {
            return index > other.index;
        } else {
            return time > other.time;
        }
    }
};

// each job has time it takes to complete
struct Job {
    unsigned long time;
    Job(unsigned long time) : time(time) {}
};

// priority queue for thread workers
class ThreadQueue {
public:
    ThreadQueue(size_t n_threads) {
        for (size_t i = 0; i < n_threads; ++i) {
            threads.emplace_back(i);
        }
        std::make_heap(threads.begin(), threads.end(), std::greater<Thread>());
    }

private:
    std::vector<Thread> threads;

public:
    // process a job using the highest priority thread and returns a timestamp
    // pair (thread id, start time of processing job)
    JobTimestamp processJob(Job const job) {
        std::pop_heap(threads.begin(), threads.end(), std::greater<Thread>());
        auto thread = threads.back();
        threads.pop_back();
        auto job_timestamp = std::make_pair(thread.index, thread.time);
        thread.time += job.time;
        threads.push_back(thread);
        std::push_heap(threads.begin(), threads.end(), std::greater<Thread>());
        return job_timestamp;
    }
};

// get all timestamp pairs (thread id, start time of processing job) for
// processing all jobs with n number of threads
std::vector<JobTimestamp>
getProcessedJobTimestamps(size_t n_threads, std::vector<Job> const & jobs) {
    auto thread_queue = ThreadQueue(n_threads);
    auto job_timestamps = std::vector<JobTimestamp>();
    for (auto const job : jobs) {
        job_timestamps.push_back(thread_queue.processJob(job));
    }
    return job_timestamps;
}

#endif
