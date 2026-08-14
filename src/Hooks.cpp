#include <cstdlib>
#include "../includes/Hooks.h"
#include "../includes/ColorsConfig.h"
#include "../includes/SomeMacros.h"
#ifdef GTASA
#include <CHudColours.h>
#endif

using namespace plugin;

static uint32_t callCounter = 0;

static uint32_t Hash32(uint32_t x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

static CRGBA GetColorToApply(CRGBA const &clr) {
    uint32_t now, delay, step, h;
    uint8_t r, g, b;
    float speed;

    if (config.RandomColors != 0) {
        now = GetTickCount();
        speed = config.RandomColorsSpeed;
        if (speed <= 0.0f)
            speed = 1.0f;
        delay = (uint32_t)(16.666f / speed);
        if (delay == 0)
            delay = 1;
        step = now / delay;

        h = Hash32(step + (callCounter++ * 0x9e3779b9));
        r = (uint8_t)(h & 0xFF);
        g = (uint8_t)((h >> 8) & 0xFF);
        b = (uint8_t)((h >> 16) & 0xFF);

        return CRGBA(r, g, b, clr.a);
    }
    return clr;
}

static void WriteColor(unsigned int addrR, unsigned int addrG, unsigned int addrB, int addrA, CRGBA const &clr) {
    CRGBA colorToUse;

    colorToUse = GetColorToApply(clr);

    patch::SetUChar(addrR, colorToUse.r);
    patch::SetUChar(addrG, colorToUse.g);
    patch::SetUChar(addrB, colorToUse.b);
    if (addrA != -1 && addrA != 0) {
        patch::SetUChar(addrA, colorToUse.a);
    }
}

#ifdef GTASA
static void WriteColorSA(unsigned char colorIndex, CRGBA const &clr) {
    CRGBA colorToUse;

    colorToUse = GetColorToApply(clr);

    HudColour.SetRGBAValue(colorIndex, colorToUse.r, colorToUse.g, colorToUse.b, colorToUse.a);
}
#endif
    
#ifdef GTAVC
void Hooks::ColorsHooksVC() {
    callCounter = 0;

    // Money Main & Shadow
    WriteColor(0x5582AF, 0x5582AA, 0x5582A5, -1, config.Colors.MoneyColor);
    WriteColor(0x558263, 0x558261, 0x55825F, -1, config.Colors.MoneyShadowColor);

    // Ammo Main & Shadow
    WriteColor(0x5588C2, 0x5588BD, 0x5588B8, -1, config.Colors.AmmoColor);
    WriteColor(0x558876, 0x558874, 0x558872, -1, config.Colors.AmmoShadowColor);

    // Health, Armor, Wanted Shadow
    WriteColor(0x558A08, 0x558A06, 0x558A04, 0x5589FF, config.Colors.HAWShadowColor);

    // Health Main & Icon
    WriteColor(0x558BA9, 0x558BA4, 0x558B9F, 0x558B9A, config.Colors.HealthColor);
    WriteColor(0x558C8E, 0x558C66, 0x558C61, 0x558C56, config.Colors.HealthIconColor);

    // Armor Main & Icon
    WriteColor(0x558E26, 0x558E21, 0x558E1C, 0x558E17, config.Colors.ArmorColor);
    WriteColor(0x558EFE, 0x558ED6, 0x558ED1, 0x558EC6, config.Colors.ArmorIconColor);

    // Wanted Active, Suspended & Inactive Stars
    WriteColor(0x5590CA, 0x5590C5, 0x5590C0, -1, config.Colors.WantedActiveColor);
    WriteColor(0x559128, 0x559123, 0x55911E, -1, config.Colors.WantedSuspendedColor);
    WriteColor(0x559170, 0x55916E, 0x559169, -1, config.Colors.WantedInactiveColor);

    // Zone Main & Shadow
    WriteColor(0x559954, 0x55994F, 0x55994D, -1, config.Colors.ZoneColor);
    WriteColor(0x559903, 0x559901, 0x5598FF, -1, config.Colors.ZoneShadowColor);

    // Vehicle Main & Shadow
    WriteColor(0x559DE3, 0x559DDE, 0x559DD9, -1, config.Colors.VehicleColor);
    WriteColor(0x559E29, 0x559E27, 0x559E25, -1, config.Colors.VehicleShadowColor);

    // Time (Clock) Main & Shadow
    WriteColor(0x559F91, 0x559F8C, 0x559F87, 0x559F82, config.Colors.TimeColor);
    WriteColor(0x559F2D, 0x559F2B, 0x559F29, 0x559F24, config.Colors.TimeShadowColor);

    // Brief & Help Message Box Text & Shadow
    WriteColor(0x55B542, 0x55B53D, 0x55B538, 0x55B533, config.Colors.BriefTextColor);
    WriteColor(0x55B5E4, 0x55B5E2, 0x55B5E0, -1, CRGBA(0, 0, 0, 255));
    WriteColor(0x55B60F, 0x55B60A, 0x55B605, 0x55B600, config.Colors.HelpTextColor);
    WriteColor(0x55B7C0, 0x55B7BB, 0x55B7B9, -1, config.Colors.BriefTextColor);
    WriteColor(0x55B990, 0x55B98E, 0x55B98C, -1, CRGBA(0, 0, 0, 255));

    // Subtitles Main & Shadow
    WriteColor(0x55AEB8, 0x55AEB3, 0x55AEAE, 0x55AEA9, config.Colors.SubtitleColor);
    WriteColor(0x55AFEF, 0x55AFED, 0x55AFEB, 0x55AFE6, config.Colors.SubtitleShadowColor);

    // OnScreen Timer Clock Digits Main & Shadow
    WriteColor(0x55A186, 0x55A181, 0x55A17C, 0x55A177, config.Colors.TimerColor);
    WriteColor(0x55A128, 0x55A126, 0x55A124, 0x55A11F, config.Colors.OddJobShadowColor);

    // OnScreen Timer Label Text & Shadow
    WriteColor(0x55A248, 0x55A243, 0x55A23E, 0x55A239, config.Colors.TimerTextColor);
    WriteColor(0x55A21D, 0x55A21B, 0x55A219, 0x55A214, config.Colors.OddJobShadowColor);

    // OnScreen Counter Digits Main & Shadow
    WriteColor(0x55A40E, 0x55A409, 0x55A404, 0x55A3FF, config.Colors.CounterColor);
    WriteColor(0x55A3E3, 0x55A3E1, 0x55A3DF, 0x55A3DA, config.Colors.OddJobShadowColor);

    // OnScreen Counter Text Label Main & Shadow
    WriteColor(0x55A7A3, 0x55A79E, 0x55A799, 0x55A794, config.Colors.CounterTextColor);
    WriteColor(0x55A778, 0x55A776, 0x55A774, 0x55A76F, config.Colors.OddJob2ShadowColor);

    // OnScreen Counter Digits Alt / Highlight Main
    WriteColor(0x55A847, 0x55A842, 0x55A840, 0x55A83B, config.Colors.CounterColor);

    // Mission Title Main & Shadow (m_pBigMessage[1] inside DrawAfterFade())
    WriteColor(0x557283, 0x55727E, 0x55727C, -1, config.Colors.MissionTitleColor);
    WriteColor(0x5571F4, 0x5571F2, 0x5571F0, -1, CRGBA(0, 0, 0, 255));

    // OddJob / Mission Style 3 Main & Shadow (m_pBigMessage[3] inside DrawAfterFade())
    WriteColor(0x556A7B, 0x556A76, 0x556A71, 0x556A6C, config.Colors.OddJobColor);
    WriteColor(0x556A56, 0x556A54, 0x556A52, 0x556A4D, config.Colors.OddJobShadowColor);

    // OddJob Result / Mission Passed Main & Shadow (m_pBigMessage[4] inside DrawAfterFade())
    WriteColor(0x556B92, 0x556B8D, 0x556B88, 0x556B83, config.Colors.OddJob2Color);
    WriteColor(0x556B6D, 0x556B6B, 0x556B69, 0x556B64, config.Colors.OddJob2ShadowColor);

    // OddJob / Mission Style 5 Main & Shadow (m_pBigMessage[5] inside DrawAfterFade())
    WriteColor(0x556E78, 0x556E73, 0x556E6E, 0x556E69, config.Colors.OddJobColor);
    WriteColor(0x556E53, 0x556E51, 0x556E4F, 0x556E4A, config.Colors.OddJobShadowColor);

    // Wasted Main (m_pBigMessage[0] inside Draw())
    WriteColor(0x55B9DE, 0x55B9D9, 0x55B9D4, -1, config.Colors.WastedBustedColor);

    // Busted Main (m_pBigMessage[2] inside Draw())
    WriteColor(0x55BC4F, 0x55BC4A, 0x55BC45, -1, config.Colors.WastedBustedColor);
}
#endif

#ifdef GTA3
void Hooks::ColorsHooksIII() {
    callCounter = 0;

    // Money Main
    WriteColor(0x505FC1, 0x505FBF, 0x505FBA, -1, config.Colors.MoneyColor);

    // Ammo Main (alpha is dynamic push eax)
    WriteColor(0x506331, 0x50632F, 0x50632D, -1, config.Colors.AmmoColor);

    // Health Main
    WriteColor(0x5066B4, 0x5066B2, 0x5066B0, 0x5066AB, config.Colors.HealthColor);

    // Armor Main
    WriteColor(0x506A28, 0x506A23, 0x506A21, 0x506A1C, config.Colors.ArmorColor);

    // Wanted Active Stars Main (alpha is dynamic push eax)
    WriteColor(0x506CAF, 0x506CAA, 0x506CA8, -1, config.Colors.WantedActiveColor);

    // Zone Main
    WriteColor(0x507137, 0x507132, 0x507130, -1, config.Colors.ZoneColor);

    // Vehicle Main (alpha is dynamic push eax)
    WriteColor(0x5075D5, 0x5075D0, 0x5075CE, -1, config.Colors.VehicleColor);

    // Time Main
    WriteColor(0x507770, 0x50776B, 0x507769, 0x507764, config.Colors.TimeColor);

    // Timer Digits & Text Main
    WriteColor(0x507990, 0x50798E, 0x50798C, 0x507987, config.Colors.TimerColor);
    WriteColor(0x507A26, 0x507A24, 0x507A22, 0x507A1D, config.Colors.TimerTextColor);

    // Counter 1 Digits & Text Main
    WriteColor(0x507AE1, 0x507ADF, 0x507ADD, 0x507AD8, config.Colors.CounterColor);
    WriteColor(0x507C3F, 0x507C3D, 0x507C3B, 0x507C36, config.Colors.CounterTextColor);

    // Counter 2 Text Main (Taxi Fare "FARES:")
    WriteColor(0x50800D, 0x50800B, 0x508006, 0x508001, config.Colors.CounterTextColor);
    // Counter 2 Digits Main (Taxi Fare value "0")
    WriteColor(0x507E58, 0x507E56, 0x507E51, 0x507E4C, config.Colors.CounterColor);
    WriteColor(0x507D0C, 0x507D0A, 0x507D05, 0x507D00, config.Colors.CounterColor);

    // Subtitles Main & Shadow
    WriteColor(0x5088A1, 0x50889C, 0x508897, 0x508892, config.Colors.SubtitleColor);
    WriteColor(0x508876, 0x508874, 0x508872, 0x50886D, config.Colors.SubtitleShadowColor);

    // Help Message Box Text Main
    WriteColor(0x509437, 0x509432, 0x50942D, 0x509428, config.Colors.HelpTextColor);

    // BigMessage 0 Main
    WriteColor(0x508CAD, 0x508CAB, 0x508CA6, -1, config.Colors.BigMessageColor);

    // Mission Title Main
    WriteColor(0x50A17D, 0x50A178, 0x50A176, -1, config.Colors.MissionTitleColor);

    // Wasted / Busted Main
    WriteColor(0x508F45, 0x508F43, 0x508F41, -1, config.Colors.WastedBustedColor);

    // OddJob 3, 4, 5 Main
    WriteColor(0x5098EF, 0x5098ED, 0x5098E8, 0x5098E3, config.Colors.OddJobColor);
    WriteColor(0x509A7E, 0x509A7C, 0x509A77, 0x509A72, config.Colors.OddJobColor);
    WriteColor(0x509DF4, 0x509DF2, 0x509DF0, 0x509DEB, config.Colors.OddJob2Color);

    //Wanted stars shadow need to be there.
    WriteColor(0x506BF1, 0x506BEF, 0x506BED, 0x506BE8, config.Colors.HAWShadowColor);

    if (config.EnableShadowColoring != 0) {
        WriteColor(0x505F1F, 0x505F1D, 0x505F1B, 0x505F16, config.Colors.MoneyShadowColor);
        WriteColor(0x507089, 0x507087, 0x507085, 0x507080, config.Colors.ZoneShadowColor);
        WriteColor(0x506577, 0x506575, 0x506573, 0x50656E, config.Colors.HAWShadowColor);
        WriteColor(0x5068E8, 0x5068E6, 0x5068E4, 0x5068DF, config.Colors.HAWShadowColor);
        WriteColor(0x507527, 0x507525, 0x507523, 0x50751E, config.Colors.VehicleShadowColor);
        WriteColor(0x5076F1, 0x5076EF, 0x5076ED, 0x5076E8, config.Colors.TimeShadowColor);
        WriteColor(0x509867, 0x509865, 0x509863, 0x50985E, config.Colors.OddJobShadowColor);
        WriteColor(0x5099E8, 0x5099E6, 0x5099E4, 0x5099DF, config.Colors.OddJobShadowColor);
        WriteColor(0x509D51, 0x509D4F, 0x509D4D, 0x509D48, config.Colors.OddJob2ShadowColor);
    } else {
        // Apply zero alpha shadow colors to all shadows
        WriteColor(0x505F1F, 0x505F1D, 0x505F1B, 0x505F16, CRGBA(0, 0, 0, 0));
        WriteColor(0x506577, 0x506575, 0x506573, 0x50656E, CRGBA(0, 0, 0, 0));
        WriteColor(0x5068E8, 0x5068E6, 0x5068E4, 0x5068DF, CRGBA(0, 0, 0, 0));
        WriteColor(0x507089, 0x507087, 0x507085, 0x507080, CRGBA(0, 0, 0, 0));
        WriteColor(0x507527, 0x507525, 0x507523, 0x50751E, CRGBA(0, 0, 0, 0));
        WriteColor(0x5076F1, 0x5076EF, 0x5076ED, 0x5076E8, CRGBA(0, 0, 0, 0));
        WriteColor(0x509867, 0x509865, 0x509863, 0x50985E, CRGBA(0, 0, 0, 0));
        WriteColor(0x5099E8, 0x5099E6, 0x5099E4, 0x5099DF, CRGBA(0, 0, 0, 0));
        WriteColor(0x509D51, 0x509D4F, 0x509D4D, 0x509D48, CRGBA(0, 0, 0, 0));
    }

    // Drop shadow printstring patches (zero alpha) under config condition
    if (config.LeaveDropShadowPrintStringsUnpatched == 0) {
        WriteColor(0x5078E1, 0x5078DF, 0x5078DD, 0x5078D8, CRGBA(0, 0, 0, 0)); // Timer Digits Shadow
        WriteColor(0x507C8D, 0x507C8B, 0x507C89, 0x507C84, CRGBA(0, 0, 0, 0)); // Counter 1 Text Shadow
        WriteColor(0x507F88, 0x507F86, 0x507F84, 0x507F7F, CRGBA(0, 0, 0, 0)); // Counter 2 Text/Digits Shadow
        WriteColor(0x508BFF, 0x508BFD, 0x508BFB, -1, CRGBA(0, 0, 0, 0));       // BigMessage Shadow
        WriteColor(0x50A0C7, 0x50A0C5, 0x50A0C3, -1, CRGBA(0, 0, 0, 0));       // Mission Title Shadow
        WriteColor(0x508E9F, 0x508E9D, 0x508E9B, -1, CRGBA(0, 0, 0, 0));       // Wasted/Busted Shadow
    }
}
#endif


void Hooks::ColorsHooksSA() {
    callCounter = 0;
#ifdef GTASA
    // Callsite index redirection for elements that share indices:
    patch::SetUChar(0x58B0E3, 7);  // VehicleName: redirect from index 1 (GREEN) to 7
    patch::SetUChar(0x58B369, 10); // MissionTimers: redirect from index 4 (WHITE) to 10
    patch::SetUChar(0x58CD4B, 11); // OddJobTitle: redirect from index 6 (ORANGE) to 11
    patch::SetUChar(0x58CE50, 13); // OddJob2: redirect from index 3 (BLUELIGHT) to 13
    patch::SetUChar(0x58D41F, 14); // MissionTitle: redirect from index 6 (ORANGE) to 14

    // Assign colors to HudColour table slots (0..14)
    WriteColorSA(HUD_COLOUR_RED, config.Colors.HUD_COLOUR_RED);
    WriteColorSA(HUD_COLOUR_GREEN, config.Colors.HUD_COLOUR_GREEN);
    WriteColorSA(HUD_COLOUR_BLUEDARK, config.Colors.HUD_COLOUR_BLUEDARK);
    WriteColorSA(HUD_COLOUR_BLUELIGHT, config.Colors.HUD_COLOUR_BLUELIGHT);
    WriteColorSA(HUD_COLOUR_WHITE, config.Colors.HUD_COLOUR_WHITE);
    WriteColorSA(HUD_COLOUR_BLACK, config.Colors.HUD_COLOUR_BLACK);
    WriteColorSA(HUD_COLOUR_ORANGE, config.Colors.HUD_COLOUR_ORANGE);
    WriteColorSA(HUD_COLOUR_PURPLE, config.Colors.HUD_COLOUR_PURPLE);
    WriteColorSA(HUD_COLOUR_GREY, config.Colors.HUD_COLOUR_GREY);
    WriteColorSA(HUD_COLOUR_REDDARK, config.Colors.HUD_COLOUR_REDDARK);
    WriteColorSA(HUD_COLOUR_GREENDARK, config.Colors.HUD_COLOUR_GREENDARK);
    WriteColorSA(HUD_COLOUR_ORANGELIGHT, config.Colors.HUD_COLOUR_ORANGELIGHT);
    WriteColorSA(HUD_COLOUR_GREYDARK, config.Colors.HUD_COLOUR_GREYDARK);
    WriteColorSA(HUD_COLOUR_BLUE, config.Colors.HUD_COLOUR_BLUE);
    WriteColorSA(HUD_COLOUR_YELLOW, config.Colors.HUD_COLOUR_YELLOW);
#endif
}

void Hooks::ConfigRefresher() {
    static uint32_t lastReloadCheck = 0;
    uint32_t now;

    now = GetTickCount();
    if (now - lastReloadCheck > 150) {
        lastReloadCheck = now;
        if (config.ReloadKey != 0) {
            if (config.ReloadKey == -1 || KeyPressed(config.ReloadKey)) {
                config.Read();
#ifdef GTA3
                ColorsHooksIII();
#elif defined(GTAVC)
                ColorsHooksVC();
#elif defined(GTASA)
                ColorsHooksSA();
#endif
            }
        }
    }
}


