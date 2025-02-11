#include <cstddef>
#include <vector>

class turing_machine {
public:
    turing_machine() = default;

    void go_left();
    void go_right();

    char get_current() const;
    void set_current(char c);

    void show() const;
private:
    std::vector<char> data_(100);
    std::size_t cursor_pos_ = 50;
};
