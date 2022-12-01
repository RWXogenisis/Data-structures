import java.util.*;
import java.lang.*;
import java.io.*;


import java.io.*;
import java.util.*;

class FileCreation{
	public void createFile() throws IOException {
		String fileContent = "14 Ram Ram@gmail.com 9876543433 Afghanistan\r\n" + 
    			"170 Janu Janu@gmail.com 9876543434 Albania\r\n" + 
    			"197 Karthick Karthick@gmail.com 9876543435 Algeria\r\n" + 
    			"123 Kumar Kumar@gmail.com 9876543436 Antarctica\r\n" + 
    			"166 Gobi Gobi@gmail.com 9876543443 Barbados\r\n" + 
    			"116 Guru Guru@gmail.com 8876543444 Bermuda\r\n" + 
    			"191 John John@gmail.com 9876543445 Brazil\r\n" + 
    			"70 Sri Sri@gmail.com 9876543446 Canada\r\n" + 
    			"175 Babu Babu@gmail.com 9876543447 Cuba\r\n" + 
    			"55 vishal vishal@gmail.com 8876543449 Afghanistan\r\n" + 
    			"136 Ravi Ravi@gmail.com 9876543450 Albania\r\n" + 
    			"76 Shyuam Shyuam@gmail.com 9876543451 Algeria\r\n" + 
    			"10 Seetha Seetha@gmail.com 9876543452 Antarctica\r\n" + 
    			"47 Deepa Deepa@gmail.com 9876543453 Barbados\r\n" + 
    			"15 Keethir Keethir@gmail.com 9876543454 Bermuda\r\n" + 
    			"53 Kathir Kathir@gmail.com 9876543455 Brazil\r\n" + 
    			"104 Babu Babu@gmail.com 9876543456 Canada\r\n" + 
    			"99 Prasanth Prasanth@gmail.com 9876543457 Cuba\r\n" + 
    			"79 Reeha Reeha@gmail.com 9876543437 Finland\r\n" + 
    			"97 Smith Smith@gmail.com 9876543438 India\r\n" + 
    			"173 rani rani@gmail.com 9876543439 India\r\n" + 
    			"168 Reeta Reeta@gmail.com 9876543440 India\r\n" + 
    			"32 raji raji@gmail.com 9876543441 India\r\n" + 
    			"11 vani vani@gmail.com 9876543442 India";
        
        FileWriter fileWriter = new FileWriter("File1.txt");
        fileWriter.write(fileContent);
        fileWriter.close();
	}
}



public class Main{
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        try{
            FileCreation fc = new FileCreation();
            fc.createFile();
            
            FileReader f1 = new FileReader("File1.txt");
            FileWriter f2 = new FileWriter("File2.txt");
            
            BufferedReader br = new BufferedReader(f1);
            
            String sent = "";
            String line;
            while((line=br.readLine())!=null){
                sent+=line;
                sent+="\n";
            }
            
            String data[] = sent.split("\n");
            int flag = 1;
            while(flag != 0){
                flag = 0;
                for(int i =0 ; i<data.length-1; i++){
                    if(Integer.valueOf(data[i].split(" ")[0]) > Integer.valueOf(data[i+1].split(" ")[0])){
                        String temp = data[i];
                        data[i] = data[i+1];
                        data[i+1] = temp;
                        flag+=1;
                    }
                }
            }
            
            for(String i:data){
                System.out.println(i);
            }
            
            
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
}
