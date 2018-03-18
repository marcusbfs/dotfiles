/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#FBFBFB", /* black   */
  [1] = "#FFFFFF", /* red     */
  [2] = "#CACACA", /* green   */
  [3] = "#D9D9D9", /* yellow  */
  [4] = "#727272", /* blue    */
  [5] = "#636363", /* magenta */
  [6] = "#9E9E9E", /* cyan    */
  [7] = "#BDBDBD", /* white   */

  /* 8 bright colors */
  [8]  = "#494949", /* black   */
  [9]  = "#EAEAEA", /* red     */
  [10] = "#C9C9C9", /* green   */
  [11] = "#DDDDDD", /* yellow  */
  [12] = "#4F4F4F", /* blue    */
  [13] = "#4D4D4D", /* magenta */
  [14] = "#505050", /* cyan    */
  [15] = "#EEEEEE", /* white   */

  /* special colors */
  [256] = "#101010", /* background */
  [257] = "#A0A0A0", /* foreground */
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
