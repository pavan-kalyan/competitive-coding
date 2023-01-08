import java.util.*;
class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();

    List<Integer> a = new ArrayList<>();
    List<Integer> o = new ArrayList<>();
    Set<Integer> s = new HashSet<>();
    for (int i = 0; i < n; i++) {
      int root = sc.nextInt();
      o.add(root);
      if (!s.contains(root)) {
        a.add(root);
        s.add(root);
      }

      if (!s.contains(root * 2)) {
        s.add(root * 2);
        a.add(root * 2);
      }
      if (!s.contains(root * 2 + 1)) {
        s.add(root * 2 + 1);
        a.add(root * 2 + 1);
      }
    }
    Collections.sort(a);
    // System.out.println(o);
    Map<Integer, Integer> gen = new HashMap<>();

    // generated amoeba
    gen.put(1, 0);
    for (int i = 0; i < a.size(); i++) {
      if (gen.containsKey(a.get(i) / 2)) {
        int parentGen = gen.get(a.get(i) / 2);
        gen.put(a.get(i), parentGen + 1);
      }
    }
    System.out.println(0);
    for (int i = 0; i < o.size(); i++) {
      // System.out.println(gen.get(o.get(i)));
      System.out.println(gen.get(o.get(i) * 2));
      System.out.println(gen.get(o.get(i) * 2 + 1));
    }
    return;
  }
}