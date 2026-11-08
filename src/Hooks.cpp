#include "../includes/Hooks.h"
#include "../includes/ColorsConfig.h"
#include "../includes/InputHandler.h"
#ifdef GTASA
#include <CHudColours.h>
#endif

using namespace plugin;

static uint32_t callCounter = 0;

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

        h = (step + callCounter++) * 1103515245 + 12345;
        r = (uint8_t)(h & 0xFF);
        g = (uint8_t)((h >> 8) & 0xFF);
        b = (uint8_t)((h >> 16) & 0xFF);

        return CRGBA(r, g, b, clr.a);
    }
    return clr;
}

#if defined(GTA3) || defined(GTAVC)
static void ApplyColorPatches(ColorPatch const *patches, size_t count) {
    size_t i;
    ColorPatch const *p;
    CRGBA colorToUse;

    for (i = 0; i < count; i++) {
        p = &patches[i];
        colorToUse = GetColorToApply(*p->color);

        patch::SetUChar(p->addrR, colorToUse.r);
        patch::SetUChar(p->addrG, colorToUse.g);
        patch::SetUChar(p->addrB, colorToUse.b);
        if (p->addrA != -1 && p->addrA != 0) {
            patch::SetUChar(p->addrA, colorToUse.a);
        }
    }
}
#endif

#ifdef GTA3
static const unsigned int gta3ShadowZeroAlphaAddrs[][4] = {
    { 0x505F1F, 0x505F1D, 0x505F1B, 0x505F16 },
    { 0x506577, 0x506575, 0x506573, 0x50656E },
    { 0x5068E8, 0x5068E6, 0x5068E4, 0x5068DF },
    { 0x507089, 0x507087, 0x507085, 0x507080 },
    { 0x507527, 0x507525, 0x507523, 0x50751E },
    { 0x5076F1, 0x5076EF, 0x5076ED, 0x5076E8 },
    { 0x509867, 0x509865, 0x509863, 0x50985E },
    { 0x5099E8, 0x5099E6, 0x5099E4, 0x5099DF },
    { 0x509D51, 0x509D4F, 0x509D4D, 0x509D48 }
};

static const unsigned int gta3DropShadowZeroAlphaAddrs[][4] = {
    { 0x5078E1, 0x5078DF, 0x5078DD, 0x5078D8 }, // Timer Digits Shadow
    { 0x507C8D, 0x507C8B, 0x507C89, 0x507C84 }, // Counter 1 Text Shadow
    { 0x507F88, 0x507F86, 0x507F84, 0x507F7F }, // Counter 2 Text/Digits Shadow
    { 0x508BFF, 0x508BFD, 0x508BFB, 0 },          // BigMessage Shadow
    { 0x50A0C7, 0x50A0C5, 0x50A0C3, 0 },          // Mission Title Shadow
    { 0x508E9F, 0x508E9D, 0x508E9B, 0 }           // Wasted/Busted Shadow
};

static const ColorPatch gta3MainPatches[] = {
    // Money Main
    { 0x505FC1, 0x505FBF, 0x505FBA, -1, &config.Colors.MoneyColor },

    // Ammo Main (alpha is dynamic push eax)
    { 0x506331, 0x50632F, 0x50632D, -1, &config.Colors.AmmoColor },

    // Health Main
    { 0x5066B4, 0x5066B2, 0x5066B0, 0x5066AB, &config.Colors.HealthColor },

    // Armor Main
    { 0x506A28, 0x506A23, 0x506A21, 0x506A1C, &config.Colors.ArmorColor },

    // Wanted Active Stars Main (alpha is dynamic push eax)
    { 0x506CAF, 0x506CAA, 0x506CA8, -1, &config.Colors.WantedActiveColor },

    // Zone Main
    { 0x507137, 0x507132, 0x507130, -1, &config.Colors.ZoneColor },

    // Vehicle Main (alpha is dynamic push eax)
    { 0x5075D5, 0x5075D0, 0x5075CE, -1, &config.Colors.VehicleColor },

    // Time Main
    { 0x507770, 0x50776B, 0x507769, 0x507764, &config.Colors.TimeColor },

    // Timer Digits & Text Main
    { 0x507990, 0x50798E, 0x50798C, 0x507987, &config.Colors.TimerColor },
    { 0x507A26, 0x507A24, 0x507A22, 0x507A1D, &config.Colors.TimerTextColor },

    // Counter 1 Digits & Text Main
    { 0x507AE1, 0x507ADF, 0x507ADD, 0x507AD8, &config.Colors.CounterColor },
    { 0x507C3F, 0x507C3D, 0x507C3B, 0x507C36, &config.Colors.CounterTextColor },

    // Counter 2 Text Main (Taxi Fare "FARES:")
    { 0x50800D, 0x50800B, 0x508006, 0x508001, &config.Colors.CounterTextColor },
    // Counter 2 Digits Main (Taxi Fare value "0")
    { 0x507E58, 0x507E56, 0x507E51, 0x507E4C, &config.Colors.CounterColor },
    { 0x507D0C, 0x507D0A, 0x507D05, 0x507D00, &config.Colors.CounterColor },

    // Subtitles Main & Shadow
    { 0x5088A1, 0x50889C, 0x508897, 0x508892, &config.Colors.SubtitleColor },
    { 0x508876, 0x508874, 0x508872, 0x50886D, &config.Colors.SubtitleShadowColor },

    // Help Message Box Text Main
    { 0x509437, 0x509432, 0x50942D, 0x509428, &config.Colors.HelpTextColor },

    // BigMessage 0 Main
    { 0x508CAD, 0x508CAB, 0x508CA6, -1, &config.Colors.BigMessageColor },

    // Mission Title Main
    { 0x50A17D, 0x50A178, 0x50A176, -1, &config.Colors.MissionTitleColor },

    // Wasted / Busted Main
    { 0x508F45, 0x508F43, 0x508F41, -1, &config.Colors.WastedBustedColor },

    // OddJob 3, 4, 5 Main
    { 0x5098EF, 0x5098ED, 0x5098E8, 0x5098E3, &config.Colors.OddJobColor },
    { 0x509A7E, 0x509A7C, 0x509A77, 0x509A72, &config.Colors.OddJobColor },
    { 0x509DF4, 0x509DF2, 0x509DF0, 0x509DEB, &config.Colors.OddJob2Color },

    // Wanted stars shadow need to be there
    { 0x506BF1, 0x506BEF, 0x506BED, 0x506BE8, &config.Colors.HAWShadowColor }
};

