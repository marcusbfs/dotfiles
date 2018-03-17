/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#252525", /* black   */
  [1] = "#ed4a46", /* red     */
  [2] = "#70b433", /* green   */
  [3] = "#dbb32d", /* yellow  */
  [4] = "#368aeb", /* blue    */
  [5] = "#eb6eb7", /* magenta */
  [6] = "#3fc5b7", /* cyan    */
  [7] = "#777777", /* white   */

  /* 8 bright colors */
  [8]  = "#3b3b3b", /* black   */
  [9]  = "#ff5e56", /* red     */
  [10] = "#83c746", /* green   */
  [11] = "#efc541", /* yellow  */
  [12] = "#4f9cfe", /* blue    */
  [13] = "#ff81ca", /* magenta */
  [14] = "#56d8c9", /* cyan    */
  [15] = "#dedede", /* white   */

  /* special colors */
  [256] = "#181818", /* background */
  [257] = "#b9b9b9", /* foreground */
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
