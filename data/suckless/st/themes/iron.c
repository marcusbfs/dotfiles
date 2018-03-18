/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#101010", /* black   */
  [1] = "#252525", /* red     */
  [2] = "#464646", /* green   */
  [3] = "#525252", /* yellow  */
  [4] = "#2a2a2a", /* blue    */
  [5] = "#b9b9b9", /* magenta */
  [6] = "#e3e3e3", /* cyan    */
  [7] = "#f7f7f7", /* white   */

  /* 8 bright colors */
  [8]  = "#7c7c7c", /* black   */
  [9]  = "#999999", /* red     */
  [10] = "#a0a0a0", /* green   */
  [11] = "#8e8e8e", /* yellow  */
  [12] = "#333333", /* blue    */
  [13] = "#686868", /* magenta */
  [14] = "#747474", /* cyan    */
  [15] = "#5e5e5e", /* white   */

  /* special colors */
  [256] = "#0f0e0f", /* background */
  [257] = "#abaeac", /* foreground */
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
