#include <d3dx9.h>
//#include "debugPrintf.h"
#include "mydirect3d.h"
#include "texture.h"

#define TEXTURE_FILENAME_MAX (64)


typedef struct TextureFile_tag
{
	char filename[TEXTURE_FILENAME_MAX];
	int width;
	int height;
} TextureFile;

static const TextureFile g_TextureFiles[] = {
    { "asset/texture/bird.png", 128, 193 },
	{ "asset/texture/bullet00.png", 32, 32 },
	{ "asset/texture/bullet01.png", 32, 32 },
	{ "asset/texture/bullets00.png", 256, 256 },
	{ "asset/texture/exp.png", 128, 128 },
	{ "asset/texture/number.tga", 320, 32 },
	{ "asset/texture/TITLE.png", 499, 243 },
	{"asset/texture/TITLE_FULLSIZE.png",500,500},
	{ "asset/texture/FLOWER.png", 500, 500 },
	{ "asset/texture/ALIVE.png", 500, 500 },
	{ "asset/texture/result.png", 1024, 576 },
	{ "asset/texture/kokosozai.png", 512, 512 },
	{ "asset/texture/SELECT.png", 500, 500 },
	{ "asset/texture/START.png", 500, 500 },
	{ "asset/texture/bg_matsushima.jpg", 600, 213 },
	{"asset/texture/impact.png",778,775},
	{"asset/texture/shock.png",288,355},
	{ "asset/texture/EnemyFlower1.png", 501, 501 },


};

static const int TEXTURE_FILE_COUNT = sizeof(g_TextureFiles) / sizeof(g_TextureFiles[0]);

static_assert(TEXTURE_INDEX_MAX == TEXTURE_FILE_COUNT, "TEXTURE_INDEX_MAX != TEXTURE_FILE_COUNT");

static LPDIRECT3DTEXTURE9 g_pTextures[TEXTURE_FILE_COUNT] = {};

int Texture_Load(void)
{   
    LPDIRECT3DDEVICE9 pDevice = GetD3DDevice();
	if( !pDevice ) {
		return TEXTURE_FILE_COUNT;
	}

	int failed_count = 0;

	for( int i = 0; i < TEXTURE_FILE_COUNT; i++ ) {
		
		if( FAILED(D3DXCreateTextureFromFile(pDevice, g_TextureFiles[i].filename, &g_pTextures[i])) ) {
            // DebugPrintf("テクスチャの読み込みに失敗 ... %s\n", g_TextureFiles[i].filename);
			failed_count++;
		}
	}

	return failed_count;
}

void Texture_Release(void)
{
	for( int i = 0; i < TEXTURE_FILE_COUNT; i++ ) {
		
		if( g_pTextures[i] ) {
			g_pTextures[i]->Release();
			g_pTextures[i] = NULL;
		}
	}
}

LPDIRECT3DTEXTURE9 Texture_GetTexture(TextureIndex index)
{
    if( index < 0 || index >= TEXTURE_INDEX_MAX ) {
        return NULL;
    }

	return g_pTextures[index];
}

int Texture_GetWidth(TextureIndex index)
{
    if( index < 0 || index >= TEXTURE_INDEX_MAX ) {
        return NULL;
    }

	return g_TextureFiles[index].width;
}

int Texture_GetHeight(TextureIndex index)
{
    if( index < 0 || index >= TEXTURE_INDEX_MAX ) {
        return NULL;
    }

	return g_TextureFiles[index].height;
}
