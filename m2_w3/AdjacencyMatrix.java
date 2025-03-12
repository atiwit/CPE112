package m2_w3;

public class AdjacencyMatrix {
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

    public static void main(String[] args) {

    }
}
