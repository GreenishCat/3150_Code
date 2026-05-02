#include "FaceCard.h"
#include <ostream>
#include <string>

FaceCard::FaceCard(const std::string& suit, int rank)
    : PlayingCard(suit, rank) {}

void FaceCard::print(std::ostream& os) const {
    switch (rank_) {
        case 11:
            os << "Jack of " << suit_;
            break;
        case 12:
            os << "Queen of " << suit_;
            break;
        case 13:
            os << "King of " << suit_;
            break;
        default:
            os << rankToString(rank_) << " of " << suit_;
            break;
    }
}