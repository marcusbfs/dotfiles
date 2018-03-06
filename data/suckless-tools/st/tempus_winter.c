/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#202427", /* black   */
  [1] = "#ca7162", /* red     */
  [2] = "#589584", /* green   */
  [3] = "#988b21", /* yellow  */
  [4] = "#2b92c8", /* blue    */
  [5] = "#b572b6", /* magenta */
  [6] = "#4f91b5", /* cyan    */
  [7] = "#888a8a", /* white   */

  /* 8 bright colors */
  [8]  = "#1b2431", /* black   */
  [9]  = "#c47818", /* red     */
  [10] = "#2c9a81", /* green   */
  [11] = "#a2864b", /* yellow  */
  [12] = "#6987d7", /* blue    */
  [13] = "#987dc2", /* magenta */
  [14] = "#1f96b0", /* cyan    */
  [15] = "#798ba5", /* white   */

  /* special colors */
  [256] = "#202427", /* background */
  [257] = "#798ba5", /* foreground */
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
