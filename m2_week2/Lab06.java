package m2_week2;

public class Lab06 {
    public static void main(String[] args) {
        Tree a = new Tree();
        a.insertNode(6);
        a.insertNode(2);
        a.insertNode(3);
        a.insertNode(4);
        a.insertNode(5);

        // Traversal
        a.inorder();

    }
}

class Node {
    int val;
    Node left;
    Node right;

    public Node(int val) {
        this.val = val;
        this.left = this.right = null;
    }

}

class Tree {
    Node root;

    public Tree() {
        this.root = null;
    }

    public void insertNode(int val) {
        Node newNode = new Node(val);
        if (this.root == null) {
            this.root = newNode;
            return;
        }
        Node currNode = this.root;
        while (true) {
            if (val < currNode.val) {

                if (currNode.left == null) {
                    currNode.left = newNode;
                    return;
                } else {
                    currNode = currNode.left;
                }
            }

            if (val > currNode.val) {
                if (currNode.right == null) {
                    currNode.right = newNode;
                    return;
                } else {
                    currNode = currNode.right;
                }
            }
        }
    }

    private void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.printf("%d ", root.val);
            inorder(root.right);
        }
    }

    public void inorder() {
        inorder(this.root);
        System.out.println();
    }
}
