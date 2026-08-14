#include "includes/ColorsConfig.h"
#include "includes/Hooks.h"
#include <plugin.h>

using namespace plugin;

static void OnGameProcess() {
    Hooks::ConfigRefresher();

    if (config.RandomColors != 0) {
#ifdef GTA3
        Hooks::ColorsHooksIII();
#elif defined(GTAVC)
        Hooks::ColorsHooksVC();
#else
        Hooks::ColorsHooksSA();
#endif
    }
}

static void OnInitRw() {
    config.Read();
    config.GenerateDefault();

#ifdef GTA3
    Hooks::ColorsHooksIII();
#elif defined(GTAVC)
    Hooks::ColorsHooksVC();
#else
    Hooks::ColorsHooksSA();
#endif

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
