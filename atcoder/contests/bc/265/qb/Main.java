package qb;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        long t = sc.nextInt();

        int a[] = new int[n];
        for (int i = 0; i < n-1; i++) {
            a[i] = sc.nextInt();
        }

        int x[] = new int[m];
        int y[] = new int[m];
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < m; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
            map.put(x[i],y[i]);
        }


        for (int i = 1; i < n; i++) {

            if (t<=a[i-1]) {
                System.out.println("No");
                return;
            }

            t -=a[i-1];
            if (map.containsKey(i+1)) {
                t += map.get(i+1);
            }
        }
        System.out.println("Yes");

    }
}
