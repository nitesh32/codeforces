import java.util.Scanner;
class PrimeNumbers{
public static void main (String[] args){
    
    Scanner in = new Scanner (System.in);
    System.out.print("enter the number of elements : ");
    int n  = in.nextInt();
    int x;
    System.out.println("Enter the elements : ");
    int eve=0,eve_cou=0,od=0,od_cou=0;
    for(int i=1; i<=n; i++)
    {
        x = in.nextInt();
        if(x%2==0){
            eve += x;
            eve_cou += 1;
        }
        else{
            od += x;
            od_cou += 1;
        }

    }
    System.out.print("count of even numbers : "+eve_cou+"\n");
    System.out.print("sum of even numbers  : "+eve+"\n");
    System.out.print("average of even numbers : "+eve/eve_cou+"\n\n");
    System.out.print("count of odd numbers : "+od_cou+"\n");
    System.out.print("sum of odd numbers  : "+od+"\n");
    System.out.print("average of odd numbers : "+od/od_cou+"\n");
    
    

         

}
}