#include "../includes/ColorsConfig.h"

// Standard config paths
#define COLORS_INI_PATH GAME_PATH("scripts\\colors_config.ini")

#ifdef GTASA
static const HudColorInfo defaultSAColors = {
    CRGBA(180, 25, 29, 255),    // HUD_COLOUR_RED
    CRGBA(54, 104, 44, 255),    // HUD_COLOUR_GREEN
    CRGBA(50, 60, 127, 255),    // HUD_COLOUR_BLUEDARK
    CRGBA(172, 203, 241, 255),  // HUD_COLOUR_BLUELIGHT
    CRGBA(225, 225, 225, 255),  // HUD_COLOUR_WHITE
    CRGBA(0, 0, 0, 255),        // HUD_COLOUR_BLACK
    CRGBA(144, 98, 16, 255),    // HUD_COLOUR_ORANGE
    CRGBA(168, 110, 252, 255),  // HUD_COLOUR_PURPLE
    CRGBA(150, 150, 150, 255),  // HUD_COLOUR_GREY
    CRGBA(104, 15, 17, 255),    // HUD_COLOUR_REDDARK
    CRGBA(38, 71, 31, 255),     // HUD_COLOUR_GREENDARK
    CRGBA(226, 192, 99, 255),   // HUD_COLOUR_ORANGELIGHT
    CRGBA(74, 90, 107, 255),    // HUD_COLOUR_GREYDARK
    CRGBA(20, 25, 200, 255),    // HUD_COLOUR_BLUE
    CRGBA(255, 255, 0, 255)     // HUD_COLOUR_YELLOW
};
#endif

