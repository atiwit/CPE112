package m3_week1;

public abstract class AdjM {
    protected int[][] matrix;

    public AdjM(int n) {
        this.matrix = new int[n][n];
    }

    // abstract = just define that have this fn (can implements)
    public abstract void addEdge(int i, int j, int weight);

    public abstract int getWeight(int i, int j);
}
