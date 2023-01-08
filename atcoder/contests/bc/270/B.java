import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int X = sc.nextInt();
    int Y = sc.nextInt();
    int Z = sc.nextInt();

    int ans = -1;
    if (X == 0)
      ans = 0;
    if (X > 0 && Y > 0 && X < Y) {
      ans = Math.abs(X);
    } else if (X < 0 && Y > 0) {
      ans = Math.abs(X);
    } else if (X > 0 && Y < 0) {
      ans = Math.abs(X);
    } else if (X < 0 && Y < 0 && X > Y) {
      ans = Math.abs(X);
    } else if (X > 0 && Y > 0 && Y < X) {
      if (Z < Y) {
        if (Z > 0) {
          ans = X;
        } else {
          ans = Math.abs(Z) + Math.abs(Z) + Math.abs(X);
        }
      } else {
        ans = -1;
      }
    } else if (X < 0 && Y < 0 && X < Y) {
      if (Z > Y) {
        if (Z < 0) {
          ans = X;
        } else {
          ans = Math.abs(Z) + Math.abs(Z) + Math.abs(X);
        }
      } else {
        ans = -1;
      }
    }
    System.out.println(ans);
  }
}