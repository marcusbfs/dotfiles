/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#1C1C1C", /* black   */
  [1] = "#ff005b", /* red     */
  [2] = "#cee318", /* green   */
  [3] = "#ffe755", /* yellow  */
  [4] = "#048ac7", /* blue    */
  [5] = "#833c9f", /* magenta */
  [6] = "#0ac1cd", /* cyan    */
  [7] = "#e5e5e5", /* white   */

  /* 8 bright colors */
  [8]  = "#666666", /* black   */
  [9]  = "#ff00a0", /* red     */
  [10] = "#ccff00", /* green   */
  [11] = "#ff9f00", /* yellow  */
  [12] = "#48c6ff", /* blue    */
  [13] = "#be67e1", /* magenta */
  [14] = "#63e7f0", /* cyan    */
  [15] = "#f3f3f3", /* white   */

  /* special colors */
  [256] = "#1C1C1C", /* background */
  [257] = "#c5c5c5", /* foreground */
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
