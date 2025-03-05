package m2_week2;
public class RefType {

    public static void main(String[] args) {
              int a = 10;
              int b = 10;

              System.out.println(a == b);
              //
              Node n1 = new Node(1);
              Node n2 = new Node(1);
              System.out.println(n1 == n2);

              //
              Node n3 = new Node(99);
              Node n4 = new Node(69);
            //assign n3 in n4 so n4 = 69
              n4 = n3;

            //n4.val == n3.val
              n4.val = 69;

              System.out.println(n4.val); //69
    }
}

class Node {
    int val;
    Node leftChild;
    Node rightChild;

    public Node(int val) {
        this.val = val;
        this.leftChild = this.rightChild = null;
    }

}


