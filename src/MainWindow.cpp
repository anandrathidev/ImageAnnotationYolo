#include "App.h"
#include <core/IANNErrors.h>
#include <exception>

namespace IANN
{
    int QTmain(int argc, char* argv[])
    {
        try
        {
            MainApp mainapp(argc, argv);
            // blocking
            mainapp.RunApp();
        }
        catch (std::exception& e)
        {
            return ERRORSCODE::QTFAILED;
        }
        return 0;

    }
}