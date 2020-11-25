#include "city.hh"
#include <QTime>
#include <algorithm>

namespace Game
{

City::City() : Interface::ICity()
{
    loc_.setXY(200,200);
    std::shared_ptr<Game::Restaurant> NewRestaurant = std::make_shared<Game::Restaurant>(loc_);
    restaurants_.push_back(NewRestaurant);

}

void City::setBackground(QImage &basicbackground, QImage &bigbackground)
{
    try {
        background_ = bigbackground;
    }

     catch (...) {
        Interface::InitError badpic("Setting the picture was unsuccesful or the picture was invalid.");
        throw badpic;
    }

    return;
}

void City::setClock(QTime clock)
{
    Q_ASSERT(clock.isValid() == true);
    clock_ = clock;

    return;
}

void City::addStop(std::shared_ptr<Interface::IStop> stop)
{
    stops_.push_back(stop);
}

void City::startGame()
{
    return;
}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    actors_.push_back(newactor);
}

void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    actor->remove();
}

void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{
    Q_ASSERT(actor->isRemoved() == true);

    return;
}

bool City::findActor(std::shared_ptr<Interface::IActor> actor) const
{
    auto it = std::find(actors_.begin(),actors_.end(), actor);
    if(it == actors_.end()){
        return false;
    }
    else{
        return true;
    };
}


void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{
    Q_ASSERT(std::find(actors_.begin(), actors_.end(), actor) != actors_.end());

    movedActors_.push_back(actor);

    return;
}

std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const
{
    std::vector<std::shared_ptr<Interface::IActor>> nearBy;

    for( std::shared_ptr<Interface::IActor> actor: actors_){
        if(actor->giveLocation().isClose(loc) == true){

            nearBy.push_back(actor);
        }

    }
    return nearBy;
}

bool City::isGameOver() const
{
    return false;
}

QImage City::getBackground()
{
    return background_;
}

std::vector<std::shared_ptr<Interface::IActor> > City::getActors()
{
    return actors_;
}

std::vector<std::shared_ptr<Interface::IActor> > City::getMovedActors()
{
    return movedActors_;
}

void City::clearMovedActors()
{
    movedActors_.clear();
}

std::vector<std::shared_ptr<Interface::IStop> > City::getStops()
{
    return stops_;
}

std::vector<std::shared_ptr<Restaurant> > City::getRestaurants()
{
    return restaurants_;
};

}
