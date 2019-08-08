#include <gmock/gmock.h>
#include "PhoneBook.hpp"

using namespace testing;

TEST(PhoneBook, addNumberCorrectly) {
    PhoneBook phone_book;
    phone_book.add(911, "police");
    ASSERT_EQ(phone_book.find(911), "police");
}

TEST(PhoneBook, deleteNumberCorrectly) {
    PhoneBook phone_book;
    phone_book.add(17239, "Bob");
    phone_book.del(17239);
    ASSERT_EQ(phone_book.find(17239), "not found");
}

TEST(PhoneBook, ignoreInvalidDelete) {
    PhoneBook phone_book;
    phone_book.add(911, "police");
    phone_book.del(910);
    ASSERT_EQ(phone_book.find(911), "police");
}

TEST(Phone, overwriteNumberCorrectly) {
    PhoneBook phone_book;
    phone_book.add(76213, "Mom");
    phone_book.add(76213, "Dad");
    ASSERT_EQ(phone_book.find(76213), "Dad");
}

int main(int argc, char *argv[]) {
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
