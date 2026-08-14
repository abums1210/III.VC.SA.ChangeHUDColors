#pragma once
#include "ConfigHelper.h"

enum DefaultColorPreset {
    GTA_III_COLOR = 0,
    GTA_VC_COLOR,
    GTA_SA_COLOR,
    GTA_IV_COLOR,
    GTA_V_COLOR,
    GTA_LCS_COLOR,
    GTA_VCS_COLOR,
    TOTAL_COLORDEFAULTS = 7
};

struct GlobalHudDefaultColors {
    CRGBA MoneyColor;
    CRGBA HealthColor;
    CRGBA HealthIconColor;
    CRGBA ArmorColor;
    CRGBA ArmorIconColor;
    CRGBA AmmoColor;
    CRGBA WantedActiveColor;
    CRGBA WantedSuspendedColor;
    CRGBA WantedInactiveColor;
    CRGBA ZoneColor;
    CRGBA VehicleColor;
    CRGBA TimeColor;
    CRGBA MoneyShadowColor;
    CRGBA AmmoShadowColor;
    CRGBA ZoneShadowColor;
    CRGBA VehicleShadowColor;
    CRGBA TimeShadowColor;
    CRGBA HAWShadowColor; //Health Armor Wanted = HAW
    CRGBA TimerColor;
    CRGBA TimerTextColor;
    CRGBA CounterColor;
    CRGBA CounterTextColor;
    CRGBA OddJobColor;
    CRGBA OddJobShadowColor;
    CRGBA OddJob2Color;
    CRGBA OddJob2ShadowColor;
    CRGBA MissionTitleColor;
    CRGBA BigMessageColor;
    CRGBA WastedBustedColor;
    CRGBA SubtitleColor;
    CRGBA SubtitleShadowColor;
    CRGBA BriefTextColor;
    CRGBA HelpTextColor;
};

#ifdef GTASA
struct HudColorInfo {
    CRGBA HUD_COLOUR_RED;
    CRGBA HUD_COLOUR_GREEN;
    CRGBA HUD_COLOUR_BLUEDARK;
    CRGBA HUD_COLOUR_BLUELIGHT;
    CRGBA HUD_COLOUR_WHITE;
    CRGBA HUD_COLOUR_BLACK;
    CRGBA HUD_COLOUR_ORANGE;
    CRGBA HUD_COLOUR_PURPLE;
    CRGBA HUD_COLOUR_GREY;
    CRGBA HUD_COLOUR_REDDARK;
    CRGBA HUD_COLOUR_GREENDARK;
    CRGBA HUD_COLOUR_ORANGELIGHT;
    CRGBA HUD_COLOUR_GREYDARK;
    CRGBA HUD_COLOUR_BLUE;
    CRGBA HUD_COLOUR_YELLOW;
};
#else
typedef GlobalHudDefaultColors HudColorInfo;
#endif

class ColorsConfig {
  public:
    int ReloadKey, DefaultOverride, RandomColors;
#ifdef GTA3
    int LeaveDropShadowPrintStringsUnpatched, EnableShadowColoring;
#endif
    float RandomColorsSpeed;
    HudColorInfo Colors;

    ColorsConfig();

    bool Read();
    void Write();
    void GenerateDefault();
};
extern ColorsConfig config;