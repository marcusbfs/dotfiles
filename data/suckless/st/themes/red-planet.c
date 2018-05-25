const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#0f141d", /* black   */
  [1] = "#5B535E", /* red     */
  [2] = "#9D5653", /* green   */
  [3] = "#C65252", /* yellow  */
  [4] = "#E59070", /* blue    */
  [5] = "#3D5F89", /* magenta */
  [6] = "#567094", /* cyan    */
  [7] = "#a4bcd4", /* white   */

  /* 8 bright colors */
  [8]  = "#728394",  /* black   */
  [9]  = "#5B535E",  /* red     */
  [10] = "#9D5653", /* green   */
  [11] = "#C65252", /* yellow  */
  [12] = "#E59070", /* blue    */
  [13] = "#3D5F89", /* magenta */
  [14] = "#567094", /* cyan    */
  [15] = "#a4bcd4", /* white   */

  /* special colors */
  [256] = "#0f141d", /* background */
  [257] = "#a4bcd4", /* foreground */
  [258] = "#a4bcd4",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
