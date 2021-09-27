using namespace std;

class Solution {
    enum { N_SYMBOLS = 13 };
    const array<string,N_SYMBOLS> SYMBOLS = {
        "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
    };
    const array<int,N_SYMBOLS> VALUES = {
        1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
    };
public:
    int romanToInt(string s) {
        int accumulator = 0;    /* sum of the symbols' values so far */

        string currSymbol;  /* the current symbol from the symbols array */
        int currlen;        /* length of the current symbol */

        /* loop through the length of the string
         * increment ichar to skip invalid values
         */
        for (size_t ichar = 0, slen = s.length(); ichar < slen; ++ichar) {
            /* loop through the array of symbols */
            for (size_t iSymbol = 0; iSymbol < N_SYMBOLS; ++iSymbol) {
                /* get the current symbol and its length */
                currSymbol = SYMBOLS[iSymbol];
                currlen = currSymbol.length();
                /* if the remainder of the string is at least as long as the symbol */
                if ((slen - ichar >= currlen)
                        /* and the symbol equals the next characters of its length */
                        && (s.compare(ichar, currlen, currSymbol) == 0))
                {
                    /* add the corresponding value to the accumulator */
                    accumulator += VALUES[iSymbol];
                    /* skip the length of the symbol (account for the loop's +1 */
                    ichar += (currlen - 1);
                } /* if ((slen - ichar >= currlen)
                        && (s.compare(ichar, currlen, currSymbol) == 0))
                   */
            } /* for (size_t iSymbol = 0; iSymbol < N_SYMBOLS; ++iSymbol) */
        } /* for (size_t ichar = 0, slen = s.length(); ichar < slen; ++ichar) */
        return accumulator;
    }
};
