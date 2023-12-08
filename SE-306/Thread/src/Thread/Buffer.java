package Thread;

public interface Buffer
{
// place int value into Buffer
public void set( int value ) throws InterruptedException;

// return int value from Buffer
public int get() throws InterruptedException;
} // end interface Buffer