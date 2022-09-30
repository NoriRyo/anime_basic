#include "DxLib.h"
#include <cassert>
#include "SceneMain.h"

namespace
{
	// �O���t�B�b�N�t�@�C����
	const char* const kPlayarGraphicFilename = "data/char.png";

	
	// �v���C���[�O���t�B�b�N������
	constexpr int kPlayarGraphicDivX = 3;
	constexpr int kPlayarGraphicDivY = 4;
	constexpr int kPlayarGraphicDivNum = kPlayarGraphicDivX * kPlayarGraphicDivY;

	// �v���C���[�O���t�B�b�N�T�C�Y
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

// ������
void SceneMain::init()
{
	LoadDivGraph(kPlayarGraphicFilename, kPlayarGraphicDivNum,
		kPlayarGraphicDivX, kPlayarGraphicDivY,
		kPlayarGraphicSizeX, kPlayarGraphicSizeY, m_hPlayerGraphic);

	m_player.setHandle(m_hPlayerGraphic[4]);
	m_player.init();
}

// �I������
void SceneMain::end()
{
	for (auto& handle : m_hPlayerGraphic)
	{
		DeleteGraph(m_hPlayerGraphic[4]);
	}
}

// ���t���[���̏���
void SceneMain::update()
{
	m_player.update();
}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_player.draw();
}