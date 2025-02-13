#include "DxLib.h"
#include <cassert>
#include "game.h"
#include "player.h"

namespace
{
	// キャラクターのサイズ
	constexpr int kSizeX = 32;
	constexpr int kSizeY = 32;
	// キャラクターアニメーション1コマあたり
	constexpr int kAinmeChangeFrame = 8;

	
}

Player::Player()
{
	// 初期化
	for (auto& handle : m_handle)
	{
		handle = -1;
	}
	m_animeNo = 0;
	m_animeFrame = 0;
	m_dirNo = 0;
}

Player::~Player()
{
	
}

void Player::init()
{
	m_pos.x = Game::kScreenWidth / 2 - kSizeX / 2;
	m_pos.y = Game::kScreenHeight / 2 - kSizeY / 2;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;

	m_animeNo = 0;
	m_animeFrame = 0;
	m_dirNo = 0;
}

void Player::update()
{
	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	bool isKey = false;
	if (padState & PAD_INPUT_UP)
	{
		m_dirNo = 3;
		isKey = true;
	}
	if (padState & PAD_INPUT_DOWN)
	{
		m_dirNo = 0;
		isKey = true;
	}
	if (padState & PAD_INPUT_LEFT)
	{
		m_dirNo = 1;
		isKey = true;
	}
	if (padState & PAD_INPUT_RIGHT)
	{
		m_dirNo = 2;
		isKey = true;
	}

	// キャラクターアニメーション
	if(isKey) m_animeFrame++;
	if (m_animeFrame >= kGraphicDivX * kAinmeChangeFrame)
	{
		m_animeFrame = 0;
	}

	int tenpAnimeNo = m_animeFrame / kAinmeChangeFrame;
	m_animeNo = m_dirNo * kGraphicDivX + tenpAnimeNo;
}

void Player::draw()
{
	//DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle[m_animeNo], true);
	DrawExtendGraph(32, 32, Game::kScreenWidth - 32, Game::kScreenHeight - 32, m_handle[m_animeNo], true);
}