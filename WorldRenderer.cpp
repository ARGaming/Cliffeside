#include "WorldRenderer.h"

WorldRenderer::WorldRenderer(const std::string fileName)
{
    bgtxtr.loadFromFile(fileName);
    bgtxtr.setSmooth(true);
    bg.setTexture(bgtxtr);
    bg.setScale(1.6, 1.6);

}

void WorldRenderer::draw(sf::RenderTarget& target)
{
    target.draw(bg);
}
