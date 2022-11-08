package semaphores0;

//dodanie semaforów
import java.util.concurrent.Semaphore;

 
public class Semaphores0 {
    
public static final int COUNT=2,DELAY=250;
    
    //stworzenie przepustki sempahore
        static Semaphore a = new Semaphore(3,true);
        static Semaphore b = new Semaphore(0,true);
        static Semaphore c = new Semaphore(0,true);
        
private static final class poka_A extends Thread { //thread definition

 @Override
@SuppressWarnings("SleepWhileInLoop")
public void run() {
try {
    for (int j = 0; j < COUNT; j++) {
 for (int i = 0; i < 3; i++) {
//use semaphores here
a.acquire();
System.out.print("A ");
//use semaphores here

 Thread.sleep(DELAY);
}
 b.release(3);
    
    } 
}
catch (InterruptedException ex) {
System.out.println("Ooops...");
Thread.currentThread().interrupt();
throw new RuntimeException(ex);
 }

System.out.println("\nThread A: I'm done...");
 }
}
    
private static final class poka_B extends Thread { //thread definition

 @Override
@SuppressWarnings("SleepWhileInLoop")
public void run() {
try {
 for (int j = 0; j < COUNT; j++) {
 for (int i = 0; i < 3; i++) {
//use semaphores here
b.acquire();
System.out.print("B ");
//use semaphores here

 Thread.sleep(DELAY);
}
 c.release(3);
    
    } 
}
catch (InterruptedException ex) {
System.out.println("Ooops...");
Thread.currentThread().interrupt();
throw new RuntimeException(ex);
 }

System.out.println("Thread B: I'm done...");
 }
}

private static final class poka_C extends Thread { //thread definition

 @Override
@SuppressWarnings("SleepWhileInLoop")
public void run() {
try {
 for (int j = 0; j < COUNT; j++) {
 for (int i = 0; i < 3; i++) {
//use semaphores here
c.acquire();
System.out.print("C ");
//use semaphores here

 Thread.sleep(DELAY);
}
 a.release(3);
    
    } 
 } 
catch (InterruptedException ex) {
System.out.println("Ooops...");
Thread.currentThread().interrupt();
throw new RuntimeException(ex);
 }

System.out.println("Thread C: I'm done...");
 }
}


    public static void main(String[] args) {
        
        
        new poka_A().start();
        new poka_B().start();
        new poka_C().start();
        //System.out.println("Bye!");
    }
    
}
