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

void Test3(){
    turing_machine m;
    user_interface u(m);

    std::string cmd = "<< << << << << << << << << <<"s;

    u.load_commands(cmd);
    u.execute_commands();
}

void Task1(){
    turing_machine m;
    user_interface u(m);

    std::string cmd = "^1 >> ^0 >> ^1 << << & ? >> & ? >> & ? >> & ? ^0 >> ^0"s;

    u.load_commands(cmd);
    u.execute_commands();
}

void Task2(){
    turing_machine m;
    user_interface u(m);

    std::string cmd = "^1 >> ^0 >> ^1 >> ^1 << << << & ? >> & ? >> & ? >> & ? >> & ? << ^_"s;

    u.load_commands(cmd);
    u.execute_commands();
}

void Task3(){
    turing_machine m;
    user_interface u(m);

    std::string cmd = "^1 >> ^0 >> ^1 >> ^1 << << << & ? << >> & << ^^"s;

    u.load_commands(cmd);
    u.execute_commands();
}
int main() {
    //Test1();
    //Test2();
    //Test3();

    Task1();
    Task2();
    Task3();
    return 0;
}