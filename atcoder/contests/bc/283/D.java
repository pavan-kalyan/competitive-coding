import java.util.*;
class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    String s = sc.nextLine();
    Stack<Character> st = new Stack<>();
    Map<Character, Integer> m = new HashMap<>();
    for (int i = 0; i < s.length(); i++) {
      if (s.charAt(i) == '(') {
        st.push((char) (i + '0'));
      } else if (s.charAt(i) == ')') {
        // int j = st.pop() - '0';
        boolean foundDigit = false;
        while (!st.isEmpty() && !foundDigit) {
          char temp = st.pop();
          if (Character.isDigit(temp)) {
            foundDigit = true;
          } else {
            m.remove(temp);
          }
        }
      } else {
        st.push(s.charAt(i));
        if (m.containsKey(s.charAt(i))) {
          System.out.println("No");
          return;
        } else {
          m.put(s.charAt(i), i);
        }
      }
    }

    System.out.println("Yes");

    return;
  }
}