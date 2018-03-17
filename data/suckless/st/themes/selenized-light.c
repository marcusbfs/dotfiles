/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#ece3cc", /* black   */
  [1] = "#d2212d", /* red     */
  [2] = "#489100", /* green   */
  [3] = "#ad8900", /* yellow  */
  [4] = "#0072d4", /* blue    */
  [5] = "#ca4898", /* magenta */
  [6] = "#009c8f", /* cyan    */
  [7] = "#909995", /* white   */

  /* 8 bright colors */
  [8]  = "#d5cdb6", /* black   */
  [9]  = "#cc1729", /* red     */
  [10] = "#428b00", /* green   */
  [11] = "#a78300", /* yellow  */
  [12] = "#006dce", /* blue    */
  [13] = "#c44392", /* magenta */
  [14] = "#00978a", /* cyan    */
  [15] = "#3a4d53", /* white   */

  /* special colors */
  [256] = "#fbf3db", /* background */
  [257] = "#53676d", /* foreground */
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
