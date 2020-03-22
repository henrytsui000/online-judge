public class D086{
public static void main(String[] args){
java.util.Scanner sc = new java.util.Scanner(System.in);
while(sc.hasNext()){
String num = sc.next();
if(num.equals("0")) break;
new CharAdd(num).print();
}
}
}

class CharAdd{
private char[] charr;

public CharAdd(String s){ charr = s.toUpperCase().toCharArray();}

private int getGrade(){ 
int sum = 0;
for(int i = 0; i < charr.length; i++){
if((int)charr[i] > 90 || (int)charr[i] < 65) return -1;
else sum += (int)charr[i] - 64;
}
return sum;
}

public void print(){
int sum = getGrade();
if(sum == -1) System.out.println("Fail");
else System.out.println(sum);
}
}