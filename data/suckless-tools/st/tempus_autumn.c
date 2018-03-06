/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#322622", /* black   */
  [1] = "#fc5526", /* red     */
  [2] = "#83973f", /* green   */
  [3] = "#9e9022", /* yellow  */
  [4] = "#7f8dbf", /* blue    */
  [5] = "#ce7673", /* magenta */
  [6] = "#6e978b", /* cyan    */
  [7] = "#919078", /* white   */

  /* 8 bright colors */
  [8]  = "#35260f", /* black   */
  [9]  = "#dc721a", /* red     */
  [10] = "#609d59", /* green   */
  [11] = "#b1891a", /* yellow  */
  [12] = "#6b8ed6", /* blue    */
  [13] = "#9d80d3", /* magenta */
  [14] = "#229ea0", /* cyan    */
  [15] = "#8e8f8d", /* white   */

  /* special colors */
  [256] = "#322622", /* background */
  [257] = "#8e8f8d", /* foreground */
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
