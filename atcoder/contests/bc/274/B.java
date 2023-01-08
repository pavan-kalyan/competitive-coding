import java.util.*;
class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int H = sc.nextInt();
    int W = sc.nextInt();
    int[][] grid = new int[H][W];
    // System.out.println("H and W = " + H + " " + W);

    // System.out.println(sc.nextLine());
    sc.nextLine();
    // System.out.println(sc.nextLine());
    // System.out.println(sc.nextLine());
    // System.out.println(sc.nextLine());
    //
    for (int i = 0; i < H; i++) {
      String row = sc.nextLine();
      for (int j = 0; j < W; j++) {
        char c = row.charAt(j);
        // System.out.println(c);
        if (c == '#') {
          grid[i][j] = 1;
        }
      }
    }
    int[] x = new int[W];
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (grid[i][j] == 1) {
          x[j]++;
        }
      }
    }
    for (int i = 0; i < W; i++) {
      System.out.print(x[i] + " ");
    }

    // System.out.println(grid);

    // System.out.printf("%.3f\n", res);
  }
}