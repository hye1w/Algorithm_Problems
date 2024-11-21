import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = br.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);

        Set<String> unheard = new HashSet<>();
        for (int i = 0; i < n; i++) {
            unheard.add(br.readLine());
        }

        ArrayList<String> unheardUnseen = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            String name = br.readLine();
            if (unheard.contains(name)) {
                unheardUnseen.add(name);
            }
        }

        Collections.sort(unheardUnseen);
        System.out.println(unheardUnseen.size());
        for (String name : unheardUnseen) {
            System.out.println(name);
        }
    }
}
