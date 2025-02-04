import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter an integer: ");
        int num = scanner.nextInt();
        
        String binary = "";

        while (num > 0) {
            binary = (num % 2) + binary;
            num /= 2;
        }

        System.out.println("Binary representation: " + (binary.isEmpty() ? "0" : binary));
        scanner.close();
    }
}
