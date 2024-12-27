import java.util.*;
public class Main {
    public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    int n,k,a,b,i,j;
    n=sc.nextInt();
    k=sc.nextInt();
    int arr[]=new int[n];
    int arr1[]=new int[k];
    for(i=1;i<=k;i++)
{
    a=sc.nextInt();
    b=sc.nextInt();
    for(j=a-1;j<b;j++)
    arr[j]++;
}
 Arrays.sort(arr);
 
 System.out.println(arr[n/2]);
    }
}
