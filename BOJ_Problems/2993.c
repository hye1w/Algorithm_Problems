import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String s = scanner.next();
        int sz = s.length();
        StringBuilder ans = new StringBuilder();
        ans.append("z".repeat(sz));

        for (int i = 0; i < sz - 2; ++i) {
            for (int j = i + 1; j < sz - 1; ++j) {
                StringBuilder tmp = new StringBuilder(s);

                reverse(tmp, 0, i);
                reverse(tmp, i + 1, j);
                reverse(tmp, j + 1, sz - 1);

                if (tmp.toString().compareTo(ans.toString()) < 0) {
                    ans = new StringBuilder(tmp);
                }
            }
        }

        System.out.println(ans.toString());
    }

    private static void reverse(StringBuilder sb, int start, int end) {
        while (start < end) {
            char temp = sb.charAt(start);
            sb.setCharAt(start, sb.charAt(end));
            sb.setCharAt(end, temp);
            start++;
            end--;
        }
    }
}
