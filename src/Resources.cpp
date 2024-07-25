#include "Resources.h"

Resources::Resources()
{
    loadTextures();
    m_font.loadFromFile("Crackman Front.otf");
    loadSounds();
}

const sf::Texture& Resources::getTexture(TextureObject texObj) const
{
    return m_textureVec[texObj];
}

const sf::Texture& Resources::getMenuTexture(Menu_Textures texture) const
{
    return m_MenuTexture[texture];
}

const sf::Font& Resources::getFont() const
{
    return m_font;
}

Resources& Resources::instace()
{
    static Resources inst;  //static so the resources will called once
    return inst;
}

void Resources::loadSounds()
{
    m_sound.resize(Sounds::s_Total);

    m_sound[Sounds::s_Eat_cookie].loadFromFile("Eat_sound.wav");
    m_sound[Sounds::s_Pacman_dead].loadFromFile("Pacman_dead_sound.wav");
    m_sound[Sounds::s_Eat_demon].loadFromFile("Pacman_eat_demon.wav");
    m_sound[Sounds::s_Eat_gift].loadFromFile("Pacman_gift.wav");
    m_sound[Sounds::s_Eat_key].loadFromFile("Pacman_key.wav");
    m_sound[Sounds::s_Supermode].loadFromFile("Pacman_supermode.wav");
    m_sound[Sounds::s_hit_ghost].loadFromFile("Pac_hit_ghost.wav");
    m_sound[Sounds::s_Start_music].loadFromFile("Start_music.wav");
    m_sound[Sounds::s_Win_stage].loadFromFile("win_stage.wav");
    m_sound[Sounds::s_Gift].loadFromFile("Gift.wav");
}

void Resources::loadTextures()
{
    m_textureVec.resize(TextureObject::t_Total);

    m_textureVec[TextureObject::t_Door].loadFromFile("Door.png");
    m_textureVec[TextureObject::t_Ghost].loadFromFile("red_ghost1.png");
    m_textureVec[TextureObject::t_Wall].loadFromFile("Wall.png");
    m_textureVec[TextureObject::t_Pacman_r].loadFromFile("pacman_half_open_right.png");
    m_textureVec[TextureObject::t_Pacman_l].loadFromFile("pacman_half_open_left.png");
    m_textureVec[TextureObject::t_Pacman_u].loadFromFile("pacman_half_open_up.png");
    m_textureVec[TextureObject::t_Pacman_d].loadFromFile("pacman_half_open_down.png");
    m_textureVec[TextureObject::t_SPacman_r].loadFromFile("Super_right.png");
    m_textureVec[TextureObject::t_SPacman_l].loadFromFile("Super_left.png");
    m_textureVec[TextureObject::t_SPacman_u].loadFromFile("Super_up.png");
    m_textureVec[TextureObject::t_SPacman_d].loadFromFile("Super_down.png");

    m_textureVec[TextureObject::t_Cookie].loadFromFile("Cookie.png");
    m_textureVec[TextureObject::t_Key].loadFromFile("Key.png");
    m_textureVec[TextureObject::t_Ghost_r].loadFromFile("blue_ghost1.png");
    m_textureVec[TextureObject::t_Ghost_o].loadFromFile("orange_ghost1.png");
    m_textureVec[TextureObject::t_Ghost_fr].loadFromFile("dead_ghost2.png");
    m_textureVec[TextureObject::t_Dead_ghost].loadFromFile("dead_ghost.png");
    m_textureVec[TextureObject::t_LifeGift].loadFromFile("LifeGift.png");
    m_textureVec[TextureObject::t_TimeGift].loadFromFile("TimeGift.png");
    m_textureVec[TextureObject::t_FreezeGift].loadFromFile("FreezeGift.png");
    m_textureVec[TextureObject::t_SuperGift].loadFromFile("Super_gift.png");

    m_MenuTexture.resize(Menu_Textures::t_Total);

    m_MenuTexture[Menu_Textures::t_Back].loadFromFile("Menu_Back.png");

    m_MenuTexture[Menu_Textures::t_Backround].loadFromFile("menu.png");

    m_MenuTexture[Menu_Textures::t_Exit].loadFromFile("Menu_EXIT.png");
    m_MenuTexture[Menu_Textures::t_Play].loadFromFile("Menu_play.png");
    m_MenuTexture[Menu_Textures::t_Help].loadFromFile("Menu_Help.png");
    m_MenuTexture[Menu_Textures::t_helpBackround].loadFromFile("helpbackground.png");
    m_MenuTexture[Menu_Textures::t_Win].loadFromFile("YOUWIN.png");
    m_MenuTexture[Menu_Textures::t_Loose].loadFromFile("GameOver.png");
    
}


sf::SoundBuffer& Resources::getSound(Sounds sound)
{
    return m_sound[sound];
}




