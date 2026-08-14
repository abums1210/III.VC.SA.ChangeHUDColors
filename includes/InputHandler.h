#pragma once

class InputHandler {
public:
    static bool oldKeyState[256];

    __declspec(noinline) static bool IsKeyJustPressed(unsigned int key);
    static void UpdateOldKeyState();

    static void ResetKeyState() {
        for (int i = 0; i < 256; i++) oldKeyState[i] = false;
    }
};
