int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Traverse from last digit to first
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;        // Increase last non-9 digit
            *returnSize = digitsSize;
            return digits;      // No need to expand size
        }
        digits[i] = 0;           // If digit is 9 → becomes 0
    }

    // If we reach here, all digits were 9
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    result[0] = 1;                     // Example: 999 → 1000
    for (int i = 1; i <= digitsSize; i++)
        result[i] = 0;

    *returnSize = digitsSize + 1;
    return result;
}
