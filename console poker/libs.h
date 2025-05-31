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

class Deck
{
private:
	std::vector<Card> deck;
public:
	void Shuffle();
	std::vector<Card> GetHand(int numOfCards);
	void PrintDeck();
	std::vector<Card> GetDeckVec();

	void SETDECK_DEBUG();
};

class Player
{
private:
	std::vector<Card> Cards{};    //first is rank second is color
	Hand playerHand{};
	std::string name{};
	int id;
public:
	Player(std::string nickname) { name = nickname; }
	
	void GetPlayerCards(Deck& deck);

	void GetPlayerBestHand(std::vector<Card> tableCards);

	void PrintPlayerCards();

	void PrintPlayerBestHand();

	std::vector<Card> GETPLAYERCARDS();

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

class EntList
{
private:
	std::vector<Player*> player;

public:
	void AddPlayer(std::string nickname)
	{
		Player* p = new Player(nickname);
		player.push_back(p);
	}
	Player* GetPlayer(int id)
	{
		return player[id];
	}
	std::vector<Player*> GetVector()
	{
		return player;
	}
};

