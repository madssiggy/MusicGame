#pragma once

#include <d3dx9.h>


typedef struct
{
	float cx, cy;	//���S���W
	float r;		//���a

}CIRCLE;

typedef struct
{
	float x, y;		//�n�_���W
	float ex, ey;	//�x�N�g�������i�I�_�j
	float r;		//���a

}CUPSULE;

typedef struct {
	float lx, rx, ly, ry;
}BOX;

void Collision_Initialize(void);
void Collision_Update(void);

void Collision_Player_vs_Enemy(void);
bool Collision_StageVsPlayer(int index);


//bool Collision_HitCheck_TileMap(D3DXVECTOR2 dst, D3DXVECTOR2* pOut);


