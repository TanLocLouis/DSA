for (int i = 0; i < nums.size(); ++i) {
    while (!monoStack.empty() && nums[i] > nums[monoStack.top()]) {
        result[monoStack.top()] = nums[i];
        monoStack.pop();
    }
    monoStack.push(i);
}