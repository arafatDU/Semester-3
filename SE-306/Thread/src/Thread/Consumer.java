package Thread;

import java.util.Random;

public class Consumer implements Runnable
{
private final static Random generator = new Random();
private final Buffer sharedLocation; // reference to shared object

// constructor
public Consumer( Buffer shared )
{
sharedLocation = shared;
} // end Consumer constructor

// read sharedLocation&#39;s value 10 times and sum the values
public void run()
{
int sum = 0;

for ( int count = 1; count <= 10; count++ )
{
// sleep 0 to 3 seconds, read value from buffer and add to sum
try
{
Thread.sleep( generator.nextInt( 3000 ) );
sum += sharedLocation.get();
System.out.printf( "\t\t\t%2d\n", sum );
} // end try
// if lines 26 or 27 get interrupted, print stack trace
catch ( InterruptedException exception )
{
exception.printStackTrace();
} // end catch
} // end for

System.out.printf( "\n%s %d\n%s\n",
"Consumer read values totaling", sum, "Terminating Consumer" );
} // end method run
} // end class Consumer