/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#373b40", /* black   */
  [1] = "#9d3a5c", /* red     */
  [2] = "#089568", /* green   */
  [3] = "#b05772", /* yellow  */
  [4] = "#646c9f", /* blue    */
  [5] = "#7c4871", /* magenta */
  [6] = "#219e92", /* cyan    */
  [7] = "#b3bece", /* white   */

  /* 8 bright colors */
  [8]  = "#3c4148", /* black   */
  [9]  = "#a54566", /* red     */
  [10] = "#0ca071", /* green   */
  [11] = "#bf6c85", /* yellow  */
  [12] = "#6973b1", /* blue    */
  [13] = "#8a507e", /* magenta */
  [14] = "#2cac9f", /* cyan    */
  [15] = "#c9d5e8", /* white   */

  /* special colors */
  [256] = "#1f2123", /* background */
  [257] = "#d9d1e8", /* foreground */
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
