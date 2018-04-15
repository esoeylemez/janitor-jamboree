/* input.h -*-c-*-
 * Input handler.
 *
 * "THE BEER-WARE LICENCE" (Revision 42):
 * See the file LICENSE.md for details */

#ifndef INPUT_h
#define INPUT_h

#include <stdlib.h>
#include <SDL/SDL.h>

struct inputData {
    uint8_t *state;
    uint8_t quit;
};

typedef struct inputData input;

input *inputInit();
void inputGetKeys(input *controls);

#endif
