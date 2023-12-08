package Thread;

// Producer and Consumer threads manipulating a circular buffer.
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class CircularBufferTest
{
public static void main( String[] args )
{
// create new thread pool with two threads
ExecutorService application = Executors.newCachedThreadPool();

// create CircularBuffer to store ints
CircularBuffer sharedLocation = new CircularBuffer();

// display the initial state of the CircularBuffer
sharedLocation.displayState( "Initial State" );

// execute the Producer and Consumer tasks
application.execute( new Producer( sharedLocation ) );
application.execute( new Consumer( sharedLocation ) );

application.shutdown();
} // end main
} //end class CircularBufferTest