#ifndef MULTI_DRAWABLE
#define MULTI_DRAWABLE
#include "strategy.h"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <vector>

class MultiDrawable : public sf::Drawable/*a MultiDrawable can be in toDraw of another MultiDrawable*/, public virtual Strategy {
private:
    std::vector<sf::Drawable*> toDraw; //list of sprites/shapes to draw
    //!!! big question on the best way to store Sprites ? and on the poointer and freeing...
public:
    void draw(sf::RenderTarget& target/*often the window where to draw*/, sf::RenderStates states/*shader or other*/);
    void addSprite(sf::Drawable);//called addSprite but can add any sf::Drawable
    MultiDrawable(std::vector<sf::Drawable*>);
    MultiDrawable(sf::Drawable);
    MultiDrawable();
    ~MultiDrawable();
};

#endif