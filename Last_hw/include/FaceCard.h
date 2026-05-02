#ifndef FACECARD_H
#define FACECARD_H
#include "PlayingCard.h"
#include <string>

class FaceCard : public PlayingCard {
public:
    FaceCard(const std::string& suit, int rank);

    void print(std::ostream& os) const override;
};

#endif