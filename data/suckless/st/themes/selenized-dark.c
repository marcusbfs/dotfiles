/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#184956", /* black   */
  [1] = "#fa5750", /* red     */
  [2] = "#75b938", /* green   */
  [3] = "#dbb32d", /* yellow  */
  [4] = "#4695f7", /* blue    */
  [5] = "#f275be", /* magenta */
  [6] = "#41c7b9", /* cyan    */
  [7] = "#72898f", /* white   */

  /* 8 bright colors */
  [8]  = "#2d5b69", /* black   */
  [9]  = "#ff665c", /* red     */
  [10] = "#84c747", /* green   */
  [11] = "#ebc13d", /* yellow  */
  [12] = "#58a3ff", /* blue    */
  [13] = "#ff84cd", /* magenta */
  [14] = "#53d6c7", /* cyan    */
  [15] = "#cad8d9", /* white   */

  /* special colors */
  [256] = "#103c48", /* background */
  [257] = "#adbcbc", /* foreground */
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
