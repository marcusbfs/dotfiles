/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#${col0}", /* black   */
  [1] = "#${col1}", /* red     */
  [2] = "#${col2}", /* green   */
  [3] = "#${col3}", /* yellow  */
  [4] = "#${col4}", /* blue    */
  [5] = "#${col5}", /* magenta */
  [6] = "#${col6}", /* cyan    */
  [7] = "#${col7}", /* white   */

  /* 8 bright colors */
  [8]  = "#${col8}", /* black   */
  [9]  = "#${col9}", /* red     */
  [10] = "#${col10}", /* green   */
  [11] = "#${col11}", /* yellow  */
  [12] = "#${col12}", /* blue    */
  [13] = "#${col13}", /* magenta */
  [14] = "#${col14}", /* cyan    */
  [15] = "#${col15}", /* white   */

  /* special colors */
  [256] = "#${colbg}", /* background */
  [257] = "#${colfg}", /* foreground */
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
