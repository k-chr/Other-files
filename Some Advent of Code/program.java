import java.io.File;
import java.io.FileNotFoundException;
import java.util.NoSuchElementException;
import java.util.Scanner;
class Program {
    public static void main(String[] args)  throws FileNotFoundException {
        {
            File file = new File("input.txt");
            Scanner in = new Scanner(file);
            int twos = 0;
            int threes = 0;
            for(;true;){
                try {
                    String sentence = in.nextLine();
                    int tab[] = new int['z'- 'a' + 1];
                    boolean set = false;
                    boolean set1 = false;
                    for(int i = 0; i < sentence.length();tab[sentence.charAt(i) - 'a']++,++i);
                    for(int i = 0; i < tab.length;++i)
                    {
                        if(tab[i] == 2 && !set){
                            twos += 1;
                            set=true;
                        }
                        else if(tab[i] == 3 && !set1){
                            threes+=1;
                            set1= true;
                        }
                    }
                }
                catch (NoSuchElementException e){
                    break;
                }
            }

            System.out.println(twos*threes);
        }
    }
}