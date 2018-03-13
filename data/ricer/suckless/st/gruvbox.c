const char *colorname[] = {
	/* 8 normal colors */
    "#282828", /* hard contrast: #1d2021 / soft contrast: #32302f */
    "#cc241d",
    "#98971a",
    "#d79921",
    "#458588",
    "#b16286",
    "#689d6a",
    "#a89984",

	/* 8 bright colors */
    "#928374",
    "#fb4934",
    "#b8bb26",
    "#fabd2f",
    "#83a598",
    "#d3869b",
    "#8ec07c",
    "#ebdbb2",

	[255] = 0,

	/* more colors can be added after 255 to use with DefaultXX */
	"#cccccc",
	"#555555",
};


/*
 * Default colors (colorname index)
 * foreground, background, cursor, reverse cursor
 */
unsigned int defaultfg = 15;
unsigned int defaultbg = 0;
unsigned int defaultcs = 15;
unsigned int defaultrcs = 257;
