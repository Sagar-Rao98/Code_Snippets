// Define your enumeration like this (in say numbers.h);
ENUM_BEGIN( Numbers )
    ENUM(ONE),
    ENUM(TWO),
    ENUM(FOUR)
ENUM_END( Numbers )

// The macros are defined in a more fundamental .h file (say defs.h);
#define ENUM_BEGIN(typ) enum typ {
#define ENUM(nam) nam
#define ENUM_END(typ) };

// Now in one and only one .c file, redefine the ENUM macros and reinclude
//  the numbers.h file to build a string table
#undef ENUM_BEGIN
#undef ENUM
#undef ENUM_END
#define ENUM_BEGIN(typ) const char * typ ## _name_table [] = {
#define ENUM(nam) #nam
#define ENUM_END(typ) };
#undef NUMBERS_H_INCLUDED   // whatever you need to do to enable reinclusion
#include "numbers.h"

// Now you can do exactly what you want to do, with no retyping, and for any
//  number of enumerated types defined with the ENUM macro family
//  Your code follows;
char num_str[10];
int process_numbers_str(Numbers num) {
  switch(num) {
    case ONE:
    case TWO:
    case THREE:
    {
      strcpy(num_str, Numbers_name_table[num]); // eg TWO -> "TWO"
    } break;
    default:
      return 0; //no match
  return 1;
}

// Sweet no ? After being frustrated by this for years, I finally came up
//  with this solution for my most recent project and plan to reuse the idea
//  forever
