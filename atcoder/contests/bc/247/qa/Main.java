import java.util.Scanner;

public class Main {

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        System.out.print("0");
        for(int i=0; i<3; i++){
            System.out.print(s.charAt(i));
        }
        System.out.println("");
    }
}
