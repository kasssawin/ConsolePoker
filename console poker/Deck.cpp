#include "libs.h"

void Deck::Shuffle()
{
	for (int i = TWO; i <= ACE; i++)
	{
		for (int j = HEARTS; j <= SPADES; j++)
		{
			deck.push_back({ static_cast<Rank>(i), static_cast<Color>(j), false });
		}
	}
	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(deck.begin(), deck.end(), g);
}

std::vector<Card> Deck::GetHand(int numOfCards)
{

	std::vector<Card> cards;
	if (!deck.empty())
	{
		for (int i = 0; i < numOfCards; i++)
		{
			cards.push_back(deck.back());
			deck.pop_back();
		};
	}
	else std::cout << "Deck is empty!" << std::endl;
	return cards;
	
}

void Deck::PrintDeck()
{
	for (Card& card : deck)
	{
		std::cout << RankToText(card.rank) << " of " << ColorToText(card.color) << std::endl;
	}
}

void Deck::SETDECK_DEBUG()
{
/*	int x = 2;
	Rank y;
	for (int i = 0; i < 7; i++)
	{
		y = static_cast<Rank>(x);
		deck.push_back(Card{ y, Color::SPADES });
		x++;
	}
*/

	deck.push_back({ FOUR, SPADES });
	deck.push_back({ TWO, SPADES });
	deck.push_back({ TWO, SPADES });
	deck.push_back({ TWO, SPADES });
	deck.push_back({ SIX, SPADES });
	deck.push_back({ JACK, SPADES });
	deck.push_back({ ACE, SPADES });
}