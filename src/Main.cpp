#include <iostream>
#include <efuse_board/Dummy.hpp>

int main(int argc, char** argv)
{
    efuse_board::DummyClass dummyClass;
    dummyClass.welcome();

    return 0;
}