static const GlobalHudDefaultColors& GetGlobalHudDefaultColors(int defaultIdx) {
    static const GlobalHudDefaultColors defaultColors[TOTAL_COLORDEFAULTS] = {
        // GTA_III_COLOR = 0 (from re3 Hud.cpp)
        {CRGBA(89, 115, 150, 255), CRGBA(186, 101, 50, 255), CRGBA(186, 101, 50, 255),
         CRGBA(124, 140, 95, 255), CRGBA(124, 140, 95, 255), CRGBA(0, 0, 0, 255),
         CRGBA(193, 164, 120, 255), CRGBA(193, 164, 120, 255), CRGBA(0, 0, 0, 255),
         CRGBA(152, 154, 82, 255), CRGBA(194, 165, 120, 255), CRGBA(194, 165, 120, 255),
         CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255),
         CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255),
         CRGBA(186, 101, 50, 255), CRGBA(186, 101, 50, 255), CRGBA(0, 106, 164, 255), CRGBA(0, 106, 164, 255), CRGBA(89, 115, 150, 255),
         CRGBA(0, 0, 0, 255), CRGBA(156, 91, 40, 255), CRGBA(0, 0, 0, 255),
         CRGBA(220, 172, 2, 255), CRGBA(85, 119, 133, 255), CRGBA(170, 123, 87, 255),
         CRGBA(225, 225, 225, 255), CRGBA(0, 0, 0, 255),
         CRGBA(175, 175, 175, 255), CRGBA(175, 175, 175, 255)},
        // GTA_VC_COLOR = 1 (from reVC Hud.cpp)
        {CRGBA(0, 207, 133, 255), CRGBA(255, 150, 225, 255), CRGBA(255, 150, 225, 255),
         CRGBA(185, 185, 185, 255), CRGBA(185, 185, 185, 255), CRGBA(255, 150, 225, 255),
         CRGBA(97, 194, 247, 255), CRGBA(62, 141, 181, 255), CRGBA(27, 89, 130, 255),
         CRGBA(45, 155, 90, 255), CRGBA(97, 194, 247, 255), CRGBA(97, 194, 247, 255),
         CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255),
         CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255),
         CRGBA(97, 194, 247, 255), CRGBA(97, 194, 247, 255), CRGBA(97, 194, 247, 255), CRGBA(97, 194, 247, 255), CRGBA(0, 207, 133, 255),
         CRGBA(0, 0, 0, 255), CRGBA(97, 194, 247, 255), CRGBA(0, 0, 0, 255),
         CRGBA(220, 172, 2, 255), CRGBA(255, 150, 225, 255), CRGBA(0, 207, 133, 255),
         CRGBA(225, 225, 225, 255), CRGBA(0, 0, 0, 255),
         CRGBA(175, 175, 175, 255), CRGBA(175, 175, 175, 255)},
        // GTA_SA_COLOR = 2
        {CRGBA(54, 104, 44, 255), CRGBA(180, 25, 29, 255), CRGBA(150, 25, 29, 255),
         CRGBA(225, 225, 225, 255), CRGBA(225, 225, 225, 255), CRGBA(172, 203, 241, 255),
         CRGBA(144, 98, 16, 255), CRGBA(82, 56, 9, 255), CRGBA(0, 0, 0, 255),
         CRGBA(172, 203, 241, 255), CRGBA(54, 104, 44, 255), CRGBA(225, 225, 225, 255),
         CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255),
         CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255),
         CRGBA(225, 225, 225, 255), CRGBA(225, 225, 225, 255), CRGBA(225, 225, 225, 255), CRGBA(225, 225, 225, 255), CRGBA(54, 104, 44, 255),
         CRGBA(0, 0, 0, 255), CRGBA(172, 203, 241, 255), CRGBA(0, 0, 0, 255),
         CRGBA(225, 225, 225, 255), CRGBA(180, 25, 29, 255), CRGBA(180, 25, 29, 255),
         CRGBA(225, 225, 225, 255), CRGBA(0, 0, 0, 255),
         CRGBA(175, 175, 175, 255), CRGBA(175, 175, 175, 255)},
        // GTA_IV_COLOR = 3
        {CRGBA(255, 255, 255, 255), CRGBA(87, 124, 88, 255), CRGBA(87, 124, 88, 255),
         CRGBA(74, 148, 160, 255), CRGBA(74, 148, 160, 255), CRGBA(255, 255, 255, 255),
         CRGBA(255, 255, 255, 255), CRGBA(125, 125, 125, 255), CRGBA(0, 0, 0, 255),
         CRGBA(255, 255, 255, 255), CRGBA(255, 255, 255, 255), CRGBA(255, 255, 255, 255),
         CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255),
         CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255),
         CRGBA(255, 255, 255, 255), CRGBA(255, 255, 255, 255), CRGBA(255, 255, 255, 255), CRGBA(255, 255, 255, 255), CRGBA(255, 255, 255, 255),
         CRGBA(0, 0, 0, 255), CRGBA(255, 255, 255, 255), CRGBA(0, 0, 0, 255),
         CRGBA(255, 255, 255, 255), CRGBA(255, 255, 255, 255), CRGBA(255, 255, 255, 255),
         CRGBA(225, 225, 225, 255), CRGBA(0, 0, 0, 255),
         CRGBA(175, 175, 175, 255), CRGBA(175, 175, 175, 255)},
        // GTA_V_COLOR = 4
        {CRGBA(180, 180, 180, 255), CRGBA(65, 164, 70, 255), CRGBA(65, 164, 70, 255),
         CRGBA(32, 87, 117, 255), CRGBA(32, 87, 117, 255), CRGBA(255, 255, 255, 255),
         CRGBA(255, 255, 255, 255), CRGBA(125, 125, 125, 255), CRGBA(0, 0, 0, 255),
         CRGBA(255, 255, 255, 255), CRGBA(255, 255, 255, 255), CRGBA(255, 255, 255, 255),
         CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255),
         CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255),
         CRGBA(255, 255, 255, 255), CRGBA(255, 255, 255, 255), CRGBA(255, 255, 255, 255), CRGBA(255, 255, 255, 255), CRGBA(255, 255, 255, 255),
         CRGBA(0, 0, 0, 255), CRGBA(255, 255, 255, 255), CRGBA(0, 0, 0, 255),
         CRGBA(255, 255, 255, 255), CRGBA(255, 255, 255, 255), CRGBA(255, 255, 255, 255),
         CRGBA(225, 225, 225, 255), CRGBA(0, 0, 0, 255),
         CRGBA(175, 175, 175, 255), CRGBA(175, 175, 175, 255)},
        // GTA_LCS_COLOR = 5
        {CRGBA(60, 149, 46, 255), CRGBA(202, 11, 10, 255), CRGBA(202, 11, 10, 255),
         CRGBA(69, 160, 231, 255), CRGBA(69, 160, 231, 255), CRGBA(255, 255, 255, 255),
         CRGBA(255, 203, 51, 255), CRGBA(82, 56, 9, 255), CRGBA(0, 0, 0, 255),
         CRGBA(255, 255, 255, 255), CRGBA(255, 255, 255, 255), CRGBA(255, 203, 51, 255),
         CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255),
         CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255),
         CRGBA(255, 203, 51, 255), CRGBA(255, 203, 51, 255), CRGBA(255, 203, 51, 255), CRGBA(255, 203, 51, 255), CRGBA(60, 149, 46, 255),
         CRGBA(0, 0, 0, 255), CRGBA(255, 255, 255, 255), CRGBA(0, 0, 0, 255),
         CRGBA(255, 203, 51, 255), CRGBA(202, 11, 10, 255), CRGBA(202, 11, 10, 255),
         CRGBA(225, 225, 225, 255), CRGBA(0, 0, 0, 255),
         CRGBA(175, 175, 175, 255), CRGBA(175, 175, 175, 255)},
        // GTA_VCS_COLOR = 6
        {CRGBA(40, 102, 35, 255), CRGBA(208, 86, 133, 255), CRGBA(209, 86, 133, 255),
         CRGBA(15, 224, 219, 255), CRGBA(15, 224, 219, 255), CRGBA(255, 255, 255, 255),
         CRGBA(255, 203, 51, 255), CRGBA(82, 56, 9, 255), CRGBA(0, 0, 0, 255),
         CRGBA(255, 255, 255, 255), CRGBA(255, 255, 255, 255), CRGBA(192, 135, 45, 255),
         CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255),
         CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255), CRGBA(0, 0, 0, 255),
         CRGBA(192, 135, 45, 255), CRGBA(192, 135, 45, 255), CRGBA(192, 135, 45, 255), CRGBA(192, 135, 45, 255), CRGBA(40, 102, 35, 255),
         CRGBA(0, 0, 0, 255), CRGBA(255, 255, 255, 255), CRGBA(0, 0, 0, 255),
         CRGBA(192, 135, 45, 255), CRGBA(208, 86, 133, 255), CRGBA(208, 86, 133, 255),
         CRGBA(225, 225, 225, 255), CRGBA(0, 0, 0, 255),
         CRGBA(175, 175, 175, 255), CRGBA(175, 175, 175, 255)}
    };
    return defaultColors[defaultIdx];
}

