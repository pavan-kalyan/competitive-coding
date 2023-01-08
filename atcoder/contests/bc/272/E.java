class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int res = 0;
    while (n-- > 0) {
      res += sc.nextInt();
    }
    System.out.println(res);
  }
}