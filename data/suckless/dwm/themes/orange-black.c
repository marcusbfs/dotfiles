static const char norm_fg[] = "#abbbc1";
static const char norm_bg[] = "#0f110e";
static const char norm_border[] = "#778287";

static const char sel_fg[] = "#abbbc1";
static const char sel_bg[] = "#B66011";
static const char sel_border[] = "#ff4900";

static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
};
