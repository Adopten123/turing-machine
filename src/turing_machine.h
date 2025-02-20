#pragma once

#include <cstddef>
#include <vector>

struct cell {
    char value_;
    int number_;
};

class turing_machine {

private:
    std::vector<cell> data_ = { cell{'_', 0} };
    int cursor_pos_ = 0;
    char buffer_;

    void add_left();
    void add_right();

    void show_data() const;
public:
    turing_machine() = default;

    void go_left();
    void go_right();

    void set_buffer();
    char get_buffer();

    void set_current(char c);

    void show();
};
