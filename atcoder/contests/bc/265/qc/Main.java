package qc;

import java.util.Scanner;

public class Main {

   public static void main(String[] args) {
       int h,w;
       Scanner sc = new Scanner(System.in);
       h = sc.nextInt();
       w = sc.nextInt();

       char[][] g = new char[h][w];
       for (int i = 0;i<h;i++) {
           for (int j = 0;j<w;j++) {
              g[i][j] = sc.next().trim().charAt(0);
           }
       }
   }
}
