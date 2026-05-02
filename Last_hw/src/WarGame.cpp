#include "WarGame.h"

#include <iostream>
#include <memory>
#include <utility>

WarGame::WarGame(Deck deck, const std::string& outputPath)
    : round_(1), writer_(outputPath) {
    std::pair<Deck, Deck> halves = deck.split();
    playerA_ = std::move(halves.first);
    playerB_ = std::move(halves.second);
}

void WarGame::play() {
    std::cout << "Starting War\n";

    while (!playerA_.empty() && !playerB_.empty()) {
        std::cout << "Round " << round_ << "\n";
        playRound();
        writer_.writeRound(round_, playerA_, playerB_);
        ++round_;
    }

    std::cout << "Game Over\n";

    if (playerA_.size() > playerB_.size()) {
        std::cout << "Player A wins with " << playerA_.size() << " cards!\n";
    } else if (playerB_.size() > playerA_.size()) {
        std::cout << "Player B wins with " << playerB_.size() << " cards!\n";
    } else {
        std::cout << "It's a tie!\n";
    }
}

void WarGame::playRound() {
    std::unique_ptr<Card> cardA = playerA_.draw();
    std::unique_ptr<Card> cardB = playerB_.draw();

    if (!cardA || !cardB) {
        return;
    }

    std::cout << "Player A plays: " << *cardA << "\n";
    std::cout << "Player B plays: " << *cardB << "\n";

    // A wins if B <= A
    if (!(*cardA < *cardB)) {
        playerA_.addToBottom(std::move(cardA));
        playerA_.addToBottom(std::move(cardB));
    } else {
        playerB_.addToBottom(std::move(cardB));
        playerB_.addToBottom(std::move(cardA));
    }
}