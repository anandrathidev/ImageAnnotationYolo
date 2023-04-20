#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <extern/spdlog/include/spdlog/spdlog.h>

namespace IANN
{
    int QTmain(int argc, char* argv[]);
}

int main(int argc, char* argv[])
{
    std::cout << "argc == " << argc << '\n';

    for (int ndx = 0; ndx < argc; ++ndx)
        std::cout << "argv[" << ndx << "] == " << std::quoted(argv[ndx]) << '\n';
        std::cout << "argv[" << argc << "] == " << static_cast<void*>(argv[argc]) << '\n';

    int r = IANN::QTmain(argc, argv);
    return r;
}