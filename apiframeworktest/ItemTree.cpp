#include "pch.h"
#include "ItemTree.h"
#include "ItemData.h"
#include "ItemBox.h"
#include "Inventory.h"
#include "ItemData.h"
#include "KeyMgr.h"

ItemTree::ItemTree()
{
	//1
	itemBoxs.push_back(make_shared<ItemBox>(L"����"));
	itemBoxs.at(0)->SetName(L"����");
	itemBoxs.at(0)->SetPos(Vec2(300, 400));
	itemBoxs.at(0)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"��"));
	itemBoxs.at(1)->SetName(L"��");
	itemBoxs.at(1)->SetPos(Vec2(450, 400));
	itemBoxs.at(1)->SetScale(Vec2(100, 100));

	//2
	itemBoxs.push_back(make_shared<ItemBox>(L"����"));
	itemBoxs.at(2)->SetName(L"����");
	itemBoxs.at(2)->SetPos(Vec2(150, 200));
	itemBoxs.at(2)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"������"));
	itemBoxs.at(3)->SetName(L"������");
	itemBoxs.at(3)->SetPos(Vec2(300, 200));
	itemBoxs.at(3)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"����"));
	itemBoxs.at(4)->SetName(L"����");
	itemBoxs.at(4)->SetPos(Vec2(450, 200));
	itemBoxs.at(4)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"���� �ֱ�"));
	itemBoxs.at(5)->SetName(L"���� �ֱ�");
	itemBoxs.at(5)->SetPos(Vec2(600, 200));
	itemBoxs.at(5)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"����"));
	itemBoxs.at(6)->SetName(L"����");
	itemBoxs.at(6)->SetPos(Vec2(750, 200));
	itemBoxs.at(6)->SetScale(Vec2(100, 100));

	//3
	itemBoxs.push_back(make_shared<ItemBox>(L"���� ����"));
	itemBoxs.at(7)->SetName(L"���� ����");
	itemBoxs.at(7)->SetPos(Vec2(-150, 0));
	itemBoxs.at(7)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"å"));
	itemBoxs.at(8)->SetName(L"å");
	itemBoxs.at(8)->SetPos(Vec2(0, 0));
	itemBoxs.at(8)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"ȶ��"));
	itemBoxs.at(9)->SetName(L"ȶ��");
	itemBoxs.at(9)->SetPos(Vec2(150, 0));
	itemBoxs.at(9)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"�ڽ�"));
	itemBoxs.at(10)->SetName(L"�ڽ�");
	itemBoxs.at(10)->SetPos(Vec2(600, 0));
	itemBoxs.at(10)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"����"));
	itemBoxs.at(11)->SetName(L"����");
	itemBoxs.at(11)->SetPos(Vec2(300, 0));
	itemBoxs.at(11)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"��"));
	itemBoxs.at(12)->SetName(L"��");
	itemBoxs.at(12)->SetPos(Vec2(450, 0));
	itemBoxs.at(12)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"���"));
	itemBoxs.at(13)->SetName(L"���");
	itemBoxs.at(13)->SetPos(Vec2(750, 0));
	itemBoxs.at(13)->SetScale(Vec2(100, 100));

	//4
	itemBoxs.push_back(make_shared<ItemBox>(L"����"));
	itemBoxs.at(14)->SetName(L"����");
	itemBoxs.at(14)->SetPos(Vec2(0, -200));
	itemBoxs.at(14)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"���"));
	itemBoxs.at(15)->SetName(L"���");
	itemBoxs.at(15)->SetPos(Vec2(-150, -200));
	itemBoxs.at(15)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"Ű"));
	itemBoxs.at(16)->SetName(L"Ű");
	itemBoxs.at(16)->SetPos(Vec2(375, -200));
	itemBoxs.at(16)->SetScale(Vec2(100, 100));
	
	//5
	itemBoxs.push_back(make_shared<ItemBox>(L"������"));
	itemBoxs.at(17)->SetName(L"������");
	itemBoxs.at(17)->SetPos(Vec2(0, -400));
	itemBoxs.at(17)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"���� ���"));
	itemBoxs.at(18)->SetName(L"���� ���");
	itemBoxs.at(18)->SetPos(Vec2(150, -400));
	itemBoxs.at(18)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"ö ���"));
	itemBoxs.at(19)->SetName(L"ö ���");
	itemBoxs.at(19)->SetPos(Vec2(300, -400));
	itemBoxs.at(19)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"�� ����"));
	itemBoxs.at(20)->SetName(L"�� ����");
	itemBoxs.at(20)->SetPos(Vec2(600, -400));
	itemBoxs.at(20)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"�ݱ�"));
	itemBoxs.at(21)->SetName(L"�ݱ�");
	itemBoxs.at(21)->SetPos(Vec2(750, -400));
	itemBoxs.at(21)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"����"));
	itemBoxs.at(22)->SetName(L"����");
	itemBoxs.at(22)->SetPos(Vec2(900, -400));
	itemBoxs.at(22)->SetScale(Vec2(100, 100));
   
	//6
	itemBoxs.push_back(make_shared<ItemBox>(L"��"));
	itemBoxs.at(23)->SetName(L"��");
	itemBoxs.at(23)->SetPos(Vec2(150, -600));
	itemBoxs.at(23)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"���"));
	itemBoxs.at(24)->SetName(L"���");
	itemBoxs.at(24)->SetPos(Vec2(450, -600));
	itemBoxs.at(24)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"����"));
	itemBoxs.at(25)->SetName(L"����");
	itemBoxs.at(25)->SetPos(Vec2(675, -600));
	itemBoxs.at(25)->SetScale(Vec2(100, 100));

	//7
	itemBoxs.push_back(make_shared<ItemBox>(L"�ذ�"));
	itemBoxs.at(26)->SetName(L"�ذ�");
	itemBoxs.at(26)->SetPos(Vec2(300, -800));
	itemBoxs.at(26)->SetScale(Vec2(100, 100));

	itemBoxs.push_back(make_shared<ItemBox>(L"�����̾�"));
	itemBoxs.at(27)->SetName(L"�����̾�");
	itemBoxs.at(27)->SetPos(Vec2(450, -800));
	itemBoxs.at(27)->SetScale(Vec2(100, 100));

	//8
	itemBoxs.push_back(make_shared<ItemBox>(L"����"));
	itemBoxs.at(28)->SetName(L"����");
	itemBoxs.at(28)->SetPos(Vec2(300, -1000));
	itemBoxs.at(28)->SetScale(Vec2(100, 100));

	//9
	itemBoxs.push_back(make_shared<ItemBox>(L"���̾Ƹ��"));
	itemBoxs.at(29)->SetName(L"���̾Ƹ��");
	itemBoxs.at(29)->SetPos(Vec2(300, -1200));
	itemBoxs.at(29)->SetScale(Vec2(100, 100));
}

