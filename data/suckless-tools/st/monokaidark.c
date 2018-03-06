/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#272822", /* black   */
  [1] = "#f92672", /* red     */
  [2] = "#a6e22e", /* green   */
  [3] = "#f4bf75", /* yellow  */
  [4] = "#66d9ef", /* blue    */
  [5] = "#ae81ff", /* magenta */
  [6] = "#a1efe4", /* cyan    */
  [7] = "#f8f8f2", /* white   */

  /* 8 bright colors */
  [8]  = "#75715e", /* black   */
  [9]  = "#f92672", /* red     */
  [10] = "#a6e22e", /* green   */
  [11] = "#f4bf75", /* yellow  */
  [12] = "#66d9ef", /* blue    */
  [13] = "#ae81ff", /* magenta */
  [14] = "#a1efe4", /* cyan    */
  [15] = "#f9f8f5", /* white   */

  /* special colors */
  [256] = "#272822", /* background */
  [257] = "#f8f8f2", /* foreground */
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