static const ColorPatch gta3ShadowColorPatches[] = {
    { 0x505F1F, 0x505F1D, 0x505F1B, 0x505F16, &config.Colors.MoneyShadowColor },
    { 0x507089, 0x507087, 0x507085, 0x507080, &config.Colors.ZoneShadowColor },
    { 0x506577, 0x506575, 0x506573, 0x50656E, &config.Colors.HAWShadowColor },
    { 0x5068E8, 0x5068E6, 0x5068E4, 0x5068DF, &config.Colors.HAWShadowColor },
    { 0x507527, 0x507525, 0x507523, 0x50751E, &config.Colors.VehicleShadowColor },
    { 0x5076F1, 0x5076EF, 0x5076ED, 0x5076E8, &config.Colors.TimeShadowColor },
    { 0x509867, 0x509865, 0x509863, 0x50985E, &config.Colors.OddJobShadowColor },
    { 0x5099E8, 0x5099E6, 0x5099E4, 0x5099DF, &config.Colors.OddJobShadowColor },
    { 0x509D51, 0x509D4F, 0x509D4D, 0x509D48, &config.Colors.OddJob2ShadowColor }
};

static void WriteZeroAlphaAddrs(const unsigned int addrs[][4], size_t count) {
    size_t i;

    for (i = 0; i < count; i++) {
        patch::SetUChar(addrs[i][0], 0);
        patch::SetUChar(addrs[i][1], 0);
        patch::SetUChar(addrs[i][2], 0);
        if (addrs[i][3] != 0) {
            patch::SetUChar(addrs[i][3], 0);
        }
    }
}

void Hooks::ApplyColorHooks() {
    callCounter = 0;

    ApplyColorPatches(gta3MainPatches, ARRAY_SIZE(gta3MainPatches));

    if (config.EnableShadowColoring != 0) {
        ApplyColorPatches(gta3ShadowColorPatches, ARRAY_SIZE(gta3ShadowColorPatches));
    } else {
        WriteZeroAlphaAddrs(gta3ShadowZeroAlphaAddrs, ARRAY_SIZE(gta3ShadowZeroAlphaAddrs));
    }

    if (config.LeaveDropShadowPrintStringsUnpatched == 0) {
        WriteZeroAlphaAddrs(gta3DropShadowZeroAlphaAddrs, ARRAY_SIZE(gta3DropShadowZeroAlphaAddrs));
    }
}

#elif defined(GTAVC)
static const CRGBA blackSolid(0, 0, 0, 255);

