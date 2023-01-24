import java.util.*;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    int n;
    int q;
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    q = sc.nextInt();

    Long[] p = new Long[n];
    for (int i = 0; i < n; i++) {
      p[i] = sc.nextLong();
    }
    Arrays.sort(p);

    Long[] pre = new Long[n + 1];
    pre[0] = 0L;
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + p[i];
    }
    // System.out.println(Arrays.toString(pre));

    int[][] qs = new int[q][2];
    for (int i = 0; i < q; i++) {
      int x = sc.nextInt();
      int y = sc.nextInt();
      // System.out.println(pre[n - x + y] - pre[n - x]);
      qs[i][0] = x;
      qs[i][1] = y;
    }

    for (int i = 0; i < q; i++) {
      int x = qs[i][0];
      int y = qs[i][1];
      long ans = pre[n - x + y] - pre[n - x];
      System.out.println(ans);
    }
  }
}
