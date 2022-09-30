#include "DxLib.h"
#include <cassert>
#include "SceneMain.h"

namespace
{
	// グラフィックファイル名
	const char* const kPlayarGraphicFilename = "data/char.png";

	
	// プレイヤーグラフィック分割数
	constexpr int kPlayarGraphicDivX = 3;
	constexpr int kPlayarGraphicDivY = 4;
	constexpr int kPlayarGraphicDivNum = kPlayarGraphicDivX * kPlayarGraphicDivY;

	// プレイヤーグラフィックサイズ
	constexpr int kPlayarGraphicSizeX = 32;
	constexpr int kPlayarGraphicSizeY = 32;

}

SceneMain::SceneMain()
{
	for (auto& handle : m_hPlayerGraphic)
	{
		handle = -1;
	}
}
SceneMain::~SceneMain()
{

}

// 初期化
void SceneMain::init()
{
	LoadDivGraph(kPlayarGraphicFilename, kPlayarGraphicDivNum,
		kPlayarGraphicDivX, kPlayarGraphicDivY,
		kPlayarGraphicSizeX, kPlayarGraphicSizeY, m_hPlayerGraphic);

	m_player.setHandle(m_hPlayerGraphic[4]);
	m_player.init();
}

// 終了処理
void SceneMain::end()
{
	for (auto& handle : m_hPlayerGraphic)
	{
		DeleteGraph(m_hPlayerGraphic[4]);
	}
}

// 毎フレームの処理
void SceneMain::update()
{
	m_player.update();
}

// 毎フレームの描画
void SceneMain::draw()
{
	m_player.draw();
}