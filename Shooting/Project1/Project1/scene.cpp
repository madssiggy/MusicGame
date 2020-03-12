#include "scene.h"



static SCENE_INDEX g_SceneIndex;
static SCENE_INDEX g_SceneNextIndex;

typedef void (*SceneFunc)(void);

static const SceneFunc Initialize[] = {
	InitTitle,
	InitStageSelect,
	InitGame,
	InitResult,
};


void Scene_Initialize(SCENE_INDEX index)
{
	g_SceneNextIndex = g_SceneIndex = index;
	
	Initialize[g_SceneIndex]();
}

void Scene_Finalize(void)
{
	switch( g_SceneIndex ) {

	case SCENE_INDEX_TITLE:
		UninitTitle();
		break;
	case SCENE_INDEX_SELECT_STAGE:
		UninitStageSelect();
		break;
	case SCENE_INDEX_GAME:
		UninitGame();
		break;

	case SCENE_INDEX_RESULT:
		UninitResult();
		break;
	}
}

void Scene_Update(void)
{
	switch( g_SceneIndex ) {

	case SCENE_INDEX_TITLE:
		UpdateTitle();
		break;
	case SCENE_INDEX_SELECT_STAGE:
		UpdateStageSelect();
		break;
	case SCENE_INDEX_GAME:
		UpdateGame();
		break;

	case SCENE_INDEX_RESULT:
		UpdateResult();
		break;
	}
}

void Scene_Draw(void)
{
	switch( g_SceneIndex ) {

	case SCENE_INDEX_TITLE:
		DrawTitle();
		break;
	case SCENE_INDEX_SELECT_STAGE:
		DrawStageSelect();
		break;
	case SCENE_INDEX_GAME:
		DrawGame();
		break;

	case SCENE_INDEX_RESULT:
		DrawResult();
		break;
	}
}

void Scene_Check(void)
{
	if( g_SceneIndex != g_SceneNextIndex ) {
		Scene_Finalize();
		Scene_Initialize(g_SceneNextIndex);
	}
}

void Scene_Change(SCENE_INDEX index)
{
	g_SceneNextIndex = index;
}

