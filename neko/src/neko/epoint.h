#pragma once

// the application is defined elsewhere in client side
extern NEKO::Application* NEKO::CreateApplication();

int main(int argc, char** argv)
{
    NEKO::Log::Init();
    //NEKO::Log::GetCoreLogger()->info("Neko started");
    NEKO_CORE_INFO("NEKO Started");
    auto app = NEKO::CreateApplication(); // create a main object
    app->run();
    delete app;
}
