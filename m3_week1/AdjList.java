package m3_week1;

import java.util.*;

public abstract class AdjList {
    protected Map<Integer, List<Integer>> adjacencyList;

    public AdjList() {
        this.adjacencyList = new HashMap<>();
    }

    public abstract void addVertex(int ver);

    public abstract void addEdge(int src, int dest);

}