ItemTree::~ItemTree()
{
}
void ItemTree::Update()
{
	if (KEY_TAP(KEY::ENTER))
	{
		Vec2 pos = Vec2(300 - itemBoxs.at(0)->GetPos().x, 400 - itemBoxs.at(0)->GetPos().y);

		for (auto& itemBox : itemBoxs)
		{
			itemBox->SetPos(Vec2(itemBox->GetPos().x + pos.x, itemBox->GetPos().y + pos.y));
		}
	}

	if (KEY_HOLD(KEY::W))
	{
		for (auto& itemBox : itemBoxs)
		{
			itemBox->SetPos(Vec2(itemBox->GetPos().x, itemBox->GetPos().y + 10));
		}
	}
	else if (KEY_HOLD(KEY::S))
	{
		for (auto& itemBox : itemBoxs)
		{
			itemBox->SetPos(Vec2(itemBox->GetPos().x, itemBox->GetPos().y - 10));
		}
	}
	else if (KEY_HOLD(KEY::A))
	{
		for (auto& itemBox : itemBoxs)
		{
			itemBox->SetPos(Vec2(itemBox->GetPos().x + 10, itemBox->GetPos().y));
		}
	}
	else if (KEY_HOLD(KEY::D))
	{
		for (auto& itemBox : itemBoxs)
		{
			itemBox->SetPos(Vec2(itemBox->GetPos().x - 10, itemBox->GetPos().y));
		}
	}
}

