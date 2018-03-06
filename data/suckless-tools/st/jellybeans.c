/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#888888", /* black   */
  [1] = "#cf6a4c", /* red     */
  [2] = "#99ad6a", /* green   */
  [3] = "#fad07a", /* yellow  */
  [4] = "#8197bf", /* blue    */
  [5] = "#8787af", /* magenta */
  [6] = "#8fbfdc", /* cyan    */
  [7] = "#888888", /* white   */

  /* 8 bright colors */
  [8]  = "#525252", /* black   */
  [9]  = "#ff9d80", /* red     */
  [10] = "#c3e6ad", /* green   */
  [11] = "#ffefbf", /* yellow  */
  [12] = "#accaff", /* blue    */
  [13] = "#c4c4ff", /* magenta */
  [14] = "#80bfaf", /* cyan    */
  [15] = "#e8e8d3", /* white   */

  /* special colors */
  [256] = "#151515", /* background */
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
