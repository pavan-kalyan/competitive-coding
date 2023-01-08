import java.util.*;
class B {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long x = sc.nextLong();
    int k = sc.nextInt();

    for (int i = 1; i <= k; i++) {
      x = (long) Math.pow(10, i) * (long) Math.round(x / Math.pow(10, i));
    }
    System.out.println(x);
    return;
  }
}
