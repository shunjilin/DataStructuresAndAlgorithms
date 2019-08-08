#include <gmock/gmock.h>
#include "ParallelProcessing.hpp"

using namespace testing;

TEST(ParallelProcessing, CorrectNumberOfJobsProcessed) {
    auto jobs = std::vector<Job>({1, 2, 3, 4, 5});
    ASSERT_EQ(getProcessedJobTimestamps(2, jobs),
              std::vector<JobTimestamp>({{0, 0}, {1, 0}, {0, 1}, {1, 2}, {0, 4}}));
}

int main(int argc, char *argv[]) {
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
