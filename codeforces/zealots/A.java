import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    int t;
    Scanner sc = new Scanner(System.in);
    t = sc.nextInt();

    while (t-- > 0) {
      int n = sc.nextInt();
      int k = sc.nextInt();
      String strip = sc.nextLine();
      strip = sc.nextLine();

      int bcount = 0;
      int wcount = 0;
      int minCells = k;
      for (int i = 0, j = 0; i < n; i++) {
        if (i < k) {
          if (strip.charAt(i) == 'W') {
            wcount++;
          } else {
            bcount++;
          }
        } else {
          char r = strip.charAt(i);
          char l = strip.charAt(j);
          j++;
          if (l == 'W')
            wcount--;
          else
            bcount--;

          if (r == 'W')
            wcount++;
          else
            bcount++;
        }
        if (wcount + bcount == k) {
          minCells = Math.min(minCells, wcount);
        }
      }
      System.out.println(minCells);
    }
  }
}
