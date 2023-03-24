import java.util.*;

public class C {
	static Scanner sc;
	public static void main(String[] args) {

		int t;
		sc = new Scanner(System.in);
		t = sc.nextInt();

		while (t-->0) {
			solve();
		}

	}

	public static void solve() {
		int n;
		n = sc.nextInt();

		List<Set<Integer>> a = new ArrayList<>();
		for (int i=0;i<5;i++) {
			a.add(new HashSet<>());
		}

		for (int i=0;i<n;i++) {
			for (int j=0;j<5;j++) {
				int t;
				t = sc.nextInt();
				if (t==1) {
					a.get(j).add(i);
				}
			}
		}
		for (int i=0;i<5;i++) {
			for (int j=i+1;j<5;j++) {

				Set<Integer> s1 = new HashSet<>(a.get(i));
				Set<Integer> s2 = new HashSet<>(a.get(j));
				// intersection
				Set<Integer> inter = new HashSet<>(s1);
				inter.retainAll(s2);

				// union
				Set<Integer> union = new HashSet<>(a.get(i));
				union.addAll(s2);

				// System.out.println(a.get(j));
				// if (s1.size() > s2.size()) {
				// 	s1.removeAll(inter);
				// } else if (s1.size() < s2.size()) {
				// 	s2.removeAll(inter);
				// }
				// System.out.println("i,j " + i + " " + j);
				// System.out.println(s1);
				// System.out.println(s2);
				// System.out.println(inter);

				if (union.size() == n && ((s1.size() >= n/2 && s2.size() >= n/2) || s1.size() == s2.size())) {
					System.out.println("YES");
					return;
				}
			}
		}
		System.out.println("NO");

	}

}
