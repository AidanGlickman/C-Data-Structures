package u4.ex;

import java.util.Scanner;

public class Ex13_2 {
    public static void main(String[] args) {
        boolean valid = false;
        while(!valid) {
            Scanner scanner = new Scanner(System.in);
            System.out.println("Enter two integers seperated by a space.");
            String in = scanner.nextLine();
            String[] splitted = in.split(" ");
            try{
                System.out.println(Integer.parseInt(splitted[0]) + Integer.parseInt(splitted[1]));
                valid = true;
            }
            catch (NumberFormatException e){
                System.out.println("Invalid input. Try again");
            }
        }

    }
}
