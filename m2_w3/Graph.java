package m2_w3;

public class Graph {
    public static void main(String[] args) {
        AdjacencyMatrix g = new UndirectedGraph(4);
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(1, 3);
        System.out.println(g);
        System.out.println("An edge between vertice 0 adn 1 : " + g.hasEdge(0, 1));
        g.removeEdge(1, 2);
        System.out.println(g);

        g = new UndirectedGraph(5);
        g.addEdge(3, 4);
        System.out.println(g);

        WeightedGraph g2 = new WeightedGraph(5);
        g2.addEdge(0, 1);
        g2.addEdge(0, 3, 5);
        System.out.println(g2);
    }
}

class AdjacencyMatrix {
    private int[][] matrix;
    private int numV;

    public AdjacencyMatrix(int numV) {
        this.numV = numV;
        matrix = new int[numV][numV];
    }

    public void addEdge(int i, int j) { // add e (i j)
        matrix[i][j] = 1;
        matrix[j][i] = 1;
    }

    public void removeEdge(int i, int j) { // re ove e (i j)
        matrix[i][j] = 0;
        matrix[j][i] = 0;
    }

    public boolean hasEdge(int i, int j) {
        return matrix[i][j] != 0;
    }

    public String toString() {
        StringBuffer buf = new StringBuffer("");
        for (int i = 0; i < numV; i++) {
            for (int j = 0; j < i; j++) {
                buf.append(matrix[i][j] + " ");
            }
            buf.append("\n");
        }
        return buf + "";
    }
}
