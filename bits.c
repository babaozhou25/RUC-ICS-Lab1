/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    int not_x = ~x;
    int not_y = ~y;
    int x_and_y = ~(not_x | not_y);
    int result = x_and_y;
    return result;
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    int not_x_and_y = ~(x & y);
    int not_not_x_and_not_y = ~(~x & ~y);
    int x_xor_y = not_x_and_y & not_not_x_and_not_y;
    int result = x_xor_y;
    return result;
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    int sign_x = x >> 31;
    int sign_y = y >> 31;
    int is_same_sign = !(sign_x ^ sign_y);
    if(!(x ^ 0))
    {
        if(y ^ 0)
        {
            is_same_sign = 0;
        }
    }
    else
    {
        if(!(y ^ 0))
        {
            is_same_sign = 0;
        }
    }
    int result = is_same_sign;
    return result;
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int result_1 = ((v >> 16) > 0) << 4;
    v = v >> result_1;
    int result_2 = ((v >> 8) > 0) << 3;
    v = v >> result_2;
    int result_3 = ((v >> 4) > 0) << 2;
    v = v >> result_3;
    int result_4 = ((v >> 2) > 0) << 1;
    v = v >> result_4;
    int result_5 = (v >> 1) > 0;
    v = v >> (result_5);
    int result = result_1 | result_2 | result_3 | result_4 | result_5;
    return result;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
    int move_n = (n << 3); 
    int move_m = (m << 3);
    int mask_n = 0xFF << move_n;
    int mask_m = 0xFF << move_m;
    int swap_n = mask_n & x;
    int swap_m = mask_m & x;
    x = x ^ swap_n;
    x = x ^ swap_m;
    swap_n = ((swap_n >> move_n) & 0xFF) << move_m;
    swap_m = ((swap_m >> move_m) & 0xFF) << move_n;
    x = x | swap_n;
    x = x | swap_m;
    int result = x;
    return result;
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) {
    unsigned result = 0;
    unsigned i = 32;
    while(i)
    {
        result = (result << 1) | (v & 0x1);
        v = v >> 1;
        i = i - 1;
    }
    return result;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    int mask = ~(((1 << 31) >> n) << 1);  //注意对于边界 n = 0 的判断和处理，避免出现位移 32 / -1 的情况
    x = x >> n;
    x = x & mask;
    int result = x;
    return result;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {
    int judge = 0;
    judge = !( ((x >> 16)& 0xFFFF) ^ 0xFFFF);
    int result_1 = judge << 4;
    x = x << result_1;
    judge = !( ((x >> 24)& 0xFF) ^ 0xFF);
    int result_2 = judge << 3;
    x = x << result_2;
    judge = !( ((x >> 28)& 0xF) ^ 0xF);
    int result_3 = judge << 2;
    x = x << result_3;
    judge = !( ((x >> 30)& 0x3) ^ 0x3);
    int result_4 = judge << 1;
    x = x << result_4;
    judge = (x >> 31) & 0x1;
    int result_5 = judge;
    x = x << result_5;
    judge = (x >> 31) & 0x1;
    int result_6 = judge;
    int result = result_1 + result_2 + result_3 + result_4 + result_5 + result_6;
    return result;
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    unsigned result = 0;
    if(x == 0)
    {
        result = 0;
        //log_exp = 0, 右移找不到首个1
    }
    else if(x == 0x80000000)
    {
        result = 0xCF000000;
        //absolute_value 超INT区间
    }
    else
    {    
        int sign = x & (1 << 31);
        int absolute_value = x;
        if(sign)
        {
            absolute_value = -x;
        }
        int log_exp = 31;
        while(!(absolute_value >> log_exp))
        {
            log_exp = log_exp - 1;
        }
        int frac = 0;
        if(log_exp <= 23)
        {
            frac = (absolute_value << (23 - log_exp)) & 0x7FFFFF;
        }
        else
        {
            int shift = log_exp - 24;
            frac = (absolute_value >> (shift + 1)) & 0x7FFFFF;
            int error_1 = (absolute_value >> (shift) & 0x1);
            int mask_low = (1 << (shift)) - 1;
            int error_2 = absolute_value & mask_low; //取出低位误差
            if(error_1)
            {
                if(error_2 | (frac & 0x1)) // 四舍六入五成双：error_2 为 0 时判断奇偶性，非0时直接进位
                {
                    frac = frac + 1;
                    if(frac >> 23)
                    {
                        //此时frac进位后变为0x800000
                        frac = 0;
                        log_exp = log_exp + 1;
                        
                    }
                }
            }
        }
        result = sign + ((log_exp + 127) << 23) + frac; 
    }
    return result;
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned sign = uf & (1 << 31);
    unsigned exp = (uf >> 23) & 0xFF;
    unsigned frac = uf & 0x7FFFFF;
    unsigned result = uf;
    if(exp == 0xFF) 
    {
        result = uf;
    }
    else if(!exp)
    {
        result = sign + (frac << 1);
    }
    else
    {    
        exp = exp + 1;
        if(exp == 0xFF)
        {
            result = sign + 0x7F800000; // 浮点数向无穷溢出
        }
        else
        {
            result = sign + (exp << 23) + frac;
        }
    }
    return result;
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    int sign = uf2 & (1 << 31);
    int exp = (uf2 >> 20) & 0x7FF;
    int result = 0;
    if(exp >= 0x7FF) // 没有等于号
    {
        result = 0x80000000; // NaN / inf
    }
    else if(exp < 1023)
    {
        result = 0; //下溢 
    }
    else
    {
        int e = exp -1023;
        if(e > 30) 
        {
            result = 0x80000000; // 溢出MAXINT
        }
        else
        {        
            int frac_high = uf2 & 0xFFFFF;
            int high = frac_high + (1 << 20);
            if(e > 20)
            {
                int low = uf1 >> (52 - e);
                result = (high << (e - 20)) + low;
            }
            else
            {
                result = high >> (20 - e);
            }
            if(sign)
            {
                result = -result;
            }
        }
    }
    return result;
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
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    unsigned result = 0;
    if(x > 127) 
    {
        result = 0x7F800000; // +inf
    }
    else if(x >= -126)
    {
        unsigned exp = x + 127;
        result = exp << 23;
    }
    else if(x >= -149)
    {
        result = 1 << (x + 149); // sign = 0, exp = 0x00, frac * 2^(-23) * 2^(-126) = x
    }
    return result;
}
