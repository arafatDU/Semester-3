package collection;

import java.util.List;
import java.util.Arrays;
import java.util.Collections;

// class DeckOfCards declaration
public class DeckOfCards
{
private List< Card > list; // declare List that will store Cards

// set up deck of Cards and shuffle
public DeckOfCards()
{
Card[] deck = new Card[ 52 ];
int count = 0; // number of cards
// populate deck with Card objects
for ( Card.Suit suit : Card.Suit.values() )
{
for ( Card.Face face : Card.Face.values() )
{
deck[ count ] = new Card( face, suit );
count++;
} // end for
} // end for

list = Arrays.asList( deck ); // get List
Collections.shuffle( list ); // shuffle deck
} // end DeckOfCards constructor

// output deck
public void printCards()
{
// display 52 cards in two columns
for ( int i = 0; i < list.size(); i++ )
System.out.printf( "%-20s%s", list.get( i ),
( ( i + 1 ) % 2 == 0 ) ? "\n" : "\t" );
} // end method printCards

public static void main( String args[] )
{
DeckOfCards cards = new DeckOfCards();
cards.printCards();
} // end main
} // end class DeckOfCards
