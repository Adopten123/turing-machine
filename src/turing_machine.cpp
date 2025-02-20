#include "turing_machine.h"

#include <string>
#include <iostream>

using namespace std::literals;

static const int DELTA_VISION = 5;

void turing_machine::go_left(){
    if(cursor_pos_ == 0) {
        data_.insert(data_.begin(), cell{'_', data_.begin()->number_-1});
        cursor_pos_++;
    }
    cursor_pos_--;
}

void turing_machine::go_right(){
    if(cursor_pos_ == data_.size()-1)
        data_.push_back(cell{'_', (data_.end()-1)->number_+1});
    cursor_pos_++;
}

void turing_machine::set_buffer() {
    buffer_ = data_[cursor_pos_].value_;
}

char turing_machine::get_buffer() {
    return buffer_;
}

void turing_machine::set_current(char c){
    data_[cursor_pos_].value_ = c;
}

void turing_machine::add_left(){
    int delta_size = DELTA_VISION-cursor_pos_;
    //std::cerr << delta_size << std::endl;

    for(int i = 0; i < delta_size; i++)
        data_.insert(data_.begin(), cell {'_',data_.begin()->number_-1});
    cursor_pos_ += delta_size;
}

void turing_machine::add_right(){
    int delta_size = cursor_pos_ + DELTA_VISION - data_.size();
    for(int i = 0; i <= delta_size; i++)
        data_.push_back(cell{'_', (data_.end()-1)->number_+1});
}

void turing_machine::show_data() const{
    for(const auto &c : data_)
        std::cerr << c.value_ << " "s;
    std::cerr << std::endl;
}

void turing_machine::show(){
    if (cursor_pos_ - DELTA_VISION < 0)
        add_left();

    if (cursor_pos_ + DELTA_VISION >= data_.size())
        add_right();

    std::string result = ""s;
    std::string result_num = ""s;

    //std::cerr << cursor_pos_ << "\t"s << data_.size() << std::endl;

//    for (const auto& ch : data_) {
//        if (data_.begin()->number_ + cursor_pos_ == ch.number_)
//            result += "["s + ch.value_ + "]"s+ "\t"s;
//        else
//            result += ch.value_ + "\t"s;
//
//        result_num += std::to_string(ch.number_) + "\t"s;
//    }

    for (std::size_t i = cursor_pos_ - DELTA_VISION; i <= cursor_pos_ + DELTA_VISION; i++){
        if (data_.begin()->number_ + cursor_pos_ == data_[i].number_)
            result += "["s + data_[i].value_ + "]"s+ "\t"s;
        else
            result += data_[i].value_ + "\t"s;

        result_num += std::to_string(data_[i].number_) + "\t"s;
    }

    std::cout << result << std::endl;
    std::cout << result_num << std::endl;
    //show_data();
}