#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "ConstAndEnum.h"


class Resources
{
public:
	
	enum TextureObject
	{
		t_Pacman_r,
		t_Pacman_l,
		t_Pacman_u,
		t_Pacman_d,
		t_SPacman_r,
		t_SPacman_l,
		t_SPacman_u,
		t_SPacman_d,
		t_Ghost,
		t_Ghost_r,
		t_Ghost_o,
		t_Wall,
		t_Door,
		t_Cookie,
		t_Key,
		t_LifeGift,
		t_TimeGift,
		t_FreezeGift,
		t_SuperGift,
		t_Ghost_fr,
		t_Dead_ghost,
		// Add other...

		t_Total
	};

	enum Sounds
	{
		s_Eat_cookie,
		s_Pacman_dead,
		s_Eat_demon,
		s_Eat_gift,
		s_Eat_key,
		s_Supermode,
		s_hit_ghost,
		s_Start_music,
		s_Win_stage,
		s_Gift,
		// Add other...

		s_Total
	};


	~Resources() = default;
	const sf::Texture& getTexture(TextureObject texObj) const;
	const sf::Texture& getMenuTexture(Menu_Textures texture) const;
	const sf::Font& getFont() const;
	sf::SoundBuffer& getSound(Sounds sound);
	

	static Resources& instace(); //static so the resources will called once

private:
	Resources(); //private so there will be no duplicates
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;
	void loadSounds();

	void loadTextures();

	//sf::SoundBuffer m_sound;
	

	std::vector<sf::Texture> m_textureVec;
	std::vector<sf::Texture> m_MenuTexture;
	std::vector<sf::SoundBuffer> m_sound;
	sf::Font m_font;

};

