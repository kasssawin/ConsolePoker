#include "libs.h"

void Player::GetPlayerCards(Deck& deck)
{
	Cards = deck.GetHand(2);
}

void Player::GetPlayerBestHand(std::vector<Card> tableCards)
{
	playerHand = CheckPokerHand(tableCards, Cards, *this);
	std::cout << name << " best hand is " << PokerHandToText(playerHand) << std::endl;
}

void Player::PrintPlayerCards()
{
	std::cout << name << " cards: " << std::endl;
	for (Card& hand : Cards)
	{
		std::cout << RankToText(hand.rank) << " of " << ColorToText(hand.color) << std::endl;
	}
	std::cout << ".....................................\n";
}

void Player::PrintPlayerBestHand()
{
	std::cout << name << " got " << PokerHandToText(playerHand) << "!!!" << std::endl;
}

std::vector<Card> Player::GETPLAYERCARDS()
{
	return Cards;
}