static void ApplyDefaultColors(HudColorInfo &colors, int defaultIdx) {
#ifdef GTASA
    if (defaultIdx == GTA_SA_COLOR || defaultIdx < 0 || defaultIdx >= TOTAL_COLORDEFAULTS) {
        colors = defaultSAColors;
    } else {
        const GlobalHudDefaultColors &p = GetGlobalHudDefaultColors(defaultIdx);
        colors.HUD_COLOUR_RED = p.HealthColor;
        colors.HUD_COLOUR_GREEN = p.MoneyColor;
        colors.HUD_COLOUR_BLUEDARK = p.WantedSuspendedColor;
        colors.HUD_COLOUR_BLUELIGHT = (p.AmmoColor.r == 0 && p.AmmoColor.g == 0 && p.AmmoColor.b == 0) ? CRGBA(225, 225, 225, 255) : p.AmmoColor;
        colors.HUD_COLOUR_WHITE = p.ArmorColor;
        colors.HUD_COLOUR_BLACK = CRGBA(0, 0, 0, 255);
        colors.HUD_COLOUR_ORANGE = p.WantedActiveColor;
        colors.HUD_COLOUR_PURPLE = p.VehicleColor;
        colors.HUD_COLOUR_GREY = p.TimeColor;
        colors.HUD_COLOUR_REDDARK = p.ZoneColor;
        colors.HUD_COLOUR_GREENDARK = p.TimerColor;
        colors.HUD_COLOUR_ORANGELIGHT = p.OddJobColor;
        colors.HUD_COLOUR_GREYDARK = (p.WantedInactiveColor.r == 0 && p.WantedInactiveColor.g == 0 && p.WantedInactiveColor.b == 0) ? CRGBA(150, 150, 150, 255) : p.WantedInactiveColor;
        colors.HUD_COLOUR_BLUE = p.OddJob2Color;
        colors.HUD_COLOUR_YELLOW = p.MissionTitleColor;
    }
#else
    colors = GetGlobalHudDefaultColors(defaultIdx);
#endif
}

// Global config instance
ColorsConfig config;

