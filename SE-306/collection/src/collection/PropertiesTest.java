package collection;

// Demonstrates class Properties of the java.util package.
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;
import java.util.Set;

public class PropertiesTest
{
private Properties table;

// set up GUI to test Properties table
public PropertiesTest()
{
table = new Properties(); // create Properties table

// set properties
table.setProperty( "color", "blue" );
table.setProperty( "width", "200" );

System.out.println( "After setting properties" );
listProperties(); // display property values

// replace property value
table.setProperty( "color", "red" );
System.out.println( "After replacing properties" );
listProperties(); // display property values

saveProperties(); // save properties

table.clear(); // empty table

System.out.println( "After clearing properties" );
listProperties(); // display property values

loadProperties(); // load properties

// get value of property color
Object value = table.getProperty( "color" );

// check if value is in table
if ( value != null )
System.out.printf( "Property color's value is %s\n", value );
else
System.out.println( "Property color is not in table" );
} // end PropertiesTest constructor
// save properties to a file
public void saveProperties()
{
// save contents of table
try
{
FileOutputStream output = new FileOutputStream( "props.dat" );
table.store( output, "Sample Properties" ); // save properties
output.close();
System.out.println( "After saving properties" );
listProperties();
} // end try
catch ( IOException ioException )
{
ioException.printStackTrace();
} // end catch
} // end method saveProperties
// load properties from a file
public void loadProperties()
{
// load contents of table
try
{
FileInputStream input = new FileInputStream( "props.dat" );
table.load( input ); // load properties
input.close();
System.out.println( "After loading properties" );
listProperties(); // display property values
} // end try
catch ( IOException ioException )
{
ioException.printStackTrace();
} // end catch
} // end method loadProperties

// output property values
public void listProperties()
{
Set< Object > keys = table.keySet(); // get property names

// output name/value pairs
for ( Object key : keys )
{
System.out.printf(
"%s\t%s\n", key, table.getProperty( ( String ) key ) );
} // end for
System.out.println();
} // end method listProperties

public static void main( String args[] )
{
new PropertiesTest();
} // end main
} // end class PropertiesTest