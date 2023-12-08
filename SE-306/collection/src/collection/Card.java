package collection;

// Using algorithm shuffle.
import java.util.List;
import java.util.Arrays;
import java.util.Collections;

// class to represent a Card in a deck of cards
public class Card
{
public static enum Face { Ace, Deuce, Three, Four, Five, Six,
Seven, Eight, Nine, Ten, Jack, Queen, King };
public static enum Suit { Clubs, Diamonds, Hearts, Spades };

private final Face face; // face of card
private final Suit suit; // suit of card

// two-argument constructor
public Card( Face cardFace, Suit cardSuit )
{
face = cardFace; // initialize face of card
suit = cardSuit; // initialize suit of card
} // end two-argument Card constructor

// return face of the card
public Face getFace()
{
return face;
} // end method getFace
// return suit of Card
public Suit getSuit()
{
return suit;
} // end method getSuit

// return String representation of Card
public String toString()
{
return String.format( "%s of %s", face, suit );
} // end method toString
} // end class Card