package file;

public class CreateTextFileTest {
	public static void main(String args[]) {
		CreateTextFile application = new CreateTextFile();

		application.openFile();
		application.addRecords();
		application.closeFile();
	} // end main
} // end class CreateTextFileTest