package Thread;

// UnsynchronizedBuffer maintains the shared integer that is accessed by
// a producer thread and a consumer thread via methods set and get.
public class UnsynchronizedBuffer implements Buffer
{
private int buffer = -1; // shared by producer and consumer threads

// place value into buffer
public void set( int value ) throws InterruptedException
{
System.out.printf( "Producer writes\t%2d", value );
buffer = value;
} // end method set

// return value from buffer
public int get() throws InterruptedException
{
System.out.printf( "Consumer reads\t%2d", buffer );
return buffer;
} // end method get
} // end class UnsynchronizedBuffer