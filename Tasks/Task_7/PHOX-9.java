import java.util.*;
public class Main {
    public static boolean compare(String a,String b, HashMap hm)
{
    int l1,l2,i;
    l1=a.length();
    l2=b.length();
    for(i=0;i<Math.min(l1,l2);i++)
{
    if((int)hm.get(a.charAt(i))>(int)hm.get(b.charAt(i)))
    return true;
    else if((int)hm.get(a.charAt(i))<(int)hm.get(b.charAt(i)))
    return false;
    else
{
    continue;
}
}
    if(l1>l2)
    return true;
    else
    return false;
}

    public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    int n,i,j;
    String s,temp;
    s=sc.nextLine();
    n=sc.nextInt();
    sc.nextLine();
    String a[]= new String[n];
    for(i=0;i<n;i++)
    a[i]=sc.nextLine();
    HashMap<Character, Integer> hm = new HashMap<>();
    for(i=1;i<=26;i++)
    hm.put(s.charAt(i-1),i);
    
    for(i=0;i<n;i++)
{
    for(j=i+1;j<n;j++)
{
    if(compare(a[i],a[j],hm))
{
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
}
}
  for(i=0;i<n;i++)
 System.out.println(a[i]);
    
    }
}