void ItemTree::Render(HDC _dc)
{
	for (auto& itemBox : itemBoxs)
	{

		if (Inventory::GetInst()->CheckGetItemWas(itemBox->GetItemData()))
		{
			DrawLines(_dc, itemBox->GetItemData(), itemBox);
		}
	}

	for (auto& itemBox : itemBoxs)
	{

		if (Inventory::GetInst()->CheckGetItemWas(itemBox->GetItemData()))
		{
			itemBox->Render(_dc);
		}
		else
		{
			Rectangle(_dc,
				itemBox->GetPos().x - itemBox->GetScale().x / 4 - 32,
				itemBox->GetPos().y - itemBox->GetScale().y / 4 - 32,
				itemBox->GetPos().x + itemBox->GetScale().x / 4 - 32,
				itemBox->GetPos().y + itemBox->GetScale().y / 4 - 32);
		}
	}
}

void ItemTree::DrawLines(HDC _dc, const wstring& key, shared_ptr<ItemBox> itemBox)
{
	if (key == L"����")
	{
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32);
	}


	if (key == L"��")
	{
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(_dc, pen);

		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(0)->GetPos().x - 32, itemBoxs.at(0)->GetPos().y - 32);

		SelectObject(_dc, oldPen);
		DeleteObject(pen);
	}

	if (key == L"����")
	{
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(0)->GetPos().x - 32, itemBoxs.at(0)->GetPos().y - 32);

		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(1)->GetPos().x - 32, itemBoxs.at(1)->GetPos().y - 32);
	}

	if (key == L"������")
	{
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(_dc, pen);

		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(2)->GetPos().x - 32, itemBoxs.at(2)->GetPos().y - 32);

		SelectObject(_dc, oldPen);
		DeleteObject(pen);
	}

	if (key == L"����")
	{
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
		HPEN oldPen = (HPEN)SelectObject(_dc, pen);

		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(0)->GetPos().x - 32, itemBoxs.at(0)->GetPos().y - 32);

		SelectObject(_dc, oldPen);
		DeleteObject(pen);
	}

	if (key == L"���� �ֱ�")
	{
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
		HPEN oldPen = (HPEN)SelectObject(_dc, pen);

		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(1)->GetPos().x - 32, itemBoxs.at(1)->GetPos().y - 32);

		SelectObject(_dc, oldPen);
		DeleteObject(pen);
	}

	if (key == L"����")
	{
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(_dc, pen);

		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(5)->GetPos().x - 32, itemBoxs.at(5)->GetPos().y - 32);

		SelectObject(_dc, oldPen);
		DeleteObject(pen);
	}

	if (key == L"���� ����")
	{
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
		HPEN oldPen = (HPEN)SelectObject(_dc, pen);

		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(2)->GetPos().x - 32, itemBoxs.at(2)->GetPos().y - 32);

		SelectObject(_dc, oldPen);
		DeleteObject(pen);
	}

	if (key == L"å")
	{
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(2)->GetPos().x - 32, itemBoxs.at(2)->GetPos().y - 32);
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(3)->GetPos().x - 32, itemBoxs.at(3)->GetPos().y - 32);
	}

	if (key == L"ȶ��")
	{
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(_dc, pen);

		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(8)->GetPos().x - 32, itemBoxs.at(8)->GetPos().y - 32);

		SelectObject(_dc, oldPen);
		DeleteObject(pen);
	}

	if (key == L"�ڽ�")
	{
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
		HPEN oldPen = (HPEN)SelectObject(_dc, pen);

		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(4)->GetPos().x - 32, itemBoxs.at(4)->GetPos().y - 32);

		SelectObject(_dc, oldPen);
		DeleteObject(pen);
	}

	if (key == L"����")
	{
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(5)->GetPos().x - 32, itemBoxs.at(5)->GetPos().y - 32);
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(6)->GetPos().x - 32, itemBoxs.at(6)->GetPos().y - 32);
	}

	if (key == L"��")
	{
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(_dc, pen);

		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(11)->GetPos().x - 32, itemBoxs.at(11)->GetPos().y - 32);

		SelectObject(_dc, oldPen);
		DeleteObject(pen);
	}

	if (key == L"���")
	{
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(_dc, pen);

		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(10)->GetPos().x - 32, itemBoxs.at(10)->GetPos().y - 32);

		SelectObject(_dc, oldPen);
		DeleteObject(pen);
	}

	if (key == L"����")
	{
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(8)->GetPos().x - 32, itemBoxs.at(8)->GetPos().y - 32);
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(9)->GetPos().x - 32, itemBoxs.at(9)->GetPos().y - 32);
	}

	if (key == L"���")
	{
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(7)->GetPos().x - 32, itemBoxs.at(7)->GetPos().y - 32);
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(5)->GetPos().x - 32, itemBoxs.at(5)->GetPos().y - 32);
	}

	if (key == L"Ű")
	{
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
		HPEN oldPen = (HPEN)SelectObject(_dc, pen);

		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(11)->GetPos().x - 32, itemBoxs.at(11)->GetPos().y - 32);

		SelectObject(_dc, oldPen);
		DeleteObject(pen);
	}

	if (key == L"������")
	{
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(2)->GetPos().x - 32, itemBoxs.at(2)->GetPos().y - 32);
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(11)->GetPos().x - 32, itemBoxs.at(11)->GetPos().y - 32);
	}

	if (key == L"���� ���")
	{
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(13)->GetPos().x - 32, itemBoxs.at(13)->GetPos().y - 32);
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(14)->GetPos().x - 32, itemBoxs.at(14)->GetPos().y - 32);
	}

	if (key == L"ö ���")
	{
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(11)->GetPos().x - 32, itemBoxs.at(11)->GetPos().y - 32);
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(15)->GetPos().x - 32, itemBoxs.at(15)->GetPos().y - 32);
	}

	if (key == L"�� ����")
	{
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(_dc, pen);

		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(21)->GetPos().x - 32, itemBoxs.at(21)->GetPos().y - 32);

		SelectObject(_dc, oldPen);
		DeleteObject(pen);
	}

	if (key == L"�ݱ�")
	{
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(11)->GetPos().x - 32, itemBoxs.at(11)->GetPos().y - 32);
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(12)->GetPos().x - 32, itemBoxs.at(12)->GetPos().y - 32);
	}

	if (key == L"����")
	{
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(10)->GetPos().x - 32, itemBoxs.at(10)->GetPos().y - 32);
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(16)->GetPos().x - 32, itemBoxs.at(16)->GetPos().y - 32);
	}

	if (key == L"��")
	{
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(17)->GetPos().x - 32, itemBoxs.at(17)->GetPos().y - 32);
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(18)->GetPos().x - 32, itemBoxs.at(18)->GetPos().y - 32);
	}

	if (key == L"���")
	{
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(20)->GetPos().x - 32, itemBoxs.at(20)->GetPos().y - 32);
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(22)->GetPos().x - 32, itemBoxs.at(22)->GetPos().y - 32);
	}

	if (key == L"����")
	{
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(_dc, pen);

		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(24)->GetPos().x - 32, itemBoxs.at(24)->GetPos().y - 32);

		SelectObject(_dc, oldPen);
		DeleteObject(pen);
	}

	if (key == L"�ذ�")
	{
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(19)->GetPos().x - 32, itemBoxs.at(19)->GetPos().y - 32);
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(23)->GetPos().x - 32, itemBoxs.at(23)->GetPos().y - 32);
	}

	if (key == L"�����̾�")
	{
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(21)->GetPos().x - 32, itemBoxs.at(21)->GetPos().y - 32);
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(24)->GetPos().x - 32, itemBoxs.at(24)->GetPos().y - 32);
	}

	if (key == L"����")
	{
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(25)->GetPos().x - 32, itemBoxs.at(25)->GetPos().y - 32);
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(26)->GetPos().x - 32, itemBoxs.at(26)->GetPos().y - 32);
	}

	if (key == L"���̾Ƹ��")
	{
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(27)->GetPos().x - 32, itemBoxs.at(27)->GetPos().y - 32);
		MoveToEx(_dc, itemBox->GetPos().x - 32, itemBox->GetPos().y - 32, nullptr);
		LineTo(_dc, itemBoxs.at(28)->GetPos().x - 32, itemBoxs.at(28)->GetPos().y - 32);
	}
}
