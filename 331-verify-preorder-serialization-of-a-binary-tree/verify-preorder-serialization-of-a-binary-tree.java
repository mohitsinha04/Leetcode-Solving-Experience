public class Solution {
	public boolean isValidSerialization(String preorder) {
		String[] tree = preorder.split(",");
		return valid(tree, 0) == tree.length-1;
	}

	private int valid(String[] tree, int current) {
		if(current >= tree.length) return -1;
		if("#".equals(tree[current])) return current;

		// left
		int next = valid(tree, current + 1);
		if(next == -1) return -1;

		// right
		next = valid(tree, next + 1);
		return next == -1 ? -1 : next;
	}
}

// (2*idx) / 2; -> 0
// (2*idx+1) / 2 -> 1;

// 9 -? -
//     3 -? -> 1 -?
//         4 -? -> first go left, then check right
//             # -? (return)




// root

// bool isleft = isValidSerialization(root->left);
// bool isRight = isValidSerialization(root->right);