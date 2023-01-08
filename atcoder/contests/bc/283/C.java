import java.util.*;
class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    String input = sc.nextLine();
    // System.out.println(input);
    int pairs = 0;
    for (int i = 0; i < input.length(); i++) {
      if (i + 1 < input.length() && input.charAt(i) == '0' && input.charAt(i + 1) == '0') {
        pairs++;
        i++;
      } else {
        pairs++;
      }
    }
    System.out.println(pairs);

    return;
  }
}