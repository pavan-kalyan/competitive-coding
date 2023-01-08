import java.util.*;
class B {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int[] k = new int[m];
    Map<Integer, List<Integer>> partyToParticipants = new HashMap<>();
    for (int i = 0; i < m; i++) {
      k[i] = sc.nextInt();
      for (int j = 0; j < k[i]; j++) {
        int participant = sc.nextInt();
        List<Integer> participants = partyToParticipants.getOrDefault(i, new ArrayList<>());
        participants.add(participant);
        partyToParticipants.put(i, participants);
      }
    }
    Map<Integer, Set<Integer>> participantToParties = new HashMap<>();

    for (Map.Entry<Integer, List<Integer>> e : partyToParticipants.entrySet()) {
      List<Integer> participants = e.getValue();
      for (int i = 0; i < participants.size(); i++) {
        Set<Integer> parties =
            participantToParties.getOrDefault(participants.get(i), new HashSet<>());
        parties.add(e.getKey());
        participantToParties.put(participants.get(i), parties);
      }
    }

    boolean result = true;
    for (int i = 1; i <= n; i++) {
      Set<Integer> parties1 = participantToParties.getOrDefault(i, new HashSet<>());
      for (int j = i + 1; j <= n; j++) {
        Set<Integer> parties2 = participantToParties.getOrDefault(j, new HashSet<>());
        if (Collections.disjoint(parties1, parties2)) {
          result = false;
          break;
        }
      }
    }
    if (result)
      System.out.println("Yes");
    else
      System.out.println("No");
  }
}
