#include "user_interface.h"

#include <iostream>
#include <sstream>

using namespace std::literals;

void user_interface::load_commands(){
    std::string commands;
    std::cout << "Enter commands: "s << std::endl;
    std::getline(std::cin, commands);

    load_commands(commands);
}

void user_interface::load_commands(const std::string& commands){
    std::istringstream iss(commands);
    std::string cmd;

    while (iss >> cmd)
        commands_.push_back(cmd);
}
user_interface::user_interface(const turing_machine& machine)
    : machine_ptr_(std::make_unique<turing_machine>(machine)){
}

void user_interface::execute_commands() {

    for (const auto& cmd : commands_) {
        if (cmd == "<<"s)
            machine_ptr_->go_left();
        else if (cmd == ">>"s)
            machine_ptr_->go_right();
        else if (cmd == "^^"s)
            machine_ptr_->set_current(machine_ptr_->get_buffer());
        else if (cmd[0] == '^')
            machine_ptr_->set_current(cmd[1]);
        else if (cmd == "&"s)
            machine_ptr_->set_buffer();
//        std::cerr << cmd << ": "s;
//        machine_ptr_->show();
    }

    machine_ptr_->show();
    commands_.clear();
}