#pragma once

#include <iostream>
#include <vector>
#include <random>

enum Rank
{
	TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
	JACK, QUEEN, KING, ACE
};
enum Color
{
	HEARTS = 1, DIAMONDS, CLUBS, SPADES
};

enum Hand
{
	POKER_FLUSH = 1, STRAIGHT_FLUSH, FOUR_OF_KIND, FULLHOUSE, FLUSH, STRAIGHT, THREE_OF_KIND, TWO_PAIR, PAIR, HIGH_CARD
};

struct RankBasedHand
{
	Rank rank;
	int sameRankCount;
};


struct Card
{
	Rank rank;
	Color color;
	bool visilible;
};


class Player
{
private:
	std::vector<Card> Cards{};    //first is rank second is color
	Hand playerHand{};
	std::string name{};
public:
	Player(std::string nickname) { name = nickname; }
	void GetPlayerCards(Deck* deck)
	{
		Cards = deck->GetHand(2);
	}

	void GetPlayerBestHand(std::vector<Card> tableCards)
	{
		playerHand = CheckPokerHand(tableCards, Cards, *this);
	}

	void PrintPlayerCards()
	{
		std::cout << name << " cards: " << std::endl;
		for (Card& hand : Cards)
		{
			std::cout << RankToText(hand.rank) << " of " << ColorToText(hand.color) << "   ";
		}
	}

	void PrintPlayerBestHand()
	{
		std::cout << name << " got " << PokerHandToText(playerHand) << "!!!" << std::endl;
	}

	std::vector<Card> GETPLAYERCARDS()
	{
		return Cards;
	}

};



int GetRandomRank(Rank min, Rank max);
int GetRandomColor(Color min, Color max);
std::string RankToText(Rank rank);
std::string ColorToText(Color color);
std::string PokerHandToText(Hand hand);

Hand CheckPokerHand(std::vector<Card>tableCards, std::vector<Card>playerHand, Player& player);

bool CheckRoyalFlush(std::vector<Card>& cards);
std::vector<RankBasedHand> CheckForRankHands(std::vector<Card> cards);
bool CheckStraight(std::vector<Card> cards);
bool CheckFlush(std::vector<Card> cards);

void PrintRanksPairing(std::vector<RankBasedHand>& hand);

class Deck
{
private:
	std::vector<Card> deck;
public:
	void Shuffle();
	std::vector<Card> GetHand(int numOfCards);
	void PrintDeck();

	void SETDECK_DEBUG();
};

class Dealer
{

private:
	std::vector<Card> dealerCards{};
public:

	void GetDealerHand(Deck* deck)
	{
		dealerCards = deck->GetHand(5);
	}

	void PrintDealerHand()
	{
		std::cout << "Dealer cards: " << std::endl;
		if (!dealerCards.empty())
		{
			for (Card& card : dealerCards)
			{
				std::cout << RankToText(card.rank) << " " << ColorToText(card.color) << std::endl;
			}
		}
		else
		{
			std::cout << "deck is empty";
		}
	}

	std::vector<Card> GETDEALERCARDS()
	{
		return dealerCards;
	}
};


