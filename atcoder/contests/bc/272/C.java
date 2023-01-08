import java.util.*;
class C {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }

    // find max even
    int maxEven = Integer.MIN_VALUE;
    int maxOdd = Integer.MIN_VALUE;
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == 0) {
        maxEven = Math.max(maxEven, a[i]);
      } else {
        maxOdd = Math.max(maxOdd, a[i]);
      }
    }
    // System.out.println(maxEven + " " + maxOdd);

    // find next best max and even
    int nextMaxEven = Integer.MIN_VALUE;
    int nextMaxOdd = Integer.MIN_VALUE;
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == 0 && a[i] < maxEven) {
        nextMaxEven = Math.max(nextMaxEven, a[i]);
      } else if (a[i] % 2 != 0 && a[i] < maxOdd) {
        nextMaxOdd = Math.max(nextMaxOdd, a[i]);
      }
    }
    // System.out.println(nextMaxEven + " " + nextMaxOdd);
    if ((maxEven == Integer.MIN_VALUE || nextMaxEven == Integer.MIN_VALUE)
        && (nextMaxOdd == Integer.MIN_VALUE || maxOdd == Integer.MIN_VALUE)) {
      System.out.println("-1");
      return;
    }
    long maxEvenSum = 0;
    if (nextMaxEven != Integer.MIN_VALUE && maxEven != Integer.MIN_VALUE) {
      maxEvenSum = (long) maxEven + (long) nextMaxEven;
    }
    long maxOddSum = 0;
    if (nextMaxOdd != Integer.MIN_VALUE && maxOdd != Integer.MIN_VALUE) {
      maxOddSum = (long) maxOdd + (long) nextMaxOdd;
    }
    if (maxEvenSum > maxOddSum) {
      System.out.println(maxEvenSum);
    } else {
      System.out.println(maxOddSum);
    }
    return;
  }
}
