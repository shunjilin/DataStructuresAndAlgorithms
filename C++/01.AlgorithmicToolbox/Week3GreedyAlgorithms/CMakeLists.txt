add_executable(MoneyChangeStressTest MoneyChangeStressTest.cpp)
add_executable(FractionalKnapsackUnitTest FractionalKnapsackUnitTest.cpp)
add_executable(MaxDotProductStressTest MaxDotProductStressTest.cpp)
add_executable(CoveringSegmentsUnitTest CoveringSegmentsUnitTest.cpp)
add_executable(DifferentSummandsUnitTest DifferentSummandsUnitTest.cpp)
add_executable(LargestNumberUnitTest LargestNumberUnitTest.cpp)
add_executable(LargestNumberStressTest LargestNumberStressTest.cpp)

target_link_libraries(FractionalKnapsackUnitTest gmock pthread)
target_link_libraries(CoveringSegmentsUnitTest gmock pthread)
target_link_libraries(DifferentSummandsUnitTest gmock pthread)
target_link_libraries(LargestNumberUnitTest gmock pthread)

add_test(FractionalKnapsackUnitTest FractionalKnapsackUnitTest)
add_test(CoveringSegmentsUnitTest CoveringSegmentsUnitTest)
add_test(DifferentSummandsUnitTest DifferentSummandsUnitTest)
add_test(LargestNumberUnitTest LargestNumberUnitTest)
