#pragma once

#include <turing_machine.h>
#include <string>
#include <vector>
#include <memory>

class user_interface {
private:
    std::unique_ptr<turing_machine> machine_ptr_;
    std::vector<std::string> commands_;
public:
    void load_commands(const std::string& commands);
    void load_commands();
    user_interface(const turing_machine& machine);

    void execute_commands();
};
