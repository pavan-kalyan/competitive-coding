import java.util.*;
class C {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }
    Map<Integer, Integer> m = new HashMap<>();

    for (Integer x : a) {
      m.put(x, m.getOrDefault(x, 0) + 1);
    }

    List<Integer> temp = new ArrayList<>(m.keySet());

    Map<Integer, Integer> amap = new HashMap<>();
    Collections.sort(temp);
    for (int i = 0; i < temp.size(); i++) {
      amap.put(temp.get(i), temp.size() - i - 1);
    }
    // amap.entrySet().stream().forEach((e) -> System.out.println(e.getKey() + " : " +
    // e.getValue()));

    Map<Integer, Integer> finalMap = new HashMap<>();
    for (int i = 0; i < n; i++) {
      int val = amap.get(a[i]);
      finalMap.put(val, finalMap.getOrDefault(val, 0) + 1);
    }

    for (int i = 0; i < n; i++) {
      System.out.println(finalMap.getOrDefault(i, 0));
    }

    return;
  }
}
