// Translate of the Python function `getMinConnectionCost` into JavaScript
function getMinConnectionCost(warehouseCapacity, additionalHubs) {
	const n = warehouseCapacity.length;
	const results = [];

	// --- Precomputation: Calculate Prefix Sums ---
	const prefixSum = new Array(n + 1).fill(0);
	for (let i = 0; i < n; i++) {
		prefixSum[i + 1] = prefixSum[i] + warehouseCapacity[i];
	}

	for (const query of additionalHubs) {
		const hubA = query[0]; // 1-based index
		const hubB = query[1]; // 1-based index

		let currentTotalCost = 0;

		// 1. Warehouses 1 to hubA-1: Connect to hubA
		if (hubA > 1) {
			const count1 = hubA - 1;
			const targetCapacity1 = warehouseCapacity[hubA - 1];
			const sumOwnCapacities1 = prefixSum[hubA - 1];
			const cost1 = count1 * targetCapacity1 - sumOwnCapacities1;
			currentTotalCost += cost1;
		}

		// 2. Warehouses hubA+1 to hubB-1: Connect to hubB
		if (hubB - hubA > 1) {
			const count2 = hubB - hubA - 1;
			const targetCapacity2 = warehouseCapacity[hubB - 1];
			const sumOwnCapacities2 = prefixSum[hubB - 1] - prefixSum[hubA];
			const cost2 = count2 * targetCapacity2 - sumOwnCapacities2;
			currentTotalCost += cost2;
		}

		// 3. Warehouses hubB+1 to n: Connect to last hub at position n
		if (hubB < n) {
			const count3 = n - hubB;
			const targetCapacity3 = warehouseCapacity[n - 1];
			const sumOwnCapacities3 = prefixSum[n] - prefixSum[hubB];
			const cost3 = count3 * targetCapacity3 - sumOwnCapacities3;
			currentTotalCost += cost3;
		}

		results.push(currentTotalCost);
	}

	return results;
}

// Example usage
const warehouseCapacity = [3, 6, 10, 15, 20];
const additionalHubs = [
	[1, 3],
	[2, 4],
];
console.log(getMinConnectionCost(warehouseCapacity, additionalHubs));
