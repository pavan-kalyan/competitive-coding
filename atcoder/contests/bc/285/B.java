import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    String s = sc.nextLine();
    s = sc.nextLine();

    for (int i = 1; i < n; i++) {
      int count = 0;
      for (int j = 0; j + i < n; j++) {
        if (s.charAt(j) != s.charAt(j + i)) {
          count++;
        } else {
          break;
        }
      }
      System.out.println(count);
    }
  }
}