ColorsConfig::ColorsConfig() {
    int defaultIdx;

    ReloadKey = 162; // VK_LCONTROL
    DefaultOverride = -1;
    RandomColors = 0;
    RandomColorsSpeed = 1.0f;
#ifdef GTA3
    LeaveDropShadowPrintStringsUnpatched = 1;
    EnableShadowColoring = 0;
#endif

    defaultIdx = DefaultOverride;
    if (defaultIdx < 0 || defaultIdx >= TOTAL_COLORDEFAULTS) {
#ifdef GTA3
        defaultIdx = GTA_III_COLOR;
#elif defined(GTAVC)
        defaultIdx = GTA_VC_COLOR;
#elif defined(GTASA)
        defaultIdx = GTA_SA_COLOR;
#else
        defaultIdx = GTA_III_COLOR;
#endif
    }
    ApplyDefaultColors(Colors, defaultIdx);
}

bool ColorsConfig::Read() {
    int defaultIdx;
    std::string colorsPath;

    colorsPath = COLORS_INI_PATH;
    ConfigHelper cfgColors(colorsPath);

    if (!cfgColors.Exists())
        return false;

    ReloadKey = cfgColors.ReadInt("Settings", "ReloadKey", ReloadKey);
    DefaultOverride = cfgColors.ReadInt("Settings", "DefaultOverride", DefaultOverride);
    RandomColors = cfgColors.ReadInt("Settings", "RandomColors", RandomColors);
    RandomColorsSpeed = cfgColors.ReadFloat("Settings", "RandomColorsSpeed", RandomColorsSpeed);
#ifdef GTA3
    LeaveDropShadowPrintStringsUnpatched = cfgColors.ReadInt("Settings", "LeaveDropShadowPrintStringsUnpatched", LeaveDropShadowPrintStringsUnpatched);
    EnableShadowColoring = cfgColors.ReadInt("Settings", "EnableShadowColoring", EnableShadowColoring);
#endif

    defaultIdx = DefaultOverride;
    if (defaultIdx < 0 || defaultIdx >= TOTAL_COLORDEFAULTS) {
#ifdef GTA3
        defaultIdx = GTA_III_COLOR;
#elif defined(GTAVC)
        defaultIdx = GTA_VC_COLOR;
#elif defined(GTASA)
        defaultIdx = GTA_SA_COLOR;
#else
        defaultIdx = GTA_III_COLOR;
#endif
    }
    ApplyDefaultColors(Colors, defaultIdx);

    if (DefaultOverride == -1) {
#ifdef GTASA
        Colors.HUD_COLOUR_RED = cfgColors.ReadRGBA("Colors", "HUD_COLOUR_RED", Colors.HUD_COLOUR_RED);
        Colors.HUD_COLOUR_GREEN = cfgColors.ReadRGBA("Colors", "HUD_COLOUR_GREEN", Colors.HUD_COLOUR_GREEN);
        Colors.HUD_COLOUR_BLUEDARK = cfgColors.ReadRGBA("Colors", "HUD_COLOUR_BLUEDARK", Colors.HUD_COLOUR_BLUEDARK);
        Colors.HUD_COLOUR_BLUELIGHT = cfgColors.ReadRGBA("Colors", "HUD_COLOUR_BLUELIGHT", Colors.HUD_COLOUR_BLUELIGHT);
        Colors.HUD_COLOUR_WHITE = cfgColors.ReadRGBA("Colors", "HUD_COLOUR_WHITE", Colors.HUD_COLOUR_WHITE);
        Colors.HUD_COLOUR_BLACK = cfgColors.ReadRGBA("Colors", "HUD_COLOUR_BLACK", Colors.HUD_COLOUR_BLACK);
        Colors.HUD_COLOUR_ORANGE = cfgColors.ReadRGBA("Colors", "HUD_COLOUR_ORANGE", Colors.HUD_COLOUR_ORANGE);
        Colors.HUD_COLOUR_PURPLE = cfgColors.ReadRGBA("Colors", "HUD_COLOUR_PURPLE", Colors.HUD_COLOUR_PURPLE);
        Colors.HUD_COLOUR_GREY = cfgColors.ReadRGBA("Colors", "HUD_COLOUR_GREY", Colors.HUD_COLOUR_GREY);
        Colors.HUD_COLOUR_REDDARK = cfgColors.ReadRGBA("Colors", "HUD_COLOUR_REDDARK", Colors.HUD_COLOUR_REDDARK);
        Colors.HUD_COLOUR_GREENDARK = cfgColors.ReadRGBA("Colors", "HUD_COLOUR_GREENDARK", Colors.HUD_COLOUR_GREENDARK);
        Colors.HUD_COLOUR_ORANGELIGHT = cfgColors.ReadRGBA("Colors", "HUD_COLOUR_ORANGELIGHT", Colors.HUD_COLOUR_ORANGELIGHT);
        Colors.HUD_COLOUR_GREYDARK = cfgColors.ReadRGBA("Colors", "HUD_COLOUR_GREYDARK", Colors.HUD_COLOUR_GREYDARK);
        Colors.HUD_COLOUR_BLUE = cfgColors.ReadRGBA("Colors", "HUD_COLOUR_BLUE", Colors.HUD_COLOUR_BLUE);
        Colors.HUD_COLOUR_YELLOW = cfgColors.ReadRGBA("Colors", "HUD_COLOUR_YELLOW", Colors.HUD_COLOUR_YELLOW);
#else
        Colors.MoneyColor = cfgColors.ReadRGBA("Colors", "MoneyColor", Colors.MoneyColor);
        Colors.HealthColor = cfgColors.ReadRGBA("Colors", "HealthColor", Colors.HealthColor);
        Colors.HealthIconColor = cfgColors.ReadRGBA("Colors", "HealthIconColor", Colors.HealthIconColor);
        Colors.ArmorColor = cfgColors.ReadRGBA("Colors", "ArmorColor", Colors.ArmorColor);
        Colors.ArmorIconColor = cfgColors.ReadRGBA("Colors", "ArmorIconColor", Colors.ArmorIconColor);
        Colors.AmmoColor = cfgColors.ReadRGBA("Colors", "AmmoColor", Colors.AmmoColor);
        Colors.WantedActiveColor = cfgColors.ReadRGBA("Colors", "WantedActiveColor", Colors.WantedActiveColor);
        Colors.WantedSuspendedColor = cfgColors.ReadRGBA("Colors", "WantedSuspendedColor", Colors.WantedSuspendedColor);
        Colors.WantedInactiveColor = cfgColors.ReadRGBA("Colors", "WantedInactiveColor", Colors.WantedInactiveColor);
        Colors.ZoneColor = cfgColors.ReadRGBA("Colors", "ZoneColor", Colors.ZoneColor);
        Colors.VehicleColor = cfgColors.ReadRGBA("Colors", "VehicleColor", Colors.VehicleColor);
        Colors.TimeColor = cfgColors.ReadRGBA("Colors", "TimeColor", Colors.TimeColor);
        Colors.MoneyShadowColor = cfgColors.ReadRGBA("Colors", "MoneyShadowColor", Colors.MoneyShadowColor);
        Colors.AmmoShadowColor = cfgColors.ReadRGBA("Colors", "AmmoShadowColor", Colors.AmmoShadowColor);
        Colors.ZoneShadowColor = cfgColors.ReadRGBA("Colors", "ZoneShadowColor", Colors.ZoneShadowColor);
        Colors.VehicleShadowColor = cfgColors.ReadRGBA("Colors", "VehicleShadowColor", Colors.VehicleShadowColor);
        Colors.TimeShadowColor = cfgColors.ReadRGBA("Colors", "TimeShadowColor", Colors.TimeShadowColor);
        Colors.HAWShadowColor = cfgColors.ReadRGBA("Colors", "HAWShadowColor", Colors.HAWShadowColor);
        Colors.TimerColor = cfgColors.ReadRGBA("Colors", "TimerColor", Colors.TimerColor);
        Colors.TimerTextColor = cfgColors.ReadRGBA("Colors", "TimerTextColor", Colors.TimerColor);
        Colors.CounterColor = cfgColors.ReadRGBA("Colors", "CounterColor", Colors.CounterColor);
        Colors.CounterTextColor = cfgColors.ReadRGBA("Colors", "CounterTextColor", Colors.CounterColor);
        Colors.OddJobColor = cfgColors.ReadRGBA("Colors", "OddJobColor", Colors.OddJobColor);
        Colors.OddJobShadowColor = cfgColors.ReadRGBA("Colors", "OddJobShadowColor", Colors.OddJobShadowColor);
        Colors.OddJob2Color = cfgColors.ReadRGBA("Colors", "OddJob2Color", Colors.OddJob2Color);
        Colors.OddJob2ShadowColor = cfgColors.ReadRGBA("Colors", "OddJob2ShadowColor", Colors.OddJob2ShadowColor);
        Colors.MissionTitleColor = cfgColors.ReadRGBA("Colors", "MissionTitleColor", Colors.MissionTitleColor);
        Colors.BigMessageColor = cfgColors.ReadRGBA("Colors", "BigMessageColor", Colors.BigMessageColor);
        Colors.WastedBustedColor = cfgColors.ReadRGBA("Colors", "WastedBustedColor", Colors.WastedBustedColor);
        Colors.SubtitleColor = cfgColors.ReadRGBA("Colors", "SubtitleColor", Colors.SubtitleColor);
        Colors.SubtitleShadowColor = cfgColors.ReadRGBA("Colors", "SubtitleShadowColor", Colors.SubtitleShadowColor);
        Colors.BriefTextColor = cfgColors.ReadRGBA("Colors", "BriefTextColor", Colors.BriefTextColor);
        Colors.HelpTextColor = cfgColors.ReadRGBA("Colors", "HelpTextColor", Colors.HelpTextColor);
#endif
    }
    return true;
}

