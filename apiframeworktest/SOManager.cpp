#include "pch.h"
#include "SOManager.h"
#include "ScriptableObject.h"
#include "ItemSO.h"
#include "TextSO.h"
#include "SpriteSO.h"

void SOManager::Init()
{
	TextSO::Init();
	SpriteSO::Init();
	ItemSO::Init();
}
