package m3_week1;

public class GraphM extends AdjM {
    int numVertices;
    boolean isDirected;

    public GraphM(int n, boolean isDirected) {
        super(n);
        this.numVertices = n;
        this.isDirected = isDirected;
    }

    public void addEdge(int i, int j, int weight) {
        this.matrix[i][j] = weight;
        if (isDirected) {
            this.matrix[j][i] = weight;
        }
    }

    public int getWeight(int i, int j) {
        return this.matrix[i][j];
    }
}
