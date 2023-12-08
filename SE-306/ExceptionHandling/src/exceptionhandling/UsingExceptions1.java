package exceptionhandling;

public class UsingExceptions1 {
	public static void main(String args[]) {
		try // call throwException to demonstrate stack unwinding
		{
			throwException();
		} // end try
		catch (Exception exception) // exception thrown in throwException
		{
			System.err.println("Exception handled in main");
		} // end catch
	} // end main
// throwException throws exception that is not caught in this method

	public static void throwException() throws Exception {
		try // throw an exception and catch it in main
		{
			System.out.println("Method throwException");
			throw new Exception(); // generate exception
		} // end try
		catch (RuntimeException runtimeException) // catch incorrect type
		{
			System.err.println("Exception handled in method throwException");
		} // end catch
		finally // finally block always executes
		{
			System.err.println("Finally is always executed");
		} // end finally
	} // end method throwException
} // end class UsingExceptions1