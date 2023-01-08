package qa;

import java.util.Scanner;

public class Main {

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int res = n %100;
        if (res < 10) {
            System.out.println("0" + res);
        } else {
            System.out.println(res);
        }

    }
}
