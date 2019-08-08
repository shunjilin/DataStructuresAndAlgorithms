#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <unordered_map>
#include <string>

class PhoneBook {
    std::unordered_map<int, std::string> phone_book;
public:
    void add(int number, std::string name) {
        phone_book[number] = name;
    }

    void del(int number) {
        phone_book.erase(number);
    }
    
    std::string find(int number) {
        auto it = phone_book.find(number);
        if (it != phone_book.end()) {
            return it->second;
        }
        return "not found";
    }
};

#endif
