static const char norm_fg[] = "#c9e0e8";
static const char norm_bg[] = "#3e2534";
static const char norm_border[] = "#8c9ca2";

static const char sel_fg[] = "#c9e0e8";
static const char sel_bg[] = "#6091AC";
static const char sel_border[] = "#00f7ff";


static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
};
