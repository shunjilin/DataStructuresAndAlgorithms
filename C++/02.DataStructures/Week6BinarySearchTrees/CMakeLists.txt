add_executable(BinaryTreeTraversalsUnitTest BinaryTreeTraversalsUnitTest.cpp)
target_link_libraries(BinaryTreeTraversalsUnitTest gmock pthread)
add_test(BinaryTreeTraversalsUnitTest BinaryTreeTraversalsUnitTest)

add_executable(CheckValidBinaryTreeUnitTest CheckValidBinaryTreeUnitTest.cpp)
target_link_libraries(CheckValidBinaryTreeUnitTest gmock pthread)
add_test(CheckValidBinaryTreeUnitTest CheckValidBinaryTreeUnitTest)

add_executable(CheckValidBinaryTreeHardUnitTest CheckValidBinaryTreeHardUnitTest.cpp)
target_link_libraries(CheckValidBinaryTreeHardUnitTest gmock pthread)
add_test(CheckValidBinaryTreeHardUnitTest CheckValidBinaryTreeHardUnitTest)
