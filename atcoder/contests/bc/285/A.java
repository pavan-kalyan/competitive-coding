import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    if (b == a * 2 || b == (2 * a + 1)) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
