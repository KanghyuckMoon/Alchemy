#include "pch.h"
#include "Scene_Credit.h"
#include "Core.h"
#include "TimeMgr.h"
#include "TextObject.h"

Scene_Credit::Scene_Credit()
{
}

Scene_Credit::~Scene_Credit()
{
}

void Scene_Credit::Enter()
{
	textObj = new TextObject();
	textObj->SetCreditText(L"Ending\n문강혁 레전드");
	textObj->SetMoveValue(0, -0.1f);
}

void Scene_Credit::Exit()
{
}

void Scene_Credit::Update()
{

	if (time < 5.f)
	{
		textObj->Update();
		time += TimeMgr::GetInst()->GetDT();
	}
	else {
		Core::GetInst()->Close();
	}
}

void Scene_Credit::Render(HDC _dc)
{
	RECT rect;
	GetClientRect(Core::GetInst()->GetWndHandle(), &rect);
	HDC MemDC = CreateCompatibleDC(_dc);
	HBITMAP hBitmap = CreateCompatibleBitmap(_dc, 640, 480);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(MemDC, hBitmap);

	FillRect(MemDC, &rect, GetSysColorBrush(COLOR_BACKGROUND));
	BitBlt(_dc, 0, 0, rect.right, rect.bottom, MemDC, 0, 0, SRCCOPY);

	SelectObject(MemDC, hOldBitmap);

	textObj->Render(_dc);

	DeleteObject(hBitmap);
	DeleteDC(MemDC);
}
