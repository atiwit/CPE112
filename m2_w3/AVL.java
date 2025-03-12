package m2_w3;

import java.util.Scanner;

public class AVL {
    Node root;

    Node rightRotate(Node oldRoot) {
        Node newRoot = oldRoot.left;
        Node T2 = newRoot.right;
        newRoot.right = oldRoot;
        oldRoot.left = T2;

        // update old&new root height
        oldRoot.height = max(height(oldRoot.left), height(oldRoot.right)) + 1;
        newRoot.height = max(height(newRoot.left), height(newRoot.right)) + 1;

        return newRoot;
    }

    Node leftRotate(Node oldRoot) {
        Node newRoot = oldRoot.right;
        Node T2 = newRoot.left;
        newRoot.left = oldRoot;
        oldRoot.right = T2;

        // update old&new root height
        oldRoot.height = max(height(oldRoot.left), height(oldRoot.right)) + 1;
        newRoot.height = max(height(newRoot.left), height(newRoot.right)) + 1;

        return newRoot;
    }

    int height(Node node) {
        if (node == null) {
            return 0;
        }
        return node.height;
    }

    int max(int a, int b) {
        return a > b ? a : b; // Math.max(a,b)
    }

    int getBalanceFactor(Node node) {
        if (node == null) {
            return 0;
        }
        return height(node.left) - height(node.right);
    }

    Node insertNode(Node node, int key) {
        if (node == null) {
            return new Node(key);
        }
        if (key < node.key) {
            node.left = insertNode(node.left, key);
        } else if (key > node.key) {
            node.right = insertNode(node.right, key);
            // node.key = root
        } else {
            return node;
        }

        node.height = 1 + max(height(node.left), height(node.right));
        int BalanceFactor = getBalanceFactor(node);
        // LL Rotation, Rotate right
        if (BalanceFactor > 1 && key < node.left.key) {
            return rightRotate(node);
        }
        // RR Rotation, rotate left
        if (BalanceFactor < -1 && key > node.right.key) {
            return leftRotate(node);
        }
        // RL, Rotate right then left
        if (BalanceFactor < -1 && key < node.right.key) {
            node.right = rightRotate(node.right);
            return leftRotate(node);
        }
        // LR, Rotate Left then rotate right
        if (BalanceFactor > 1 && key > node.left.key) {
            node.left = leftRotate(node.left);
            return rightRotate(node);
        }

        return node;
    }

    private void preorder(Node root) {
        if (root != null) {
            System.out.printf("%d ", root.key);
            preorder(root.left);
            preorder(root.right);
        }
    }

    public void preorder() {
        preorder(this.root);
    }

    private void postorder(Node root) {
        if (root != null) {
            postorder(root.left);
            postorder(root.right);
            System.out.printf("%d ", root.key);
        }
    }

    public void postorder() {
        postorder(this.root);
    }

    private void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.printf("%d ", root.key);
            inorder(root.right);
        }
    }

    public void inorder() {
        inorder(this.root);
    }

    public static void main(String[] args) {
        AVL tree = new AVL();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of nodes : ");
        int n = sc.nextInt();
        System.out.println("Enter elements: ");
        for (int i = 0; i < n; i++) {
            int input = sc.nextInt();
            tree.root = tree.insertNode(tree.root, input);
        }
        sc.close();
        System.out.println("Preorder : ");
        tree.preorder(tree.root);
        System.out.println("\nInorder : ");
        tree.inorder(tree.root);
        System.out.println("\nPostOrder : ");
        tree.postorder(tree.root);

    }
}

class Node {
    int key, height;
    Node left;
    Node right;

    Node(int val) {
        key = val;
        height = 1;
    }
}
