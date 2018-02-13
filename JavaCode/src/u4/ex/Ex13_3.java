package u4.ex;

import java.util.Random;
import java.util.Scanner;

public class Ex13_3 {


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();

        int[] intarr = new int[100];

        for(int i = 0; i < intarr.length; i++)
            intarr[i] = random.nextInt();

        System.out.println("Enter a number between 0 and 99.");
        try{
            System.out.println(intarr[scanner.nextInt()]);
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Out of Bounds.");
        }
    }
}
