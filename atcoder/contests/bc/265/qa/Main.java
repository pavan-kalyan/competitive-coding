package qa;

import java.util.*;

public class Main {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int x = sc.nextInt();
        int y = sc.nextInt();
        int n = sc.nextInt();

        if (y/3 < x) {
            int q = n/3;
            int r = n%3;
            int answer = q*y + r*x;
            System.out.println(answer);
        } else {
            System.out.println(x*n);
        }

    }
}
