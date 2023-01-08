import java.util.*;

public class QB {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        List<String> sa = new ArrayList<String>();
        List<String> ta = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String s = sc.next();
            sa.add(s);
            String t = sc.next();
            ta.add(t);
        }

        Map<String, Integer> nameCount = new HashMap<>();

        for (int i = 0; i < n; i++) {
            if (nameCount.containsKey(sa.get(i))) {
                nameCount.put(sa.get(i), nameCount.get(sa.get(i)) + 1);
            } else {
                nameCount.put(sa.get(i), 1);
            }
            if (nameCount.containsKey(ta.get(i))) {
                nameCount.put(ta.get(i), nameCount.get(ta.get(i)) + 1);
            } else {
                nameCount.put(ta.get(i), 1);
            }
        }

        for (int i = 0; i < n; i++) {
            if ((nameCount.containsKey(sa.get(i)) && nameCount.get(sa.get(i)) > 1) &&
                    (nameCount.containsKey(ta.get(i)) && nameCount.get(ta.get(i)) > 1)) {
                System.out.println("No");
                return;
            }
        }

        System.out.println("Yes");
    }

}
