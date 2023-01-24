import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    sc.nextLine();
    Map<String, String> m = new HashMap<>();
    for (int i = 0; i < n; i++) {
      String inp = sc.nextLine();
      String src = inp.split(" ")[0];
      String dst = inp.split(" ")[1];

      m.put(src, dst);
    }

    // check for cycle
    Set<String> visited = new HashSet<>();
    Set<String> permVisited = new HashSet<>();
    for (String start : m.keySet()) {
      if (!permVisited.contains(start) && detectCycle(m, visited, start, permVisited)) {
        System.out.println("No");
        return;
      }
    }
    System.out.println("Yes");
  }

  public static boolean detectCycle(
      Map<String, String> m, Set<String> visited, String start, Set<String> permVisited) {
    permVisited.add(start);
    if (visited.contains(start)) {
      return true;
    }
    visited.add(start);

    if (m.containsKey(start)) {
      String next = m.get(start);
      boolean detected = detectCycle(m, visited, next, permVisited);
      if (detected) {
        visited.remove(start);
        return detected;
      }
    }

    visited.remove(start);
    return false;
  }
}
