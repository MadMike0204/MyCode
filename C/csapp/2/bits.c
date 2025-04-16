/* 
 * CS:APP Data Lab 
 * 
 * <kongtianqi 2023150206>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  int x_or_y = ~(~x & ~y);
  int not_x_or_y = ~(x & y);
  return x_or_y & not_x_or_y;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 1 << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  int check1 = !((x + 1) ^ (~x)); 
  int check2 = !!(x + 1); 
  return check1 & check2;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int byte_A = (1 << 3) + (1 << 1); 
  int byte_AA = (byte_A << 4) + byte_A; 
  int word_AAAA = byte_AA | (byte_AA << 8);
  int odd_mask = word_AAAA | (word_AAAA << 16);
  return !((x & odd_mask) ^ odd_mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int lower_bound = 0x30;
  int upper_bound = 0x39;
  int sign_bit_mask = 1 << 31;
  int diff_lower = x + (~lower_bound + 1);
  int check_lower = !(diff_lower >> 31); 
  int diff_upper = upper_bound + (~x + 1);
  int check_upper = !(diff_upper >> 31);
  return check_lower & check_upper;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int mask_z = ~(!x) + 1;
  int mask_y = ~mask_z;
  int result = (mask_y & y) | (mask_z & z);
  return result;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int sx = x >> 31;     
  int sy = y >> 31;    
  int case1_mask = (sx ^ sy) & sx; 
  int diff = y + (~x + 1); 
  int sdiff = diff >> 31;  
  int case2_mask = (~(sx ^ sy)) & (~sdiff); 
  int result_mask = case1_mask | case2_mask; 
  return !!result_mask; 
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int neg_x = ~x + 1;
  int or_result = x | neg_x;
  int sign_bit = or_result >> 31;
  return sign_bit + 1; 
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int sign_mask, original_val, val;
  int b16, b8, b4, b2, b1;
  int shift16, shift8, shift4, shift2; 
  int pos; 
  int is_val_zero, adjustment;
  int intermediate_bang; 

  sign_mask = x >> 31;
  original_val = x ^ sign_mask;  
  val = original_val;         
  intermediate_bang = (((val >> 16) | (~(val >> 16) + 1)) >> 31) + 1; 
  b16 = ((intermediate_bang | (~intermediate_bang + 1)) >> 31) + 1; 

  shift16 = b16 << 4;
  pos = shift16;                  
  val = val >> shift16;         

  intermediate_bang = (((val >> 8) | (~(val >> 8) + 1)) >> 31) + 1;  
  b8 = ((intermediate_bang | (~intermediate_bang + 1)) >> 31) + 1; 
 
  shift8 = b8 << 3; 
  pos = pos + shift8;            
  val = val >> shift8;         
  intermediate_bang = (((val >> 4) | (~(val >> 4) + 1)) >> 31) + 1;  
  b4 = ((intermediate_bang | (~intermediate_bang + 1)) >> 31) + 1; 
  shift4 = b4 << 2;        
  pos = pos + shift4;     
  val = val >> shift4;    

  intermediate_bang = (((val >> 2) | (~(val >> 2) + 1)) >> 31) + 1; 
  b2 = ((intermediate_bang | (~intermediate_bang + 1)) >> 31) + 1; 

  shift2 = b2 << 1;        
  pos = pos + shift2;         
  val = val >> shift2;           
  intermediate_bang = (((val >> 1) | (~(val >> 1) + 1)) >> 31) + 1; 
  b1 = ((intermediate_bang | (~intermediate_bang + 1)) >> 31) + 1; 
  pos = pos + b1; 
  is_val_zero = ((original_val | (~original_val + 1)) >> 31) + 1; 
  adjustment = ~is_val_zero + 1;
  return pos + 2 + adjustment;    

}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  unsigned exp = (uf >> 23) & 0xFF; 
  unsigned sign = uf & 0x80000000; 

  if (exp == 0xFF) { 
    return uf; 
  }

  if (exp == 0x00) { 
    return sign | (uf << 1); 
  }
  if (exp == 0xFE) { 
    return sign | 0x7F800000; 
  }
  return uf + 0x00800000; 
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {

  unsigned Tmin_inter1 = 0x80 << 8; 
  unsigned Tmin_inter2 = Tmin_inter1 << 8;
  unsigned Tmin = Tmin_inter2 << 8; 

  int bias = 0x7F;
  unsigned implicit_1_inter1 = 1 << 8;
  unsigned implicit_1_inter2 = implicit_1_inter1 << 8;
  unsigned implicit_1 = implicit_1_inter2 << 7;

  unsigned frac_mask = implicit_1 - 1; 
  unsigned sign = uf >> 31;          
  unsigned exp = (uf >> 23) & 0xFF; 
  unsigned frac = uf & frac_mask;   
  if (exp == 0xFF) { 
    return Tmin;
  }
  if (exp == 0) { 
    return 0;
  }

  int real_exp = exp - bias;

  if (real_exp < 0) {
    return 0;
  }

  if (real_exp >= 31) {
    return Tmin;
  }

  unsigned magnitude;
  unsigned significand = implicit_1 | frac; 
  if (real_exp < 23) {
    magnitude = significand >> (23 - real_exp);
  } else {
    magnitude = significand << (real_exp - 23);
  }

  if (sign) { 
    return ~magnitude + 1;
  } else { 
    return magnitude;
  }
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  int bias = 127; 

  unsigned pos_inf_inter1 = 0xFF << 8; 
  unsigned pos_inf_inter2 = pos_inf_inter1 << 8;
  unsigned pos_inf = pos_inf_inter2 << 7;
  if (x > 127) {
      return pos_inf;
  }
  if (x >= -126) {
      unsigned exp_val = x + bias;
      unsigned result_inter1 = exp_val << 8;
      unsigned result_inter2 = result_inter1 << 8;
      return result_inter2 << 7; 
  }
  if (x >= -149) {

      unsigned shift_amount = x + 149;
      return 1 << shift_amount; 
  }

  return 0; 
}