static const ColorPatch vcMainPatches[] = {
    // Money Main & Shadow
    { 0x5582AF, 0x5582AA, 0x5582A5, -1, &config.Colors.MoneyColor },
    { 0x558263, 0x558261, 0x55825F, -1, &config.Colors.MoneyShadowColor },

    // Ammo Main & Shadow
    { 0x5588C2, 0x5588BD, 0x5588B8, -1, &config.Colors.AmmoColor },
    { 0x558876, 0x558874, 0x558872, -1, &config.Colors.AmmoShadowColor },

    // Health, Armor, Wanted Shadow
    { 0x558A08, 0x558A06, 0x558A04, 0x5589FF, &config.Colors.HAWShadowColor },

    // Health Main & Icon
    { 0x558BA9, 0x558BA4, 0x558B9F, 0x558B9A, &config.Colors.HealthColor },
    { 0x558C8E, 0x558C66, 0x558C61, 0x558C56, &config.Colors.HealthIconColor },

    // Armor Main & Icon
    { 0x558E26, 0x558E21, 0x558E1C, 0x558E17, &config.Colors.ArmorColor },
    { 0x558EFE, 0x558ED6, 0x558ED1, 0x558EC6, &config.Colors.ArmorIconColor },

    // Wanted Active, Suspended & Inactive Stars
    { 0x5590CA, 0x5590C5, 0x5590C0, -1, &config.Colors.WantedActiveColor },
    { 0x559128, 0x559123, 0x55911E, -1, &config.Colors.WantedSuspendedColor },
    { 0x559170, 0x55916E, 0x559169, -1, &config.Colors.WantedInactiveColor },

    // Zone Main & Shadow
    { 0x559954, 0x55994F, 0x55994D, -1, &config.Colors.ZoneColor },
    { 0x559903, 0x559901, 0x5598FF, -1, &config.Colors.ZoneShadowColor },

    // Vehicle Main & Shadow
    { 0x559DE3, 0x559DDE, 0x559DD9, -1, &config.Colors.VehicleColor },
    { 0x559E29, 0x559E27, 0x559E25, -1, &config.Colors.VehicleShadowColor },

    // Time (Clock) Main & Shadow
    { 0x559F91, 0x559F8C, 0x559F87, 0x559F82, &config.Colors.TimeColor },
    { 0x559F2D, 0x559F2B, 0x559F29, 0x559F24, &config.Colors.TimeShadowColor },

    // Brief & Help Message Box Text & Shadow
    { 0x55B542, 0x55B53D, 0x55B538, 0x55B533, &config.Colors.BriefTextColor },
    { 0x55B5E4, 0x55B5E2, 0x55B5E0, -1, &blackSolid },
    { 0x55B60F, 0x55B60A, 0x55B605, 0x55B600, &config.Colors.HelpTextColor },
    { 0x55B7C0, 0x55B7BB, 0x55B7B9, -1, &config.Colors.BriefTextColor },
    { 0x55B990, 0x55B98E, 0x55B98C, -1, &blackSolid },

    // Subtitles Main & Shadow
    { 0x55AEB8, 0x55AEB3, 0x55AEAE, 0x55AEA9, &config.Colors.SubtitleColor },
    { 0x55AFEF, 0x55AFED, 0x55AFEB, 0x55AFE6, &config.Colors.SubtitleShadowColor },

    // OnScreen Timer Clock Digits Main & Shadow
    { 0x55A186, 0x55A181, 0x55A17C, 0x55A177, &config.Colors.TimerColor },
    { 0x55A128, 0x55A126, 0x55A124, 0x55A11F, &config.Colors.OddJobShadowColor },

    // OnScreen Timer Label Text & Shadow
    { 0x55A248, 0x55A243, 0x55A23E, 0x55A239, &config.Colors.TimerTextColor },
    { 0x55A21D, 0x55A21B, 0x55A219, 0x55A214, &config.Colors.OddJobShadowColor },

    // OnScreen Counter Digits Main & Shadow
    { 0x55A40E, 0x55A409, 0x55A404, 0x55A3FF, &config.Colors.CounterColor },
    { 0x55A3E3, 0x55A3E1, 0x55A3DF, 0x55A3DA, &config.Colors.OddJobShadowColor },

    // OnScreen Counter Text Label Main & Shadow
    { 0x55A7A3, 0x55A79E, 0x55A799, 0x55A794, &config.Colors.CounterTextColor },
    { 0x55A778, 0x55A776, 0x55A774, 0x55A76F, &config.Colors.OddJob2ShadowColor },

    // OnScreen Counter Digits Alt / Highlight Main
    { 0x55A847, 0x55A842, 0x55A840, 0x55A83B, &config.Colors.CounterColor },

    // Mission Title Main & Shadow (m_pBigMessage[1] inside DrawAfterFade())
    { 0x557283, 0x55727E, 0x55727C, -1, &config.Colors.MissionTitleColor },
    { 0x5571F4, 0x5571F2, 0x5571F0, -1, &blackSolid },

    // OddJob / Mission Style 3 Main & Shadow (m_pBigMessage[3] inside DrawAfterFade())
    { 0x556A7B, 0x556A76, 0x556A71, 0x556A6C, &config.Colors.OddJobColor },
    { 0x556A56, 0x556A54, 0x556A52, 0x556A4D, &config.Colors.OddJobShadowColor },

    // OddJob Result / Mission Passed Main & Shadow (m_pBigMessage[4] inside DrawAfterFade())
    { 0x556B92, 0x556B8D, 0x556B88, 0x556B83, &config.Colors.OddJob2Color },
    { 0x556B6D, 0x556B6B, 0x556B69, 0x556B64, &config.Colors.OddJob2ShadowColor },

    // OddJob / Mission Style 5 Main & Shadow (m_pBigMessage[5] inside DrawAfterFade())
    { 0x556E78, 0x556E73, 0x556E6E, 0x556E69, &config.Colors.OddJobColor },
    { 0x556E53, 0x556E51, 0x556E4F, 0x556E4A, &config.Colors.OddJobShadowColor },

    // Wasted Main (m_pBigMessage[0] inside Draw())
    { 0x55B9DE, 0x55B9D9, 0x55B9D4, -1, &config.Colors.WastedBustedColor },

    // Busted Main (m_pBigMessage[2] inside Draw())
    { 0x55BC4F, 0x55BC4A, 0x55BC45, -1, &config.Colors.WastedBustedColor }
};

