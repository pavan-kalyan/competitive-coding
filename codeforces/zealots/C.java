import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    int t;
    Scanner sc = new Scanner(System.in);
    t = sc.nextInt();

    while (t-- > 0) {
      sc.nextLine();
      int n = sc.nextInt();
      int k = sc.nextInt();
      int nn = n;
      int[][] g = new int[n + 1][n + 1];
      while (nn-- > 0) {
        int s = sc.nextInt();
        int d = sc.nextInt();
        g[s][d] = 1;
        g[d][s] = 1;
      }
      nn = n;

      Set<Integer> leafSet = new HashSet<>();
      for (int i = 1; i <= n; i++) {
        int c = 0;
        for (int j = 1; j <= n; j++) {
          if (g[i][j] == 1) {
            c++;
          }
        }
        if (c == 1) {
          leafSet.add(i);
        }
      }
      k--;
      while (k-- > 0) {
        for (int node : leafSet) {
        }
      }
    }
  }
}
