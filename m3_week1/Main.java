package m3_week1;

public class Main {
    public static void main(String[] args) {
        GraphM noDirect = new GraphM(3, false);
        noDirect.addEdge(0, 1, 2);
        noDirect.addEdge(0, 2, 3);
        noDirect.addEdge(1, 2, 1);

        GraphM Directed = new GraphM(3, true);
        Directed.addEdge(0, 1, 2);
        Directed.addEdge(0, 2, 3);
        Directed.addEdge(1, 2, 1);
        Directed.addEdge(2, 0, 3);

        MyAlgorithm algorithm = new MyAlgorithm();
        System.out.println("Undirected Graph from node 0 (DFS) is " + algorithm.dfs(noDirect, 0));
        System.out.println("Directed Graph from node 1 (DFS) is " + algorithm.dfs(Directed, 1));

        GraphL noDirectL = new GraphL(false, 3, 0);
        noDirectL.addVertex(0);
        noDirectL.addVertex(1);
        noDirectL.addVertex(2);

        noDirectL.addEdge(0, 1);
        noDirectL.addEdge(0, 2);
        noDirectL.addEdge(1, 2);

        GraphL DirectL = new GraphL(true, 3, 0);
        DirectL.addVertex(0);
        DirectL.addVertex(1);
        DirectL.addVertex(2);

        DirectL.addEdge(0, 1);
        DirectL.addEdge(0, 2);
        DirectL.addEdge(1, 2);
        DirectL.addEdge(1, 0);

        System.out.println("Undirected Graph from node 0 (BFS) is " + algorithm.bfs(noDirectL, 0));
        System.out.println("Directed Graph from node 1 (BFS) is " + algorithm.bfs(DirectL, 1));

    }
}
