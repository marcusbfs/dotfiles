const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#0f110e", /* black   */
  [1] = "#265161", /* red     */
  [2] = "#B66011", /* green   */
  [3] = "#7C817C", /* yellow  */
  [4] = "#BE8F5C", /* blue    */
  [5] = "#206A89", /* magenta */
  [6] = "#4C7A8D", /* cyan    */
  [7] = "#abbbc1", /* white   */

  /* 8 bright colors */
  [8]  = "#778287",  /* black   */
  [9]  = "#265161",  /* red     */
  [10] = "#B66011", /* green   */
  [11] = "#7C817C", /* yellow  */
  [12] = "#BE8F5C", /* blue    */
  [13] = "#206A89", /* magenta */
  [14] = "#4C7A8D", /* cyan    */
  [15] = "#abbbc1", /* white   */

  /* special colors */
  [256] = "#0f110e", /* background */
  [257] = "#abbbc1", /* foreground */
  [258] = "#abbbc1",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
unsigned int defaultrcs = 257;
