
#include"Dxlib.h"      //DxLib���C�u�������g�p����
#include"main.h"
#include"effect.h"
//�萔�̒�`
#define SCREEN_SIZE_X 640
#define SCREEN_SIZE_Y 680
#define PLAYER_SIZE_X 32
#define PLAYER_SIZE_Y 32

int gameCounter;


SCENE sceneID;
SCENE preSceneID;
SCENE systemScene;
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	if (!SystemInit())
	{
		return -1;
	}
	//�������Ăяo��
	SystemInit();
	//�ϐ�������
	//�������Ăяo��
	//�Q�[�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//���C������
		ClsDrawScreen();//��ʏ���

		if (sceneID != preSceneID)
		{
			preSceneID = sceneID;
		}
		switch(sceneID)
		{
		case SCENE_INIT:
			InitScene();
			break;
		case SCENE_TITLE:
			if (fadeIn)
			{
				if (!FadeInScene(5)) {}
			}
			else if (fadeOut)
			{
				if (!FadeOutScene(5))
				{
					sceneID = SCENE_GAME;
					fadeIn = true;
				}
			}
			TitleScene();
			break;
		case SCENE_GAME:
			if (fadeIn)
			{
				if (!FadeInScene(5)) {}
			}
			else if (fadeOut)
			{
				if (!FadeOutScene(5))
				{
					sceneID = SCENE_WIN;
					fadeIn = true;
				}
			}
			GameScene();
			break;
		case SCENE_WIN:
			if (fadeIn)
			{
				if (!FadeInScene(5)) {}
			}
			else if (fadeOut)
			{
				if (!FadeOutScene(5))
				{
					sceneID = SCENE_GAMEOVER;
					fadeIn = true;
				}
			}
			GameWinsScene();
			break;
		case SCENE_GAMEOVER:
			if (fadeIn)
			{
				if (!FadeInScene(5)) {}
			}
			else if (fadeOut)
			{
				if (!FadeOutScene(5))
				{
					sceneID = SCENE_INIT;
					fadeIn = true;
				}
			}
			GameOverScene();
			break;
		default:
			return -1;
			break;
		}



		gameCounter++;

		ScreenFlip();//����ʂ�\��ʂɏu�ԃR�s�[
	}
	DxLib_End();
	return 0;
}

bool SystemInit(void)
{
	//SetWindowText("1916038_������");
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)
	{
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);

	
	
	sceneID = SCENE_INIT;
	return true;
}
//�������V�[��
void InitScene(void)
{
	EffectInit();
	preSceneID = SCENE_MAX;
	sceneID = SCENE_TITLE;

}
//�^�C�g���V�[��
void TitleScene(void)
{
	TitleDraw();



	if (CheckHitKey(KEY_INPUT_SPACE)== 0)
	{
		sceneID = SCENE_GAME;
	}

}
void TitleDraw(void)
{
	//�^�C�g���`��n



	DrawCircle(100, 100, 80, GetColor(50, 50, 50), true);

}
//�Q�[���V�[��
void GameScene(void)
{


	if (CheckHitKey(KEY_INPUT_SPACE) == 0)
	{
		sceneID = SCENE_GAMEOVER;
	}

}
void GameDraw(void)
{
	//�Q�[����ʕ`��







}
//�������
void GameWinsScene(void)
{




}
void GameWinsDraw(void)
{




}
//�Q�[���I�[�o�[�V�[��
void GameOverScene(void)
{



	if (CheckHitKey(KEY_INPUT_SPACE) == 0)
	{
		sceneID = SCENE_INIT;
	}
}
void GameOverDraw(void)
{
	//�Q�[���I�[�o�[��ʕ`��



}