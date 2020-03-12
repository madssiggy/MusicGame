//=============================================================================
//
// �T�E���h���� [sound.h]
//
//=============================================================================
#pragma once


#include <windows.h>
#include "xaudio2.h"						// �T�E���h�����ŕK�v


//*****************************************************************************
// �T�E���h�t�@�C��
//*****************************************************************************
typedef enum
{
	SOUND_LABEL_BGM_ALIVE,		    // BGM0
	SOUND_LABEL_BGM_FLOWER,		    // BGM1
	SOUND_LABEL_BGM_STAGE_SELECT,		    // BGM2
	SOUND_LABEL_SE_SHOT,		// �e���ˉ�
	SOUND_LABEL_SE_HIT,			// �q�b�g��
	SOUND_LABEL_SE_EXPLOSION,	// ������
	SOUND_LABEL_SE_DECIDE,
	SOUND_LABEL_SE_CANCEL,

	SOUND_LABEL_MAX,

} SOUND_LABEL;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
bool InitSound(HWND hWnd);
void UninitSound(void);
void PlaySound(SOUND_LABEL label);
void StopSound(SOUND_LABEL label);
void StopSound(void);