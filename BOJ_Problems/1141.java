import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int answer = 0;

        ArrayList<String> list = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            list.add(scanner.next());
        }

        // 리스트를 문자열의 길이 순으로 정렬
        Collections.sort(list, Comparator.comparingInt(String::length));

        for (int i = 0; i < list.size(); i++) {

            boolean check = true;
            for (int j = i + 1; j < list.size(); j++) {

                if (list.get(j).startsWith(list.get(i))) {
                    check = false;
                    break;
                }
            }

            if (check) {
                answer++;
            }
        }

        System.out.println(answer);
    }
}
