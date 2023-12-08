package Thread;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class BlockingBufferTest
{
public static void main( String[] args )
{
// create new thread pool with two threads
ExecutorService application = Executors.newCachedThreadPool();

// create BlockingBuffer to store ints
Buffer sharedLocation = new BlockingBuffer();

application.execute( new Producer( sharedLocation ) );
application.execute( new Consumer( sharedLocation ) );

application.shutdown();
} // end main
} // end class BlockingBufferTest