void ColorsConfig::Write() {
    std::string colorsPath;

    colorsPath = COLORS_INI_PATH;
    ConfigHelper cfgColors(colorsPath);

    cfgColors.WriteInt("Settings", "ReloadKey", ReloadKey, "Key to reload color settings in-game (Virtual Key code)");
    cfgColors.WriteInt("Settings", "DefaultOverride", DefaultOverride, "Force default settings override for game style (-1 = off, 0 = GTA III, 1 = GTA VC, 2 = GTA SA, 3 = GTA IV, 4 = GTA V, 5 = GTA LCS, 6 = GTA VCS)");
    cfgColors.WriteInt("Settings", "RandomColors", RandomColors, "Randomize HUD colors (0 = off, 1 = on)");
    cfgColors.WriteFloat("Settings", "RandomColorsSpeed", RandomColorsSpeed, "Speed multiplier for Rainbomizer mode (1.0 = normal/per-frame, 0.5 = half speed, 0.25 = quarter speed, etc.)");
#ifdef GTA3
    cfgColors.WriteInt("Settings", "LeaveDropShadowPrintStringsUnpatched", LeaveDropShadowPrintStringsUnpatched, "0 = patch GTA III drop shadow printstrings to zero alpha, 1 = leave drop shadow printstrings unpatched");
    cfgColors.WriteInt("Settings", "EnableShadowColoring", EnableShadowColoring, "0 = disable HUD element shadow coloring in GTA III, 1 = enable HUD element shadow coloring in GTA III");
#endif

#ifdef GTASA
    cfgColors.WriteRGBA("Colors", "HUD_COLOUR_RED", Colors.HUD_COLOUR_RED);
    cfgColors.WriteRGBA("Colors", "HUD_COLOUR_GREEN", Colors.HUD_COLOUR_GREEN);
    cfgColors.WriteRGBA("Colors", "HUD_COLOUR_BLUEDARK", Colors.HUD_COLOUR_BLUEDARK);
    cfgColors.WriteRGBA("Colors", "HUD_COLOUR_BLUELIGHT", Colors.HUD_COLOUR_BLUELIGHT);
    cfgColors.WriteRGBA("Colors", "HUD_COLOUR_WHITE", Colors.HUD_COLOUR_WHITE);
    cfgColors.WriteRGBA("Colors", "HUD_COLOUR_BLACK", Colors.HUD_COLOUR_BLACK);
    cfgColors.WriteRGBA("Colors", "HUD_COLOUR_ORANGE", Colors.HUD_COLOUR_ORANGE);
    cfgColors.WriteRGBA("Colors", "HUD_COLOUR_PURPLE", Colors.HUD_COLOUR_PURPLE);
    cfgColors.WriteRGBA("Colors", "HUD_COLOUR_GREY", Colors.HUD_COLOUR_GREY);
    cfgColors.WriteRGBA("Colors", "HUD_COLOUR_REDDARK", Colors.HUD_COLOUR_REDDARK);
    cfgColors.WriteRGBA("Colors", "HUD_COLOUR_GREENDARK", Colors.HUD_COLOUR_GREENDARK);
    cfgColors.WriteRGBA("Colors", "HUD_COLOUR_ORANGELIGHT", Colors.HUD_COLOUR_ORANGELIGHT);
    cfgColors.WriteRGBA("Colors", "HUD_COLOUR_GREYDARK", Colors.HUD_COLOUR_GREYDARK);
    cfgColors.WriteRGBA("Colors", "HUD_COLOUR_BLUE", Colors.HUD_COLOUR_BLUE);
    cfgColors.WriteRGBA("Colors", "HUD_COLOUR_YELLOW", Colors.HUD_COLOUR_YELLOW);
#else
    cfgColors.WriteRGBA("Colors", "MoneyColor", Colors.MoneyColor);
    cfgColors.WriteRGBA("Colors", "HealthColor", Colors.HealthColor);
    cfgColors.WriteRGBA("Colors", "HealthIconColor", Colors.HealthIconColor);
    cfgColors.WriteRGBA("Colors", "ArmorColor", Colors.ArmorColor);
    cfgColors.WriteRGBA("Colors", "ArmorIconColor", Colors.ArmorIconColor);
    cfgColors.WriteRGBA("Colors", "AmmoColor", Colors.AmmoColor);
    cfgColors.WriteRGBA("Colors", "WantedActiveColor", Colors.WantedActiveColor);
    cfgColors.WriteRGBA("Colors", "WantedSuspendedColor", Colors.WantedSuspendedColor);
    cfgColors.WriteRGBA("Colors", "WantedInactiveColor", Colors.WantedInactiveColor);
    cfgColors.WriteRGBA("Colors", "ZoneColor", Colors.ZoneColor);
    cfgColors.WriteRGBA("Colors", "VehicleColor", Colors.VehicleColor);
    cfgColors.WriteRGBA("Colors", "TimeColor", Colors.TimeColor);
    cfgColors.WriteRGBA("Colors", "MoneyShadowColor", Colors.MoneyShadowColor);
    cfgColors.WriteRGBA("Colors", "AmmoShadowColor", Colors.AmmoShadowColor);
    cfgColors.WriteRGBA("Colors", "ZoneShadowColor", Colors.ZoneShadowColor);
    cfgColors.WriteRGBA("Colors", "VehicleShadowColor", Colors.VehicleShadowColor);
    cfgColors.WriteRGBA("Colors", "TimeShadowColor", Colors.TimeShadowColor);
    cfgColors.WriteRGBA("Colors", "HAWShadowColor", Colors.HAWShadowColor);
    cfgColors.WriteRGBA("Colors", "TimerColor", Colors.TimerColor);
    cfgColors.WriteRGBA("Colors", "TimerTextColor", Colors.TimerTextColor);
    cfgColors.WriteRGBA("Colors", "CounterColor", Colors.CounterColor);
    cfgColors.WriteRGBA("Colors", "CounterTextColor", Colors.CounterTextColor);
    cfgColors.WriteRGBA("Colors", "OddJobColor", Colors.OddJobColor);
    cfgColors.WriteRGBA("Colors", "OddJobShadowColor", Colors.OddJobShadowColor);
    cfgColors.WriteRGBA("Colors", "OddJob2Color", Colors.OddJob2Color);
    cfgColors.WriteRGBA("Colors", "OddJob2ShadowColor", Colors.OddJob2ShadowColor);
    cfgColors.WriteRGBA("Colors", "MissionTitleColor", Colors.MissionTitleColor);
    cfgColors.WriteRGBA("Colors", "BigMessageColor", Colors.BigMessageColor);
    cfgColors.WriteRGBA("Colors", "WastedBustedColor", Colors.WastedBustedColor);
    cfgColors.WriteRGBA("Colors", "SubtitleColor", Colors.SubtitleColor);
    cfgColors.WriteRGBA("Colors", "SubtitleShadowColor", Colors.SubtitleShadowColor);
    cfgColors.WriteRGBA("Colors", "BriefTextColor", Colors.BriefTextColor);
    cfgColors.WriteRGBA("Colors", "HelpTextColor", Colors.HelpTextColor);
#endif

    cfgColors.Format("; colors_config.ini - ChangeHUDColors configuration\n"
                      "; Settings, parameters for HUD element colors\n");
}

void ColorsConfig::GenerateDefault() {
    std::string colorsPath;

    colorsPath = COLORS_INI_PATH;
    ConfigHelper cfgColors(colorsPath);

    if (!cfgColors.Exists()) {
        Write();
    }
}
