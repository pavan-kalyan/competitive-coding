import java.util.Arrays;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    int t;
    Scanner sc = new Scanner(System.in);
    t = sc.nextInt();

    while (t-- > 0) {
      int W = sc.nextInt();
      int H = sc.nextInt();
      int x1 = sc.nextInt();
      int y1 = sc.nextInt();
      int x2 = sc.nextInt();
      int y2 = sc.nextInt();
      int w3 = sc.nextInt();
      int h3 = sc.nextInt();

      double w1 = dist(0, y1, x1, y1);
      double w2 = dist(x2, y2, W, y2);
      double h1 = dist(x1, 0, x1, y1);
      double h2 = dist(x2, H, x2, y2);

      if (w3 <= w1 || w3 <= w2) {
        System.out.println(0);
        continue;
      }
      if (h3 <= h1 || h3 <= h2) {
        System.out.println(0);
        continue;
      }

      double wmax = Math.max(w1, w2);
      double hmax = Math.max(h1, h2);
      double maxW = w1 + w2;
      double maxH = h1 + h2;

      double wd = Math.max(w3 - wmax, 0);
      double hd = Math.max(h3 - hmax, 0);

      if (maxW - w3 < 0 && maxH - h3 < 0) {
        System.out.println(-1);
        continue;
      } else if (maxW - w3 < 0) {
        System.out.println(hd);
        continue;
      } else if (maxH - h3 < 0) {
        System.out.println(wd);
        continue;
      }
      if (wd == 0) {
        System.out.println(hd);
        continue;
      }
      if (hd == 0) {
        System.out.println(wd);
        continue;
      }

      System.out.println(Math.min(wd, hd));
    }
  }
  public static double dist(int x1, int y1, int x2, int y2) {
    double dist = 0;
    int xd = Math.abs(x1 - x2);
    int yd = Math.abs(y1 - y2);
    dist = Math.pow(xd, 2) + Math.pow(yd, 2);
    dist = Math.sqrt(dist);
    return dist;
  }
}