void Hooks::ApplyColorHooks() {
    callCounter = 0;
    ApplyColorPatches(vcMainPatches, ARRAY_SIZE(vcMainPatches));
}

#elif defined(GTASA)
static const SaColorEntry saColorEntries[] = {
    { HUD_COLOUR_RED, &config.Colors.HUD_COLOUR_RED },
    { HUD_COLOUR_GREEN, &config.Colors.HUD_COLOUR_GREEN },
    { HUD_COLOUR_BLUEDARK, &config.Colors.HUD_COLOUR_BLUEDARK },
    { HUD_COLOUR_BLUELIGHT, &config.Colors.HUD_COLOUR_BLUELIGHT },
    { HUD_COLOUR_WHITE, &config.Colors.HUD_COLOUR_WHITE },
    { HUD_COLOUR_BLACK, &config.Colors.HUD_COLOUR_BLACK },
    { HUD_COLOUR_ORANGE, &config.Colors.HUD_COLOUR_ORANGE },
    { HUD_COLOUR_PURPLE, &config.Colors.HUD_COLOUR_PURPLE },
    { HUD_COLOUR_GREY, &config.Colors.HUD_COLOUR_GREY },
    { HUD_COLOUR_REDDARK, &config.Colors.HUD_COLOUR_REDDARK },
    { HUD_COLOUR_GREENDARK, &config.Colors.HUD_COLOUR_GREENDARK },
    { HUD_COLOUR_ORANGELIGHT, &config.Colors.HUD_COLOUR_ORANGELIGHT },
    { HUD_COLOUR_GREYDARK, &config.Colors.HUD_COLOUR_GREYDARK },
    { HUD_COLOUR_BLUE, &config.Colors.HUD_COLOUR_BLUE },
    { HUD_COLOUR_YELLOW, &config.Colors.HUD_COLOUR_YELLOW }
};

static void ApplyColorPatchesSA(SaColorEntry const *entries, size_t count) {
    size_t i;
    SaColorEntry const *entry;
    CRGBA colorToUse;

    for (i = 0; i < count; i++) {
        entry = &entries[i];
        colorToUse = GetColorToApply(*entry->color);
        HudColour.SetRGBAValue(entry->colorIndex, colorToUse.r, colorToUse.g, colorToUse.b, colorToUse.a);
    }
}

void Hooks::ApplyColorHooks() {
    callCounter = 0;

    // Callsite index redirection for elements that share indices:
    patch::SetUChar(0x58B0E3, 7);  // VehicleName: redirect from index 1 (GREEN) to 7
    patch::SetUChar(0x58B369, 10); // MissionTimers: redirect from index 4 (WHITE) to 10
    patch::SetUChar(0x58CD4B, 11); // OddJobTitle: redirect from index 6 (ORANGE) to 11
    patch::SetUChar(0x58CE50, 13); // OddJob2: redirect from index 3 (BLUELIGHT) to 13
    patch::SetUChar(0x58D41F, 14); // MissionTitle: redirect from index 6 (ORANGE) to 14

    ApplyColorPatchesSA(saColorEntries, ARRAY_SIZE(saColorEntries));
}
#endif

void Hooks::ConfigRefresher() {
    InputHandler::UpdateOldKeyState();

    if (config.ReloadKey != 0) {
        if (config.ReloadKey == -1 || InputHandler::IsKeyJustPressed(config.ReloadKey)) {
            config.Read();
            ApplyColorHooks();
        }
    }
}
