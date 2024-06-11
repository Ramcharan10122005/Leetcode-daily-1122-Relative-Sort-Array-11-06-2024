/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* a1, int s1, int* a2, int s2, int* r) {
    int* ans = malloc(s1 * sizeof(int));
    *r = s1;
    int max = a1[0];
    for (int i = 1; i < s1; i++) {
        max = fmax(max, a1[i]);
    }
    int* freq = calloc(max + 1, sizeof(int));
    for (int i = 0; i < s1; i++) {
        freq[a1[i]]++;
    }
    int index = 0;
    for (int i = 0; i < s2; i++) {
        int num = a2[i];
        while (freq[num]) {
            ans[index] = num;
            index++;
            freq[num]--;
        }
    }
    for (int i = 0; i < max + 1; i++) {
        int num = freq[i];
        while (num) {
            ans[index] = i;
            num--;
            index++;
        }
    }
    return ans;
}
