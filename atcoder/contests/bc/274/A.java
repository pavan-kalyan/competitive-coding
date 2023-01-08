import java.util.*;
class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    double a = sc.nextInt();
    double b = sc.nextInt();

    double scale = 1000;
    double res = Math.round(b / a * scale) / scale;
    // double res = Math.round(b / a);
    System.out.printf("%.3f\n", res);
  }
}