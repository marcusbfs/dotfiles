static const char norm_fg[]     = "#cfdbcf";
static const char norm_bg[]     = "#153d2f";
static const char norm_border[] = "#909990";

static const char sel_fg[]      = "#cfdbcf";
static const char sel_bg[]      = "#6D998B";
static const char sel_border[]  = "#2ff1ad";

static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border  },  // the focused win
};
