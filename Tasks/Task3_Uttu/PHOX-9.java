import java.util.*;
public class Main {
    public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    int n,x,i,v,f=0;
    n=sc.nextInt();
    x=sc.nextInt();
    int a[]=new int[n];
    int b[]=new int[n];
    for(i=0;i<n;i++)
{
    a[i]=sc.nextInt();
    b[i]=a[i];
}
    Arrays.sort(b);
 if(Arrays.equals(a,b))
 System.out.println("YES");
 else
 {
    v=x-n/2;
    if(v<=0)
    System.out.println("YES");
    else if(x==n)
    System.out.println("NO");
    else
{
  for(i=n-x;i<x;i++)
 {
     if(a[i]!=b[i])
    {
        f=1;
        break;
    }
 }
    if(f==1)
    System.out.println("NO");
    else
    System.out.println("YES");
}
}

    }
}
