#include "libs.h"




int main()
{
	Dealer dealer;
	Player PlayerOne("kassawin");
	Player PlayerTwo("Bot 1");
	Deck deck;
	deck.Shuffle();
	//deck.SETDECK_DEBUG();

	PlayerOne.GetPlayerCards(&deck);
	PlayerOne.PrintPlayerCards();
	std::cout << std::endl;

	PlayerTwo.GetPlayerCards(&deck);
	PlayerTwo.PrintPlayerCards();

	dealer.GetDealerHand(&deck);
	dealer.PrintDealerHand();

	PlayerOne.GetPlayerBestHand(dealer.GETDEALERCARDS());
	PlayerOne.PrintPlayerBestHand();
	PlayerTwo.GetPlayerBestHand(dealer.GETDEALERCARDS());
	PlayerTwo.PrintPlayerBestHand();
	while (true)
	{	
		std::cin.get();
	}
}

int GetRandomRank(Rank min, Rank max)
{
	std::random_device random;
	std::mt19937 gen(random());
	std::uniform_int_distribution<int> dist(min, max);
	
	return dist(gen);
}

int GetRandomColor(Color min, Color max)
{
	std::random_device random;
	std::mt19937 gen(random());
	std::uniform_int_distribution<int> dist(min, max);

	return dist(gen);
}

std::string RankToText(Rank rank)
{
	switch (rank) {
	case Rank::TWO:   return "Two";
	case Rank::THREE: return "Three";
	case Rank::FOUR:  return "Four";
	case Rank::FIVE:  return "Five";
	case Rank::SIX:   return "Six";
	case Rank::SEVEN: return "Seven";
	case Rank::EIGHT: return "Eight";
	case Rank::NINE:  return "Nine";
	case Rank::TEN:   return "Ten";
	case Rank::JACK:  return "Jack";
	case Rank::QUEEN: return "Queen";
	case Rank::KING:  return "King";
	case Rank::ACE:   return "Ace";
	default: return "Unknown";
	}
}
std::string ColorToText(Color color)
{
	switch (color)
	{
	case HEARTS:     return "Hearts";
	case DIAMONDS:	 return "Diamonds";
	case CLUBS:		 return "Clubs";
	case SPADES:	 return "Spades";
	default:		 return "Unknown";
	}
};

std::string PokerHandToText(Hand hand)
{
	switch (hand)
	{
	case POKER_FLUSH:			return "Poker Flush";
	case STRAIGHT_FLUSH:		return "Straight Flush";
	case FOUR_OF_KIND:			return "Four Of Kind";
	case FULLHOUSE:				return "Full House";
	case FLUSH:					return "Flush";
	case STRAIGHT:				return "Straight";
	case THREE_OF_KIND:			return "Three Of Kind";
	case TWO_PAIR:				return "Two Pairs";
	case PAIR:					return "Pair";
	case HIGH_CARD:				return "High Card";
	default:					return "Unknown";
	}
};