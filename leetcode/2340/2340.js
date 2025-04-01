const INF = 1e5 + 1;

function minimumSwaps(nums) {
	// 1 <= nums.length <= 10^5
	// 1 <= nums[i] <= 10^5
	const n = nums.length;
	let max = [0, -1];
	for (let i = n - 1; i >= 0; --i) {
		if (nums[i] > max[0]) {
			max[0] = nums[i];
			max[1] = i;
		}
	}

	let min = [INF, -1];
	for (let i = 0; i < n; ++i) {
		if (nums[i] < min[0]) {
			min[0] = nums[i];
			min[1] = i;
		}
	}

	if (min[1] < max[1]) {
		return min[1] + (n - 1 - max[1]);
	}

	if (min[1] === max[1]) {
		return 0;
	}

	return min[1] - 1 + (n - 1 - max[1]);
}

// const nums = [3, 4, 5, 5, 3, 1];
// const nums = [9];
const nums = [4, 2, 3, 1, 5, 6, 11, 8, 9, 10, 7];

console.log(minimumSwaps(nums));
