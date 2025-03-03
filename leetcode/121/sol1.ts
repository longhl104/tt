const INF = 10e4 + 1;

function maxProfit(prices: number[]): number {
	const tree = new SegmentTree(prices);
	let res = 0;
	for (let i = 0; i < prices.length - 1; ++i) {
		const leftNode = tree.query(0, i);
		const rightNode = tree.query(i + 1, prices.length - 1);
		res = Math.max(res, rightNode.max - leftNode.min);
	}

	return res;
}

class SegmentTree {
	private nodes: NodeResult[];
	private n: number;

	constructor(arr: number[]) {
		this.n = arr.length;
		this.nodes = new Array(4 * this.n);
		this.build(arr, 0, 0, this.n - 1);
	}

	private build(arr: number[], nodeI: number, s: number, e: number) {
		if (s === e) {
			this.nodes[nodeI] = {
				min: arr[s],
				max: arr[s],
			};

			return;
		}

		const m = Math.floor((s + e) / 2);
		const leftI = 2 * nodeI + 1;
		const rightI = 2 * nodeI + 2;
		this.build(arr, leftI, s, m);
		this.build(arr, rightI, m + 1, e);

		this.nodes[nodeI] = {
			min: Math.min(this.nodes[leftI].min, this.nodes[rightI].min),
			max: Math.max(this.nodes[leftI].max, this.nodes[rightI].max),
		};
	}

	query(
		left: number,
		right: number,
		nodeI = 0,
		s = 0,
		e = this.n - 1
	): NodeResult {
		if (right < s || left > e) {
			return {
				min: INF,
				max: -INF,
			};
		}

		if (left <= s && e <= right) return this.nodes[nodeI];

		const m = Math.floor((s + e) / 2);
		const leftNode = this.query(left, right, 2 * nodeI + 1, s, m);
		const rightNode = this.query(left, right, 2 * nodeI + 2, m + 1, e);

		return {
			min: Math.min(leftNode.min, rightNode.min),
			max: Math.max(leftNode.max, rightNode.max),
		};
	}
}

interface NodeResult {
	min: number;
	max: number;
}
