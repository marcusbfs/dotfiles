/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#262626", /* black   */
  [1] = "#830e0c", /* red     */
  [2] = "#a72b28", /* green   */
  [3] = "#c64b48", /* yellow  */
  [4] = "#ed7c79", /* blue    */
  [5] = "#ffaba9", /* magenta */
  [6] = "#ffcecb", /* cyan    */
  [7] = "#eaeaea", /* white   */

  /* 8 bright colors */
  [8]  = "#616161", /* black   */
  [9]  = "#c84f4c", /* red     */
  [10] = "#ef8380", /* green   */
  [11] = "#ffb1af", /* yellow  */
  [12] = "#ffd1d0", /* blue    */
  [13] = "#ffe9e9", /* magenta */
  [14] = "#fff8f8", /* cyan    */
  [15] = "#ffffff", /* white   */

  /* special colors */
  [256] = "#101010", /* background */
  [257] = "#ffffff", /* foreground */
};

/*
 * Default colors (colorname index)
 * foreground, background, cursor
 */
unsigned int defaultfg = 257;
unsigned int defaultbg = 256;
unsigned int defaultcs = 257;
unsigned int defaultrcs = 256;

/*
 * Colors used, when the specific fg == defaultfg. So in reverse mode this
 * will reverse too. Another logic would only make the simple feature too
 * complex.
 */
unsigned int defaultitalic = 7;
unsigned int defaultunderline = 7;
