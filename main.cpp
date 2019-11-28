#include "LinuxServer.hpp"

int main(int argc, char** argv)
{
    LinuxServer server("192.168.216.230");
    server.Start();

    return 0;
}