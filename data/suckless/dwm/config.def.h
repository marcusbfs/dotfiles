/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int start_with_gap = 0;
static const unsigned int gap_px = 20; /* gap pixel between windows */
static const unsigned int borderpx  = 5;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int viewontag          = 1;     /* Switch view on tag switch */
#define SAME_FONT "ProggyCleanTTSZ:style=Regular:size=12"
static const char *fonts[]          = { SAME_FONT };
static const char dmenufont[]       = SAME_FONT;

#include "themes/red-planet.c"

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Emacs",         NULL,       NULL,       1 << 8,       0,           -1 },
	{ "Firefox",       NULL,       NULL,       1 << 1,       0,           -1 },
	{ "Google-chrome", NULL,       NULL,       1 << 1,       0,           -1 },
	{ "Vlc",           NULL,       NULL,       1 << 2,       0,           -1 },
	{ "mpv",           NULL,       NULL,       1 << 2,       1,           -1 },
	{ "qutebrowser",   NULL,       NULL,       1 << 1,       0,           -1 },
	{ "st-float",      NULL,       NULL,            0,       1,           -1 },
};

/* layout(s) */
#include "gaplessgrid.c"

static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "###",      gaplessgrid },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/bash", "-c", cmd, NULL } }
// https://github.com/cdown/dwm/blob/master/config.h
#define ESHCMD(cmd) SHCMD("exec " cmd)
// my stuff
#define _dwm_path "$HOME/workspace/outros/dotfiles/data/suckless/"
#define _dwm_function(fname) SHCMD("cat "_dwm_path"functions.sh | bash -s "fname)
#define scripts_bin_func(fname) ESHCMD("/usr/bin/python $HOME/.scripts/bin/"fname)

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-i", "-m", dmenumon, "-fn", dmenufont, "-nb", norm_bg, "-nf", norm_fg, "-sb", sel_bg, "-sf", sel_fg, NULL };
static const char *termcmd[]  = { "st", NULL };

#include "movestack.c"
#include "moveresize.c"
#include "togglefullscreen.c"
#include <X11/XF86keysym.h>

static Key keys[] = {
    /* modifier                     key        function        argument */
    // cmds
    {  MODKEY,              XK_p,      spawn,  {.v  =  dmenucmd  }  },
    {  MODKEY,              XK_Return, spawn,  {.v  =  termcmd   }  },
    {  MODKEY,              XK_r,      spawn,  ESHCMD("st -e ranger") },
    {  MODKEY|ControlMask,  XK_g,      togglegaps, {0}},
    {  MODKEY,              XK_a,      spawn,  ESHCMD("st -e ncpamixer")  },
    {  MODKEY|ShiftMask,    XK_a,      spawn,  scripts_bin_func("toggle-audio-output.py") },
    {  MODKEY|ShiftMask,    XK_x,      spawn,  scripts_bin_func("screen-lock.py")          },
    {  MODKEY,              XK_Print,  spawn,  ESHCMD("maim -m 1 -s | xclip -selection clipboard -t image/png") },
    {  MODKEY|ShiftMask,    XK_Print,  spawn,  ESHCMD("gnome-screenshot --interactive")       },
    {  MODKEY,              XK_Insert, spawn,  ESHCMD("clipmenu")       },
    {  MODKEY,              XK_s,      spawn,  SHCMD("read -r X Y W H < <(slop -f '%x %y %w %h' -b 1 -t 0 -q); (( W     /= 8   )); (( H /= 16   )); g=${W}x${H}+${X}+${Y}; st -c st-float -g $g") },
    {  MODKEY,              XK_c,      spawn,  SHCMD("wine $HOME/workspace/outros/dotfiles/data/Flat50G/Calculator/Emu48.exe") },
    {  0,                   XF86XK_AudioPlay,  spawn,  ESHCMD("mpc toggle")  },
    {  0,                   XF86XK_AudioStop,  spawn,  ESHCMD("mpc stop")  },
    {  0,                   XF86XK_AudioNext,  spawn,  ESHCMD("mpc next")  },
    {  0,                   XF86XK_AudioPrev,  spawn,  ESHCMD("mpc prev")  },
    {  MODKEY,              XK_b,              togglebar,  {0}  },
    // move
    {  MODKEY,              XK_j,      focusstack,  {.i  =   +1  }  },
    {  MODKEY,              XK_k,      focusstack,  {.i  =   -1  }  },
    {  MODKEY|ShiftMask,    XK_j,      movestack,   {.i  =   +1  }  },
    {  MODKEY|ShiftMask,    XK_k,      movestack,   {.i  =   -1  }  },
    {  MODKEY|ShiftMask,    XK_Return, zoom,        {0}  },
    {  MODKEY,              XK_Tab,    view,        {0}  },
    {  MODKEY,              XK_q,      killclient,  {0}  },
    {  MODKEY|ShiftMask,    XK_q,      killclient,  {0}  },
    // resize
    {  MODKEY,              XK_i,      incnmaster,     {.i = +1 } },
    {  MODKEY,              XK_d,      incnmaster,     {.i = -1 } },
    {  MODKEY,              XK_h,      setmfact,       {.f = -0.05} },
    {  MODKEY,              XK_l,      setmfact,       {.f = +0.05} },
    {  MODKEY,              XK_Down,   moveresize,     {.v = "0x 25y 0w 0h"} },
    {  MODKEY,              XK_Up,     moveresize,     {.v = "0x -25y 0w 0h"} },
    {  MODKEY,              XK_Right,  moveresize,     {.v = "25x 0y 0w 0h"} },
    {  MODKEY,              XK_Left,   moveresize,     {.v = "-25x 0y 0w 0h"} },
    {  MODKEY|ShiftMask,    XK_Down,   moveresize,     {.v = "0x 0y 0w 25h"} },
    {  MODKEY|ShiftMask,    XK_Up,     moveresize,     {.v = "0x 0y 0w -25h"} },
    {  MODKEY|ShiftMask,    XK_Right,  moveresize,     {.v = "0x 0y 25w 0h"} },
    {  MODKEY|ShiftMask,    XK_Left,   moveresize,     {.v = "0x 0y -25w 0h"} },
    // layout
    {  MODKEY,              XK_t,      setlayout,      {.v = &layouts[0]} },
    {  MODKEY|ShiftMask,    XK_f,      setlayout,      {.v = &layouts[1]} },
    {  MODKEY,              XK_m,      setlayout,      {.v = &layouts[2]} },
    {  MODKEY,              XK_g,      setlayout,      {.v = &layouts[3]} },
    {  MODKEY,              XK_f,      togglefullscreen,{0} },
    {  MODKEY,              XK_space,  setlayout,       {0}  },
    {  MODKEY|ShiftMask,    XK_space,  togglefloating,  {0}  },
    // others
    {  MODKEY,              XK_0,      view,      {.ui  =  ~0  }  },
    {  MODKEY|ShiftMask,    XK_0,      tag,       {.ui  =  ~0  }  },
    {  MODKEY,              XK_comma,  focusmon,  {.i   =  -1  }  },
    {  MODKEY,              XK_period, focusmon,  {.i   =  +1  }  },
    {  MODKEY|ShiftMask,    XK_comma,  tagmon,    {.i   =  -1  }  },
    {  MODKEY|ShiftMask,    XK_period, tagmon,    {.i   =  +1  }  },
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    { MODKEY|ShiftMask,             XK_e,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

