package Thread;

// Application with two threads manipulating an unsynchronized buffer.
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class SharedBufferTest
{
public static void main( String[] args )
{
// create new thread pool with two threads
ExecutorService application = Executors.newCachedThreadPool();

// create UnsynchronizedBuffer to store ints
Buffer sharedLocation = new UnsynchronizedBuffer();

System.out.println(
"Action\t\tValue\tSum of Produced\tSum of Consumed" );
System.out.println(
"------\t\t-----\t---------------\t---------------\n" );

// execute the Producer and Consumer, giving each of them access
// to sharedLocation
application.execute( new Producer( sharedLocation ) );
application.execute( new Consumer( sharedLocation ) );

application.shutdown(); // terminate application when tasks complete
} // end main
} // end class SharedBufferTest