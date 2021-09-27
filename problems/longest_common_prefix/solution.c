

char * longestCommonPrefix(char ** strs, int strsSize){
    size_t findMinimumLength(char ** strs, int strsSize);

    char * lcpr;
    size_t min_len;    /* the length of the shortest string in strs */

    /* if 0 or less strs, return the empty string */
    if (strsSize <= 0) {
        return "";
    } /* if (strsSize <= 0) */

    /* find the minimum length */
    min_len = findMinimumLength(strs, strsSize);

    /* create a string 1 larger for null terminator */
    /* fill it with 0s or null characters, using calloc */
    lcpr = calloc((min_len + 1), sizeof(*lcpr));

    /* for each character up to min_len */
    for (size_t iChar = 0; iChar < min_len; ++iChar) {
        /* for each string after strs[0] */
        for (int iStr = 1; iStr < strsSize; ++iStr) {
            /* on the first current character different
               from the corresponding on strs[0] */
            if (strs[iStr][iChar] != strs[0][iChar]) {
                /* return the lowest common prefix */
                /* also, it's already null terminated
                   since we never reached the (min_len)th character */
                return lcpr;
            } /* if (strs[iStr][iChar] != strs[0][iChar]) */
        } /* for (int iStr = 1; iStr < strsSize; ++iStr) */
        /* if this character clears add it to lowest common prefix */
        lcpr[iChar] = strs[0][iChar];
    } /* for (size_t iChar = 0; iChar < min_len; ++iChar) */

    /* null terminate (one of the shortest strings was the least common prefix) */
    lcpr[min_len] = 0;

    return lcpr;
}

size_t findMinimumLength(char ** strs, int strsSize) {

    size_t curr_len;   /* the length of the current string */
    size_t min_len;    /* the length of the shortest string in strs */

    /* use the MAX_VALUE for min_len */
    min_len = (size_t)(-1);

    for (int k = 0; k < strsSize; ++k) {
        /* get length of kth string */
        curr_len = strlen(strs[k]);
        /* if less than min_len, update min_len*/
        if (curr_len < min_len) {
            min_len = curr_len;
        } /* if (curr_len < min_len) */
    } /* for (int k = 0; k < strsSize; ++k) */

    return min_len;
}