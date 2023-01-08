import java.util.ArrayList;
import java.util.List;

public class YugQ4 {

    public static void main(String[] args) {

        List<Integer> positions = new ArrayList<>();
        StringBuilder res = new StringBuilder();
        
        insert(positions, 2);
        insert(positions, 5);

        print(positions);
        
        if (check(positions, 5,2)) {
            res.append("1");
        } else {
            res.append("0");
        }

        if (check(positions, 6,3)) {
            res.append("1");
        } else {
            res.append("0");
        }

        if (check(positions, 5,4)) {
            res.append("1");
        } else {
            res.append("0");
        }
        
        System.out.println(res.toString());
        
    }
    
    public static void print(List<Integer> positions) {
        for(int i=0;i<positions.size();i++) {
            System.out.print(positions.get(i) + " ");
        }
        System.out.println("");
    }

    public static void insert(List<Integer> positions, int elem) {
        int i=0;
        while (i <= positions.size()-1 && i >=0 && elem > positions.get(i)) {
            i++;
        }
        positions.add(i, elem);
    }

    public static boolean check(List<Integer> positions, int end, int size) {

        Integer earliestRightIdx = Integer.MAX_VALUE;
        
        int i = positions.size()-1;

        while (i>=0 && positions.get(i) >= end) {
            i--;
            earliestRightIdx = Math.min(earliestRightIdx, i);
        }
        System.out.println("earliestRighIdx " + earliestRightIdx);
        if (earliestRightIdx == 0) return true;
        int latestLeft;
        if (earliestRightIdx == Integer.MAX_VALUE) {
            latestLeft = positions.size()-1;
        } else {
            latestLeft = i - 1;
        }
        System.out.println("latestLeft " + latestLeft);
        
        if (positions.get(latestLeft) + size > end) {
            return false;
        }
        return true;
    }
}


