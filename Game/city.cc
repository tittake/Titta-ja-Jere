#include "city.hh"
#include <QTime>
#include "main.cc"

namespace Interface
{

City::City() : Interface::ICity()
{

}

void City::setBackground(QImage &basicbackground, QImage &bigbackground)
{
    try {
        basicbackground_ = basicbackground;
        bigbackground_ = bigbackground;
    }

     catch (...) {
        InitError badpic("Setting the picture was unsuccesful or the picture was invalid.");
        throw badpic;
    }

    return;
}

void City::setClock(QTime clock)
{
    return;
}

void City::addStop(std::shared_ptr<IStop> stop)
{
    return;
}

void City::startGame()
{
    return;
}

void City::addActor(std::shared_ptr<IActor> newactor)
{
    return;
}

void City::removeActor(std::shared_ptr<IActor> actor)
{
    return;
}

void City::actorRemoved(std::shared_ptr<IActor> actor)
{
    return;
}

bool City::findActor(std::shared_ptr<IActor> actor) const
{
    return false;
}

void City::actorMoved(std::shared_ptr<IActor> actor)
{
    return;
}

std::vector<std::shared_ptr<IActor> > City::getNearbyActors(Location loc) const
{
    std::vector<std::shared_ptr<IActor>> nearBy;
    return nearBy;
}

bool City::isGameOver() const
{
    return false;
};

}
