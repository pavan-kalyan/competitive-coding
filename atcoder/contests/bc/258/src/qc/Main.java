package qc;

import java.util.Scanner;

public class Main {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        boolean res = isSortable(a, k);
        if (res) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    public static boolean isSortable(int[] a, int k) {

        //best attempt swap first (n-k) elements
//        for (int i = 0; i < a.length - k; i++) {
//            if (a[i] > a[i + k]) {
//                int t = a[i+ k];
//                a[i + k] = a[i];
//                a[i] = t;
//            }
//        }
        int counter = 0;
        while (counter < k) {
            for (int i = a.length - k - 1; i >= 0; i--) {
                if (a[i] > a[i + k]) {
                    int t = a[i + k];
                    a[i + k] = a[i];
                    a[i] = t;
                }
            }
            counter++;
        }
        return isSorted(a);
    }

    public static boolean isSorted(int[] a) {
        for (int i = 0; i < a.length - 1; i++) {
            if (a[i] > a[i + 1]) {
                return false;
            }
        }
        return true;
    }
}
