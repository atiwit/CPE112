package m2_w4;

public class Main {
    public static void main(String[] args) {
        UndirectedGraph a = new UndirectedGraph(false);
        a.addNode("a");
        a.addNode("b");
        a.addNode("c");
        a.addNode("d");
        a.addEdge("a", "b");
        a.addEdge("b", "c");
        a.addEdge("c", "d");

        int out = a.getOutDegree("a");
        System.err.println("Out degree of A = " + out);
    }
}
