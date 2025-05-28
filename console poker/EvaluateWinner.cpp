#include "libs.h"




Hand CheckPokerHand(std::vector<Card>tableCards, std::vector<Card>playerHand, Player& player)		//ADD REFERENCE TO PLAYER STRUCT SO IT CAN STORE VALUE 
{																					//OF PAIRS THREES etc SO ANOTHER FUNCT CAN DECIDE 
	std::vector<Card> pokerHand;													//WHAT PAIR IS STRONGER!!!!
	pokerHand.insert(pokerHand.end(), tableCards.begin(), tableCards.end());
	pokerHand.insert(pokerHand.end(), playerHand.begin(), playerHand.end());		//idea is to make std::vector<Card> with usefull cards
																					//and compare it with others if they have same hand

	bool flush = false;
	bool straight = false;
	if (CheckFlush(pokerHand)) { flush = true; }
	if (CheckStraight(pokerHand)) { straight = true; }

	if (flush && straight)
	{
		if (CheckRoyalFlush(pokerHand))
		{
			return POKER_FLUSH;
		}
		else { return STRAIGHT_FLUSH; }
	}

	std::vector<RankBasedHand> rankHand{ CheckForRankHands(pokerHand) };
	if (rankHand.empty() == false)
	{
		bool threeOfKind = false;
		int pairs = 0;
		for (RankBasedHand& hand : rankHand)
		{
			if (hand.sameRankCount == 4) { return FOUR_OF_KIND; }
			if (hand.sameRankCount == 3) { threeOfKind = true; }
			if (hand.sameRankCount == 2) { pairs++; }
		}
		if (threeOfKind && pairs != 0) { return FULLHOUSE; }
		if (threeOfKind && (!flush && !straight)) { return THREE_OF_KIND; }
		if (pairs == 2 && (!flush && !straight)) { return TWO_PAIR; }
		if (pairs == 1 && (!flush && !straight)) { return PAIR; }
	}
	if (flush)                                                   //MOVE FLUSH AND STRAIGHTS SO PAIR WONT WIN WITH FLUSH!!!!!!!
	{																
		std::cout << "you got a flush!";
		return FLUSH;
	}
	if (straight)
	{
		std::cout << "you got a straight!";
		return STRAIGHT;
	}
	else { return HIGH_CARD; }

}

bool CheckFlush(std::vector<Card> cards)
{
	int Hearts = 0; int Diamonds = 0;int Clubs = 0; int Spades = 0;
	for (Card& card : cards)
	{
		switch (card.color)
		{
		case(HEARTS):   Hearts++; break;
		case(DIAMONDS):   Diamonds++; break;
		case(CLUBS):   Clubs++; break;
		case(SPADES):   Spades++; break;

		}
	}
	if (Hearts >= 4 || Diamonds >= 4 || Clubs >= 4 || Spades >= 4)
	{
		return true;
	}
	else { return false; }
}

bool CheckStraight(std::vector<Card> cards)
{
	std::vector<int>ranks;
	for (Card& card : cards)
	{
		ranks.push_back(card.rank);
	}
	std::sort(ranks.begin(), ranks.end());

	int streak = 0;
	for (int i = 0; i <= ranks.size() - 2; i++)
	{
		if ((ranks[i] - ranks[i + 1]) == -1)
		{
			streak++;
		}
		else
		{
			streak = 0;
		}

	}
	if (streak >= 4) { return true; }
	else { return false; }
}

bool CheckRoyalFlush(std::vector<Card>& cards)
{
	std::vector<Rank> ranks;
	for (Card& cardBuff : cards)
	{
		ranks.push_back(cardBuff.rank);
	}
	int ten = 0; int jack = 0; int queen = 0; int king = 0; int ace = 0;

	for (Rank& rank : ranks)
	{
		switch (rank)
		{
		case(TEN): ten++; break;
		case(JACK): jack++; break;
		case(QUEEN): queen++; break;
		case(KING): king++; break;
		case(ACE): ace++; break;
		default:
			break;
		}
	}
	if (ten != 0 && jack != 0 && queen != 0 && king != 0 && ace != 0)
	{
		return true;
	}
	else { return false; }
}

std::vector<RankBasedHand> CheckForRankHands(std::vector<Card> cards)
{
	std::vector<Rank> ranks;
	std::vector<RankBasedHand> hand;
	for (Card& card : cards)
	{
		ranks.push_back(card.rank);
	}
	std::sort(ranks.begin(), ranks.end());
	bool MarkAsThree = false;
	for (int i = 0; i < ranks.size(); i++)
	{
		if (i <= 3)
		{
			if (ranks[i] == ranks[i + 1] && ranks[i + 1] == ranks[i + 2] &&
				ranks[i + 2] == ranks[i + 3])
			{
				hand.push_back({ ranks[i], 4 });
				return hand;
			}
		}
		if (i <= 4)
		{
			if (ranks[i] == ranks[i + 1] && ranks[i + 1] == ranks[i + 2])
			{
				hand.push_back({ ranks[i], 3});
				i = i + 2;
			}

		}
		if (i <= 5)
		{
			if (ranks[i] == ranks[i + 1])
			{
				hand.push_back({ ranks[i], 2 });
			}
		}
	}

	return hand;
}

void PrintRanksPairing(std::vector<RankBasedHand>& hand)
{
	if (hand.empty() == false)
	{
		for (RankBasedHand& pairing : hand)
		{
			std::cout << "you got: " << pairing.rank << " times >>>>>>" << pairing.sameRankCount << std::endl;
		}
	}
	else
	{
		std::cout << "nothing pairs!!!";
	}
}

//Hand CheckBestRankBasedHand(std::vector)

