/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#001100", /* black   */
  [1] = "#007700", /* red     */
  [2] = "#00bb00", /* green   */
  [3] = "#007700", /* yellow  */
  [4] = "#009900", /* blue    */
  [5] = "#00bb00", /* magenta */
  [6] = "#005500", /* cyan    */
  [7] = "#00bb00", /* white   */

  /* 8 bright colors */
  [8]  = "#007700", /* black   */
  [9]  = "#007700", /* red     */
  [10] = "#00bb00", /* green   */
  [11] = "#007700", /* yellow  */
  [12] = "#009900", /* blue    */
  [13] = "#00bb00", /* magenta */
  [14] = "#005500", /* cyan    */
  [15] = "#00ff00", /* white   */

  /* special colors */
  [256] = "#001100", /* background */
  [257] = "#00bb00", /* foreground */
};

/*
 * Default colors (colorname index)
 * foreground, background, cursor
 */
unsigned int defaultfg = 257;
unsigned int defaultbg = 256;
unsigned int defaultcs = 257;
unsigned int defaultrcs = 257;

/*
 * Colors used, when the specific fg == defaultfg. So in reverse mode this
 * will reverse too. Another logic would only make the simple feature too
 * complex.
 */
unsigned int defaultitalic = 7;
unsigned int defaultunderline = 7;
