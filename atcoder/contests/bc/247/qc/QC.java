import java.util.*;

public class QC {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        printS(n);
    }

    public static void printS(int n) {

        if (n == 0) {
            return;
        }

        printS(n - 1);
        System.out.print(n + " ");
        printS(n - 1);
    }

}
