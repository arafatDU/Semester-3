package exceptionhandling;

//class representing custom exception  
class InvalidAgeException extends Exception {
	public InvalidAgeException(String str) {
		// calling the constructor of parent Exception
		super(str);
	}
}