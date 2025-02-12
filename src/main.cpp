#include "turing_machine.h"
#include "user_interface.h"

using namespace std::literals;

void Test1(){
    turing_machine m;
    user_interface u(m);

    std::string cmd = ">> ^b >> ^b << << << ^a << << ^a & >> >> >> ^^"s;

    u.load_commands(cmd);
    u.execute_commands();
}

void Test2(){
    turing_machine m;
    user_interface u(m);

    std::string cmd = ">> >> >> >> >> >> >> >> >> >>"s;

    u.load_commands(cmd);
    u.execute_commands();
}

int main() {
    Test1();
    //Test2();
    return 0;
}