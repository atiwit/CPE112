package m3_week1;

import java.util.ArrayList;
import java.util.List;

public class GraphL extends AdjList {
    int numVertices;
    int numEdges;
    boolean isDirected;

    public GraphL(boolean isDirected, int numVertices, int numEdges) {
        super();
        this.isDirected = isDirected;
        this.numVertices = numVertices;
        this.numEdges = numEdges;
    }

    public void addVertex(int ver) {
        this.adjacencyList.put(ver, new ArrayList<>());
    }

    public void addEdge(int src, int dest) {
        this.adjacencyList.get(src).add(dest);
        if (this.isDirected == false) {
            this.adjacencyList.get(dest).add(src);
        }
    }
}
