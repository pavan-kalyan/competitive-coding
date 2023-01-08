import java.util.*;
class Main {
  public static class W {
    int up;
    int down;
    int left;
    int right;
    W() {}
    public String toString() {
      return "u " + up + " d " + down + " l " + left + " r " + right + "\n";
    }
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int m = sc.nextInt();
    int n = sc.nextInt();
    int startX = sc.nextInt() - 1;
    int startY = sc.nextInt() - 1;
    int walls = sc.nextInt();
    int[][] grid = new int[m][n];
    for (int i = 0; i < walls; i++) {
      int x = sc.nextInt();
      int y = sc.nextInt();
      grid[x - 1][y - 1] = 1;
    }

    int[] up = new int[n];
    int[] down = new int[n];
    int[] left = new int[m];
    int[] right = new int[m];
    for (int i = 0; i < n - 1; i++) {
      up[i] = -1;
      down[i] = m;
    }
    for (int i = 0; i < m; i++) {
      left[i] = -1;
      right[i] = n;
    }

    W dp[][] = new W[m][n];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          up[j] = Math.max(up[j], i);
          left[i] = Math.max(left[i], j);
        }
        W w = new W();
        w.left = left[i];
        w.up = up[j];
        dp[i][j] = w;
      }
    }

    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (grid[i][j] == 1) {
          down[j] = Math.min(down[j], i);
          right[i] = Math.min(right[i], j);
        }
        dp[i][j].right = right[i];
        dp[i][j].down = down[j];
      }
    }

    int q = sc.nextInt();
    int nextX = startX;
    int nextY = startY;
    List<String> res = new ArrayList<>();
    for (int i = 0; i < q; i++) {
      // System.out.println(Arrays.deepToString(inputs));
      char d = sc.next().charAt(0);
      int times = sc.nextInt();
      // System.out.println("current " + nextX + ", " + nextY);
      if (d == 'L') {
        // System.out.println("left wall " + dp[nextX][nextY].left);
        nextY = Math.max(dp[nextX][nextY].left + 1, nextY - times);
        // nextY = nextY;
      } else if (d == 'R') {
        nextY = Math.min(dp[nextX][nextY].right - 1, nextY + times);
        // nextX = nextX;
      } else if (d == 'U') {
        nextX = Math.max(dp[nextX][nextY].up + 1, nextX - times);
      } else if (d == 'D') {
        nextX = Math.min(dp[nextX][nextY].down - 1, nextX + times);
      }
      res.add((nextX + 1) + " " + (nextY + 1));
    }

    for (String ans : res) {
      System.out.println(ans);
    }

    return;
  }
}
