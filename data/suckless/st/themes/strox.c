const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#3e2534", /* black   */
  [1] = "#0E91AC", /* red     */
  [2] = "#6091AC", /* green   */
  [3] = "#12B0CD", /* yellow  */
  [4] = "#50C5DC", /* blue    */
  [5] = "#A693AC", /* magenta */
  [6] = "#A2B3CA", /* cyan    */
  [7] = "#c9e0e8", /* white   */

  /* 8 bright colors */
  [8]  = "#8c9ca2",  /* black   */
  [9]  = "#0E91AC",  /* red     */
  [10] = "#6091AC", /* green   */
  [11] = "#12B0CD", /* yellow  */
  [12] = "#50C5DC", /* blue    */
  [13] = "#A693AC", /* magenta */
  [14] = "#A2B3CA", /* cyan    */
  [15] = "#c9e0e8", /* white   */

  /* special colors */
  [256] = "#3e2534", /* background */
  [257] = "#c9e0e8", /* foreground */
  [258] = "#c9e0e8",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
