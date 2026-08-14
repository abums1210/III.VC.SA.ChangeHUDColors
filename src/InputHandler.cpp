#include "../includes/InputHandler.h"
#include "../includes/ColorsConfig.h"
#include "../includes/ProcessHelper.h"
#include <windows.h>

typedef SHORT(WINAPI* fnGetKeyState)(int);
static fnGetKeyState pGetKeyState = nullptr;

static bool MyKeyPressed(unsigned int keyCode) {
    if (!pGetKeyState) {
        pGetKeyState = (fnGetKeyState)ProcessHelper::GetFunc("user32.dll", "GetKeyState");
    }
    if (pGetKeyState) {
        return (pGetKeyState(keyCode) & 0x8000) != 0;
    }
    return false;
}

bool InputHandler::oldKeyState[256] = { false };

__declspec(noinline) bool InputHandler::IsKeyJustPressed(unsigned int key) {
    if (key >= 256) return false;
    bool current = MyKeyPressed(key);
    bool pressed = current && !oldKeyState[key];
    if (current) {
        oldKeyState[key] = true;
    }
    return pressed;
}

void InputHandler::UpdateOldKeyState() {
    if (config.ReloadKey > 0 && config.ReloadKey < 256) {
        if (!MyKeyPressed(config.ReloadKey)) {
            oldKeyState[config.ReloadKey] = false;
        }
    }
}
