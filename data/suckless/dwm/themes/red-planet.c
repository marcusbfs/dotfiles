static const char norm_fg[] = "#a4bcd4";
static const char norm_bg[] = "#0f141d";
static const char norm_border[] = "#728394";

static const char sel_fg[] = "#a4bcd4";
static const char sel_bg[] = "#9D5653";
static const char sel_border[] = "#FE3F56";


static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
};
