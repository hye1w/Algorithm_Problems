import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Set<String> setS = new HashSet<>();

        String[] NM = br.readLine().split(" ");
        int N = Integer.parseInt(NM[0]);
        int M = Integer.parseInt(NM[1]);

        for (int i = 0; i < N; i++) {
            setS.add(br.readLine());
        }

        int count = 0;
        for (int i = 0; i < M; i++) {
            String str = br.readLine();
            if (setS.contains(str)) {
                count++;
            }
        }

        System.out.println(count);
    }
}
