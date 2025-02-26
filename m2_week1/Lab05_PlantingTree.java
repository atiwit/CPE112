package m2_week1;
import java.util.Scanner;

class Node {
    int data;
    String name;
    Node left;
    Node right;

    public Node(int data,String name) {
        this.data = data;
        this.name = name;
        this.left = null;
        this.right = null;
    }

    public boolean setChildNode(Node child, char direction) {
        if(direction == 'L'){
            this.left = child;
            return true;
        }else if (direction == 'R'){
            this.right = child;
            return true;
        } else {
            return false;
        }
    }
}

class Tree {
    Node[] node;
    Node root;
    
    public Tree(int n){
        this.node = new Node[n]; //malloc(sizeof(Node) * n)
        this.root = null;
    }
    private Node searchByName(String name) {
        for(Node n : this.node){
            if(n.name.equals(name)) {
                return n;
            }
        }
        return null;
    }

    public boolean addEdge(String pName, String cName,char direction) {
        Node pNode = searchByName(pName);
        Node cNode = searchByName(cName);

        if(pNode == null || cNode == null){
            return false;
        } else {
            pNode.setChildNode(cNode, direction);
            return true;
        }
    }
    public boolean setRoot(String rName){
        Node root = searchByName(rName);
        if(root == null) {
            return false;
        }else {
            this.root = root;
            return true;
        }
    }

    private void preorder(Node root) {
        if (root != null){
            System.out.printf("%s %d\n", root.name, root.data);
            preorder(root.left);
            preorder(root.right);
        }
    }

    public void preorder(){
        preorder(this.root);
    }

    private void postorder(Node root) {
        if (root != null){
            postorder(root.left);
            postorder(root.right);
            System.out.printf("%s %d\n", root.name, root.data);
        }
    }

    public void postorder() {
        postorder(this.root);
        System.out.println();
    }

    private void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.printf("%d ", root.data);
            inorder(root.right);
        }
    }

    public void inorder() {
        inorder(this.root);
        System.out.println();
    }
}

public class Lab05_PlantingTree {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of nodes
        int N = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

        // Create the tree
        Tree tree = new Tree(N);

        // Read node data
        for (int i = 0; i < N; i++) {
            String[] nodeData = scanner.nextLine().split(" ");
            String name = nodeData[0];
            int value = Integer.parseInt(nodeData[1]);
            tree.node[i] = new Node(value, name);
        }

        // Read edges
        for (int i = 0; i < N - 1; i++) {
            String[] edgeData = scanner.nextLine().split(" ");
            String parent = edgeData[0];
            String child = edgeData[1];
            char direction = edgeData[2].charAt(0);
            tree.addEdge(parent, child, direction);
        }

        // Read the root node
        String rootName = scanner.nextLine();
        tree.setRoot(rootName);

        // Perform traversals
        tree.preorder();

        tree.inorder();

        tree.postorder();

        scanner.close();
    }
}

