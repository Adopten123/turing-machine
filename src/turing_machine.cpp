#include "turing_machine.h"

#include <string>

using namespace std::literals;

void turing_machine::go_left(){
    if(cursor_pos_ == 0)
        cursor_pos_ = data_.size();
    else
        cursor_pos_--;
}

void turing_machine::go_right(){
    if(cursor_pos_ == data_.size()-1)
        cursor_pos_ = 0;
    else
        cursor_pos_++;
}

char turing_machine::get_char(){
    return data_[cursor_pos_];
}

void turing_machine::set_char(char c){
    data_[cursor_pos_] = c;
}

void turing_machine::show(){
    std::string result = "";

    if (cursor_pos_ - 5 >= 0 and cursor_pos_ < data_.size()) {
        for (int i = cursor_pos_ - 5; i <= cursor_pos_ + 5; ++i) {
            result = data_[cursor_pos_ - 5 + i] + " "s;
        }
    }
    else if (cursor_pos_ - 5 >= 0) {
        int i =
    }

}