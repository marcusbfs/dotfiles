/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#ebebeb", /* black   */
  [1] = "#d6000c", /* red     */
  [2] = "#1d9700", /* green   */
  [3] = "#c49700", /* yellow  */
  [4] = "#0064e4", /* blue    */
  [5] = "#dd0f9d", /* magenta */
  [6] = "#00ad9c", /* cyan    */
  [7] = "#878787", /* white   */

  /* 8 bright colors */
  [8]  = "#cdcdcd", /* black   */
  [9]  = "#bf0000", /* red     */
  [10] = "#008400", /* green   */
  [11] = "#af8500", /* yellow  */
  [12] = "#0054cf", /* blue    */
  [13] = "#c7008b", /* magenta */
  [14] = "#009a8a", /* cyan    */
  [15] = "#282828", /* white   */

  /* special colors */
  [256] = "#ffffff", /* background */
  [257] = "#474747", /* foreground */
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
