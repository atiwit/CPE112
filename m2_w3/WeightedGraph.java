package m2_w3;

public class WeightedGraph extends DirectedGraph {
    public WeightedGraph(int numV) {
        super(numV);
    }

    public void addEdge(int i, int j, int val) {// overload
        matrix[i][j] = val;
    }

}
