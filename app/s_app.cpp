#include "neko.h"

class SboxApp : public NEKO::Application{
    public:
        SboxApp()
        {

        }

        ~SboxApp()
        {

        }
};

NEKO::Application *NEKO::CreateApplication()
{
    return new SboxApp();
}
