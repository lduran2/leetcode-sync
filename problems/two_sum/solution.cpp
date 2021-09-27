class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2, -1);  /* the result of the search */
        /* the indices of the first occurence of each number + 1 each */
        map<int,int> indexP1s;

        /* the current element */
        int curr;
        /* the index of the complementary element */
        int i_complement;

        /* search for a previous value first, in case of duplicates */

        /* loop through the numbers */
        for (int k = 0, len = nums.size(); k < len; ++k) {
            /* get the current element */
            curr = nums[k];

            /* get the index of the complementary element (target - current) */
            i_complement = (indexP1s[target - curr] - 1);
            /* check if it exists */
            if (i_complement >= 0) {
                /* if so, build the result */
                result[0] = i_complement;   /* earlier complement first */
                result[1] = k;              /* then new k index */
                /* return the result */
                return result;
            } /* if (i_complement >= 0) */

            /* put the index + 1 of the element into the hash table */
            /* overwrites previous values, which is okay.
               the solution doesn't care about remembering first instances */
            indexP1s[curr] = (k + 1);
        } /* for (int k = 0, len = nums.size(); k < len; ++k) */

        /* return */
        return result;
    }
};