/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#282c34", /* black   */
  [1] = "#e06c75", /* red     */
  [2] = "#98c379", /* green   */
  [3] = "#e5c07b", /* yellow  */
  [4] = "#61afef", /* blue    */
  [5] = "#c678dd", /* magenta */
  [6] = "#56b6c2", /* cyan    */
  [7] = "#abb2bf", /* white   */

  /* 8 bright colors */
  [8]  = "#4b5263", /* black   */
  [9]  = "#be5046", /* red     */
  [10] = "#98c379", /* green   */
  [11] = "#d19a66", /* yellow  */
  [12] = "#61afef", /* blue    */
  [13] = "#c678dd", /* magenta */
  [14] = "#56b6c2", /* cyan    */
  [15] = "#5c6370", /* white   */

  /* special colors */
  [256] = "#282c34", /* background */
  [257] = "#abb2bf", /* foreground */
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
