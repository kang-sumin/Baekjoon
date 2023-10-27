package JAVA;

import java.util.Arrays;
import java.util.Scanner;

public class baekjoon_2750 {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int count = scanner.nextInt();
        int[] array = new int[count];   

        //입력
        for(int i=0; i < count; i++){
            array[i] = scanner.nextInt();
        }

        //오름차순 정렬
        Arrays.sort(array);

        StringBuilder stringBuilder = new StringBuilder();
        for(int print :array){
            stringBuilder.append(print+"\n");
        }
        System.out.println(stringBuilder);
    }
}
