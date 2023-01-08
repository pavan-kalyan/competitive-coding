import java.util.*;
class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }
    int q = sc.nextInt();
    for (int i = 0; i < q; i++) {
      int type = sc.nextInt();
      if (type == 1) {
        int k = sc.nextInt() - 1;
        int val = sc.nextInt();
        a[k] = val;
      } else {
        int k = sc.nextInt() - 1;
        System.out.println(a[k]);
      }
    }

    return;
  }
}