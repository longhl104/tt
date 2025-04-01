class Node {
	constructor(data, color = "RED") {
		this.data = data;
		this.color = color;
		this.left = null;
		this.right = null;
		this.parent = null;
	}
}

class RedBlackTree {
	constructor() {
		this.NIL = new Node(null, "BLACK"); // Sentinel NIL node
		this.root = this.NIL;
	}

	insert(data) {
		let newNode = new Node(data);
		newNode.left = this.NIL;
		newNode.right = this.NIL;

		let parent = null;
		let current = this.root;

		while (current !== this.NIL) {
			parent = current;
			if (newNode.data < current.data) {
				current = current.left;
			} else {
				current = current.right;
			}
		}

		newNode.parent = parent;
		if (!parent) {
			this.root = newNode;
		} else if (newNode.data < parent.data) {
			parent.left = newNode;
		} else {
			parent.right = newNode;
		}

		newNode.color = "RED";
		this.fixInsert(newNode);
	}

	fixInsert(node) {
		while (node.parent && node.parent.color === "RED") {
			let parent = node.parent;
			let grandparent = parent.parent;

			if (parent === grandparent.left) {
				let uncle = grandparent.right;
				if (uncle.color === "RED") {
					// Case 1: Recoloring
					parent.color = "BLACK";
					uncle.color = "BLACK";
					grandparent.color = "RED";
					node = grandparent;
				} else {
					if (node === parent.right) {
						// Case 2: Left Rotation needed
						node = parent;
						this.leftRotate(node);
					}
					// Case 3: Right Rotation needed
					parent.color = "BLACK";
					grandparent.color = "RED";
					this.rightRotate(grandparent);
				}
			} else {
				let uncle = grandparent.left;
				if (uncle.color === "RED") {
					// Case 1: Recoloring
					parent.color = "BLACK";
					uncle.color = "BLACK";
					grandparent.color = "RED";
					node = grandparent;
				} else {
					if (node === parent.left) {
						// Case 2: Right Rotation needed
						node = parent;
						this.rightRotate(node);
					}
					// Case 3: Left Rotation needed
					parent.color = "BLACK";
					grandparent.color = "RED";
					this.leftRotate(grandparent);
				}
			}
		}
		this.root.color = "BLACK";
	}

	leftRotate(node) {
		let rightChild = node.right;
		node.right = rightChild.left;
		if (rightChild.left !== this.NIL) {
			rightChild.left.parent = node;
		}
		rightChild.parent = node.parent;
		if (!node.parent) {
			this.root = rightChild;
		} else if (node === node.parent.left) {
			node.parent.left = rightChild;
		} else {
			node.parent.right = rightChild;
		}
		rightChild.left = node;
		node.parent = rightChild;
	}

	rightRotate(node) {
		let leftChild = node.left;
		node.left = leftChild.right;
		if (leftChild.right !== this.NIL) {
			leftChild.right.parent = node;
		}
		leftChild.parent = node.parent;
		if (!node.parent) {
			this.root = leftChild;
		} else if (node === node.parent.right) {
			node.parent.right = leftChild;
		} else {
			node.parent.left = leftChild;
		}
		leftChild.right = node;
		node.parent = leftChild;
	}

	inOrderTraversal(node = this.root) {
		if (node !== this.NIL) {
			this.inOrderTraversal(node.left);
			console.log(node.data + " (" + node.color + ")");
			this.inOrderTraversal(node.right);
		}
	}
}

// Example Usage
let rbTree = new RedBlackTree();
console.log("--------");
rbTree.insert(10);
rbTree.inOrderTraversal();
console.log("--------");
rbTree.insert(20);
rbTree.inOrderTraversal();
console.log("--------");
rbTree.insert(30);
rbTree.inOrderTraversal();
console.log("--------");
rbTree.insert(15);
rbTree.inOrderTraversal();
console.log("--------");
rbTree.insert(25);
rbTree.inOrderTraversal();
console.log("--------");
rbTree.insert(5);
rbTree.inOrderTraversal();
