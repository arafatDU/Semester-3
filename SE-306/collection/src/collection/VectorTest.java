package collection;

// Using the Vector class.
import java.util.Vector;
import java.util.NoSuchElementException;

public class VectorTest {
	private static final String colors[] = { "red", "white", "blue" };

	public VectorTest() {
		Vector<String> vector = new Vector<String>();
		printVector(vector); // print vector

// add elements to the vector
		for (String color : colors)
			vector.add(color);

		printVector(vector); // print vector
// output the first and last elements
		try {
			System.out.printf("First element: %s\n", vector.firstElement());
			System.out.printf("Last element: %s\n", vector.lastElement());
		} // end try
// catch exception if vector is empty
		catch (NoSuchElementException exception) {
			exception.printStackTrace();
		} // end catch

// does vector contain "red"?
		if (vector.contains("red"))
			System.out.printf("\n\"red\" found at index %d\n\n", vector.indexOf("red"));
		else
			System.out.println("\n\"red\" not found\n");

		vector.remove("red"); // remove the string "red"
		System.out.println("\"red\" has been removed");
		printVector(vector); // print vector
// does vector contain "red" after remove operation?
		if (vector.contains("red"))
			System.out.printf("\"red\" found at index %d\n", vector.indexOf("red"));
		else
			System.out.println("\"red\" not found");

// print the size and capacity of vector
		System.out.printf("\nSize: %d\nCapacity: %d\n", vector.size(), vector.capacity());
	} // end Vector constructor

	private void printVector(Vector<String> vectorToOutput) {
		if (vectorToOutput.isEmpty())
			System.out.print("vector is empty"); // vectorToOutput is empty
		else // iterate through the elements
		{
			System.out.print("vector contains: ");

// output elements
			for (String element : vectorToOutput)
				System.out.printf("%s ", element);
		} // end else
		System.out.println("\n");
	} // end method printVector

	public static void main(String args[]) {
		new VectorTest(); // create object and call its constructor
	} // end main
} // end class VectorTest
