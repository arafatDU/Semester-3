package Thread;

import java.util.concurrent.ArrayBlockingQueue;

public class BlockingBuffer implements Buffer
{
private final ArrayBlockingQueue<Integer> buffer; // shared buffer

public BlockingBuffer()
{
buffer = new ArrayBlockingQueue<Integer>( 1 );
} // end BlockingBuffer constructor

// place value into buffer
public void set( int value ) throws InterruptedException
{
buffer.put( value ); // place value in buffer
System.out.printf( "%s%2d\t%s%d\n", "Producer writes ", value,
"Buffer cells occupied: ", buffer.size() );
} // end method set
// return value from buffer
public int get() throws InterruptedException
{
int readValue = 0; // initialize value read from buffer

readValue = buffer.take(); // remove value from buffer
System.out.printf( "%s %2d\t%s%d\n", "Consumer reads ",
readValue, "Buffer cells occupied: ", buffer.size() );

return readValue;
} // end method get
} // end class BlockingBuffer