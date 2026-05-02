#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H
#include "Card.h"
#include <string>

class PlayingCard : public Card {
protected:
    std::string suit_;
    int rank_;

    std::string rankToString(int rank) const;

public:
    PlayingCard(const std::string& suit, int rank);

    int value() const override;
    void print(std::ostream& os) const override;
};

#endif