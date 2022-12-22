#include "pch.h"
#include "ItemCaptionWindow.h"
#include "Background.h"
#include "ItemData.h"
#include "ItemSO.h"
ItemCaptionWindow::ItemCaptionWindow()
{
	background = new Background(L"ButtonImage640-32", L"Image\\Background\\ButtonImage640-32.bmp");
	background->SetScale(Vec2(320, 32));
	background->SetPos(Vec2(320, 350));
	background->SetImageSize(Vec2(640, 32));
	originBackgroundPos = Vec2(320, 350);

}

ItemCaptionWindow::~ItemCaptionWindow()
{
}

void ItemCaptionWindow::SetItemData(const wstring& key)
{
	if (key != L"")
	{
		m_caption = ItemSO::GetInst()->GetItemData(key)->GetText();
	}
	else
	{
		m_caption = L"";
		background->SetPos(Vec2(320, 480));
	}
}

void ItemCaptionWindow::Update()
{
}

void ItemCaptionWindow::Render(HDC _dc)
{
	if (m_caption != L"")
	{
		if (originBackgroundPos.y < background->GetPos().y)
		{
			background->SetPos(Vec2(320.f, background->GetPos().y - 5.f));
		}

		background->Render(_dc);
		TextOutW(_dc, background->GetPos().x - background->GetScale().x / 2 + 20, background->GetPos().y - 5, m_caption.c_str(), m_caption.length());
	}
}
