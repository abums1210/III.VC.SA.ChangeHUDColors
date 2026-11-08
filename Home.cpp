#include "includes/ColorsConfig.h"
#include "includes/Hooks.h"
#include <plugin.h>

using namespace plugin;

static void OnGameProcess() {
    Hooks::ConfigRefresher();

    if (config.RandomColors != 0) {
        Hooks::ApplyColorHooks();
    }
}

static void OnInitRw() {
    config.Read();
    config.GenerateDefault();
    Hooks::ApplyColorHooks();

    if (config.ReloadKey != 0 || config.RandomColors != 0) {
        Events::gameProcessEvent += OnGameProcess;
    }
}

class Home {
  public:
    Home() {
        Events::initRwEvent += OnInitRw;
    }
} home;
