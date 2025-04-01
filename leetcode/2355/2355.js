const INF = 1e5 + 1;

function maximumBooks(books) {
	const n = books.length;
	const st = [[-INF, -1]];
	const f = Array(n).fill(0);
	for (let i = 0; i < n; i++) {
		while (books[i] - (i - st[st.length - 1][1]) <= st[st.length - 1][0]) {
			st.pop();
		}

		const j = st[st.length - 1][1];
		console.log(i, st);
		if (st.length > 1) {
			f[i] = f[j];
		}

		if (books[i] > i - j) {
			f[i] += ((i - j) * (2 * books[i] - (i - j - 1))) / 2;
		} else {
			f[i] += (books[i] * (books[i] + 1)) / 2;
		}

		st.push([books[i], i]);
	}

	console.log(f);
	return Math.max(...f);
}

// const books = [8, 5, 2, 7, 9];
const books = [8, 4, 0, 4, 3, 6, 8, 6];
