/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#141a19", /* black   */
  [1] = "#ff1414", /* red     */
  [2] = "#009600", /* green   */
  [3] = "#928100", /* yellow  */
  [4] = "#4f76ff", /* blue    */
  [5] = "#dd38bc", /* magenta */
  [6] = "#358aaa", /* cyan    */
  [7] = "#927b80", /* white   */

  /* 8 bright colors */
  [8]  = "#201428", /* black   */
  [9]  = "#ff5500", /* red     */
  [10] = "#3aa43a", /* green   */
  [11] = "#b38a00", /* yellow  */
  [12] = "#8082ff", /* blue    */
  [13] = "#d159fd", /* magenta */
  [14] = "#1da190", /* cyan    */
  [15] = "#928f90", /* white   */

  /* special colors */
  [256] = "#141a19", /* background */
  [257] = "#928f90", /* foreground */
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
