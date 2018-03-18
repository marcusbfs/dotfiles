/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#000000", /* black   */
  [1] = "#6b6b6b", /* red     */
  [2] = "#c4c4c4", /* green   */
  [3] = "#b3b3b3", /* yellow  */
  [4] = "#999999", /* blue    */
  [5] = "#717171", /* magenta */
  [6] = "#8a8a8a", /* cyan    */
  [7] = "#b5cabb", /* white   */

  /* 8 bright colors */
  [8]  = "#202020", /* black   */
  [9]  = "#464646", /* red     */
  [10] = "#f8f8f8", /* green   */
  [11] = "#eeeeee", /* yellow  */
  [12] = "#7c7c7c", /* blue    */
  [13] = "#adadad", /* magenta */
  [14] = "#c0c0c0", /* cyan    */
  [15] = "#99ac9e", /* white   */

  /* special colors */
  [256] = "#000000", /* background */
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
