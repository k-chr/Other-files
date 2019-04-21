import java.io.File;
import java.io.FileNotFoundException;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.Vector;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
class Program2 {
    public static void main(String[] args)  throws FileNotFoundException {
        {


            final String regex = "(?=.*\\D+.*$)(^(?!-\\d.*$)|(.+-.+)|.*[a-zA-Z]+.*)";
            final String string = "-1";

            final Pattern pattern = Pattern.compile(regex, Pattern.MULTILINE);
            final Matcher matcher = pattern.matcher(string);

            while (matcher.find()) {
                System.out.println("Full match: " + matcher.group(0));
                for (int i = 1; i <= matcher.groupCount(); i++) {
                    System.out.println("Group " + i + ": " + matcher.group(i));
                }
            }
            File file = new File("input.txt");
            Scanner in = new Scanner(file);
            Vector<String> s = new Vector<>();
            for(;;){
                try {
                    String sentence = in.nextLine();
                    s.add(sentence);
                }
                catch (NoSuchElementException e){
                    break;
                }
            }
            String out = "";
            for(int i = 0;i < s.size() - 1; ++i){
               boolean end = false;
               String mech = s.get(i);
               for(int j = i + 1; j < s.size(); ++j){
                   String hcem = s.get(j);
                   int diffs = 0;
                   int pos = 0;
                   for(int k =0; k < hcem.length(); ++k){
                       if(hcem.charAt(k) != mech.charAt(k)){
                           ++diffs;
                           pos = k;
                       }
                   }
                   if(diffs == 1){
                       out = mech.substring(0, pos);
                       out += mech.substring(pos+1);
                       end = true;
                       break;
                   }
               }
               if(end) break;
            }
            System.out.println(out);
        }
    }
}