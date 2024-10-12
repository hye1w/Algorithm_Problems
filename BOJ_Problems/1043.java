import java.util.*;

public class Main {
    static int[] parent;
 
    public static int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
 
    public static void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX;  
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); 
        int M = sc.nextInt();  

        parent = new int[N + 1];  
        for (int i = 1; i <= N; i++) {
            parent[i] = i;  
        }

        int truthCount = sc.nextInt(); 
        List<Integer> truthPeople = new ArrayList<>();
        for (int i = 0; i < truthCount; i++) {
            truthPeople.add(sc.nextInt());  
        }

        List<List<Integer>> parties = new ArrayList<>(); 
        for (int i = 0; i < M; i++) {
            int partySize = sc.nextInt();  
            List<Integer> party = new ArrayList<>();
            for (int j = 0; j < partySize; j++) {
                party.add(sc.nextInt()); 
            }
            parties.add(party);
 
            for (int j = 1; j < party.size(); j++) {
                union(party.get(0), party.get(j));
            }
        }
 
        for (int i = 1; i < truthPeople.size(); i++) {
            union(truthPeople.get(0), truthPeople.get(i));
        }
 
        int maxLieParties = 0;
        for (List<Integer> party : parties) {
            boolean canLie = true;
            for (int person : party) {
                if (truthCount > 0 && find(person) == find(truthPeople.get(0))) {
                    canLie = false;  
                    break;
                }
            }
            if (canLie) {
                maxLieParties++;
            }
        }

        System.out.println(maxLieParties);  
    }
}
