package Week2;
import java.util.Scanner;
class Lab01 {

    public static void main(String[] args) {
     int arr[] = new int[10]; //10 elements
     Scanner sc = new Scanner(System.in);//input
     int matrix[][] = new int[3][3]; //matrix 3x3
     
     for (int i = 0; i < 3;i++) {
        for(int j = 0; j <3;j++){
            matrix[i][j] = sc.nextInt();
        }
     }

     for (int  row[] : matrix) {
        for(int ele : row){
            System.out.printf("%d ", ele);
        }
        System.out.println("\n");
     }
     sc.close();
    }
   
}