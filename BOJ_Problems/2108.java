import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        int[] numbers = new int[N];
        int sum = 0;

        for (int i = 0; i < N; i++) {
            numbers[i] = Integer.parseInt(br.readLine());
            sum += numbers[i];
        }
        
        double average = (double) sum / N;
        System.out.println(Math.round(average));
        
        Arrays.sort(numbers);
        System.out.println(numbers[N / 2]);
        
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        for (int number : numbers) {
            frequencyMap.put(number, frequencyMap.getOrDefault(number, 0) + 1);
        }
        
        int maxFrequency = 0;
        List<Integer> modes = new ArrayList<>();
        
        for (Map.Entry<Integer, Integer> entry : frequencyMap.entrySet()) {
            int frequency = entry.getValue();
            if (frequency > maxFrequency) {
                maxFrequency = frequency;
                modes.clear();
                modes.add(entry.getKey());
            } else if (frequency == maxFrequency) {
                modes.add(entry.getKey());
            }
        }
        
        Collections.sort(modes);
        if (modes.size() > 1) {
            System.out.println(modes.get(1)); 
        } else {
            System.out.println(modes.get(0));  
        }

        int range = numbers[N - 1] - numbers[0];
        System.out.println(range);
    }
}
