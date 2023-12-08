package collection;

// Program to test java.util.Stack.
import java.util.Stack;
import java.util.EmptyStackException;

public class StackTest
{
public StackTest()
{
Stack< Number > stack = new Stack< Number >();

// create numbers to store in the stack
Long longNumber = 12L;
Integer intNumber = 34567;
Float floatNumber = 1.0F;
Double doubleNumber = 1234.5678;

// use push method
stack.push( longNumber ); // push a long
printStack( stack );
stack.push( intNumber ); // push an int
printStack( stack );
stack.push( floatNumber ); // push a float
printStack( stack );
stack.push( doubleNumber ); // push a double
printStack( stack );
// remove items from stack
try
{
Number removedObject = null;

// pop elements from stack
while ( true )
{
removedObject = stack.pop(); // use pop method
System.out.printf( "%s popped\n", removedObject );
printStack( stack );
} // end while
} // end try
catch ( EmptyStackException emptyStackException )
{
emptyStackException.printStackTrace();
} // end catch
} // end StackTest constructor

private void printStack( Stack< Number > stack )
{
if ( stack.isEmpty() )
System.out.print( "stack is empty\n\n" ); // the stack is empty
else // stack is not empty
{
System.out.print( "stack contains: " );
// iterate through the elements
for ( Number number : stack )
System.out.printf( "%s ", number );

System.out.print( "(top) \n\n" ); // indicates top of the stack
} // end else
} // end method printStack

public static void main( String args[] )
{
new StackTest();
} // end main
} // end class StackTest