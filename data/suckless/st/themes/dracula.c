/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#000000", /* black   */
  [1] = "#FF5555", /* red     */
  [2] = "#50FA7B", /* green   */
  [3] = "#F1FA8C", /* yellow  */
  [4] = "#BD93F9", /* blue    */
  [5] = "#FF79C6", /* magenta */
  [6] = "#8BE9FD", /* cyan    */
  [7] = "#BFBFBF", /* white   */

  /* 8 bright colors */
  [8]  = "#4D4D4D", /* black   */
  [9]  = "#FF6E67", /* red     */
  [10] = "#5AF78E", /* green   */
  [11] = "#F4F99D", /* yellow  */
  [12] = "#CAA9FA", /* blue    */
  [13] = "#FF92D0", /* magenta */
  [14] = "#9AEDFE", /* cyan    */
  [15] = "#E6E6E6", /* white   */

  /* special colors */
  [256] = "#282A36", /* background */
  [257] = "#F8F8F2", /* foreground */
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
