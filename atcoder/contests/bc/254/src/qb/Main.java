package qb;

import java.util.Scanner;

public class Main {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        long[][] res = solve(n);
        for (int i = 0; i < res[0].length; i++) {
            for (int j = 0; j <=i; j++) {
                System.out.print(res[i][j]);
                System.out.print(" ");
            }
            System.out.println();
        }
    }

    public static long[][] solve(int n) {

        long[][] m = new long[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {

                if (j == 0 || j == i) {
                    m[i][j] = 1L;
                } else {
                    m[i][j] = m[i - 1][j - 1] + m[i - 1][j];
                }
            }
        }
        return m;
    }
}
