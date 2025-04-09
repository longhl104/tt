/*
Given an array of movie ratings, find the maximum number of indices i such that ratings[i] < ratings[i+1]
across all possible permutations of the ratings array.

Function Description
Complete the function getMaxIncrements in the editor below.
getMaxIncrements takes the following arguments:
int ratings[n]: the ratings of the movies

Returns
int: the maximum number of possible indices where the ratings can increase

Constraints
2 <= n <= 2 * 10^5
1 <= ratings[i] <= 2 * 10^5
*/

function getMaxIncrements(ratings) {
	const n = ratings.length;
	if (n <= 1) {
		return 0;
	}

	// Hint 1: Sorting the array will help to maximize the number of increasing pairs.
	ratings.sort((a, b) => a - b);

	let maxIncrements = 0;
	let l = 0;
	let r = 1;

	while (l < n && r < n) {
		if (ratings[l] < ratings[r]) {
			++maxIncrements;
			++l;
			++r;
		} else {
			++r;
		}
	}

	return maxIncrements;
}

// Example usage
const ratings1 = [2, 1, 3];
console.log(getMaxIncrements(ratings1)); // Output: 2

const ratings2 = [1, 2, 3, 4, 5];
console.log(getMaxIncrements(ratings2)); // output 4

const ratings4 = [1, 1, 1, 1, 2];
console.log(getMaxIncrements(ratings4)); //output 0

const ratings5 = [1, 1, 4, 4];
console.log(getMaxIncrements(ratings5)); //output 2
