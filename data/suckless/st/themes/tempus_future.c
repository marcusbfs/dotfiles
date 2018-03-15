/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {
  /* 8 normal colors */
  /*[0] = "#18161d", [> black   <]*/
  [0] = "#79a8c3", /* cyan    */
  [1] = "#ff7780", /* red     */
  [2] = "#68b183", /* green   */
  [3] = "#bda014", /* yellow  */
  [4] = "#54a5ff", /* blue    */
  [5] = "#da89b2", /* magenta */
  [6] = "#79a8c3", /* cyan    */
  [7] = "#bd9b87", /* white   */

  /* 8 bright colors */
  /*[8]  = "#001b1a", [> black   <]*/
  [8] = "#1b8968", /*  altered for contrast  */
  [9]  = "#ef873d", /* red     */
  [10] = "#08b885", /* green   */
  [11] = "#d39710", /* yellow  */
  [12] = "#a294fe", /* blue    */
  [13] = "#ec7aca", /* magenta */
  [14] = "#4ab0b9", /* cyan    */
  [15] = "#a4a0ac", /* white   */

  /* special colors */
  [256] = "#18161d", /* background */
  [257] = "#a4a0ac", /* foreground */
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
