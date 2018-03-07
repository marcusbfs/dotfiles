/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#4d4d4d", /* black   */
  [1] = "#C70031", /* red     */
  [2] = "#29CF13", /* green   */
  [3] = "#D8E30E", /* yellow  */
  [4] = "#3449D1", /* blue    */
  [5] = "#8400FF", /* magenta */
  [6] = "#0798AB", /* cyan    */
  [7] = "#E2D1E3", /* white   */

  /* 8 bright colors */
  [8]  = "#5a5a5a", /* black   */
  [9]  = "#F05178", /* red     */
  [10] = "#6CE05C", /* green   */
  [11] = "#F3F79E", /* yellow  */
  [12] = "#97A4F7", /* blue    */
  [13] = "#C495F0", /* magenta */
  [14] = "#68F2E0", /* cyan    */
  [15] = "#FFFFFF", /* white   */

  /* special colors */
  [256] = "#151515", /* background */
  [257] = "#aeaeae", /* foreground */
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
