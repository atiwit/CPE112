import java.util.Scanner;

public class Lab00 {
    static void myName(String name){
        System.out.print(name);
    }

    public static void main(String[] args){
        // int arr[] = {1,2,3,4,5};
        // int arr2[] = new int[5]; // in c = arr[5] Or malloc
        // String stds[] = new String[5];




        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        String name[] = new String[n];

        for(int i = 0; i < n; i++){
            name[i] = sc.nextLine();
        }
        for(int i = 0; i < n; i++){
            myName(name[i]);
        }

        sc.close();
    }
}