package Java.OJ;
import java.io.*;

public class P5708 {
    public void main(String avg[]) throws IOException {

        BufferedReader br = 
            new BufferedReader(new InputStreamReader(System.in));
        int n = (int) br.read();
        int max = n;
        int[] arr = new int[n];
        while(n > 0){
            arr[n-1] = (int) br.read();
            n--;
        } 
        while(n < max){
            System.out.println(arr[n]);
        }

    }
}
