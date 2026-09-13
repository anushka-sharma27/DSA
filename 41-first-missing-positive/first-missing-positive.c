int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {

        while (nums[i] >= 1 &&
               nums[i] <= numsSize &&
               nums[nums[i] - 1] != nums[i]) {

            int temp = nums[i];
            nums[i] = nums[temp - 1];
            nums[temp - 1] = temp;
        }
    }

    // Find the first index where the number is incorrect
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    // If all 1...n are present
    return numsSize + 1;
}
