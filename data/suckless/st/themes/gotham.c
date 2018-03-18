/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#0a0f14", /* black   */
  [1] = "#c33027", /* red     */
  [2] = "#26a98b", /* green   */
  [3] = "#edb54b", /* yellow  */
  [4] = "#195465", /* blue    */
  [5] = "#4e5165", /* magenta */
  [6] = "#33859d", /* cyan    */
  [7] = "#98d1ce", /* white   */

  /* 8 bright colors */
  [8]  = "#10151b", /* black   */
  [9]  = "#d26939", /* red     */
  [10] = "#081f2d", /* green   */
  [11] = "#245361", /* yellow  */
  [12] = "#093748", /* blue    */
  [13] = "#888ba5", /* magenta */
  [14] = "#599caa", /* cyan    */
  [15] = "#d3ebe9", /* white   */

  /* special colors */
  [256] = "#0a0f14", /* background */
  [257] = "#98d1ce", /* foreground */
};

/*
 * Default colors (colorname index)
 * foreground, background, cursor
 */
unsigned int defaultfg = 257;
unsigned int defaultbg = 256;
unsigned int defaultcs = 257;
unsigned int defaultrcs = 257;

/*
 * Colors used, when the specific fg == defaultfg. So in reverse mode this
 * will reverse too. Another logic would only make the simple feature too
 * complex.
 */
unsigned int defaultitalic = 7;
unsigned int defaultunderline = 7;
