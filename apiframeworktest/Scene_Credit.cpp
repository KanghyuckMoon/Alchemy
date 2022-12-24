#include "pch.h"
#include "Scene_Credit.h"
#include "Core.h"
#include "TimeMgr.h"
#include "TextObject.h"
#include "SoundMgr.h"

Scene_Credit::Scene_Credit()
{
}

Scene_Credit::~Scene_Credit()
{
}

void Scene_Credit::Enter()
{
	SoundMgr::GetInst()->LoadSound(L"ENDINGBGM", true, L"Sound\\Make-It-Happen.wav");
	SoundMgr::GetInst()->Stop(SOUND_CHANNEL::SC_BGM);
	SoundMgr::GetInst()->Play(L"ENDINGBGM");

	textObj = make_shared<TextObject>();

	vector<wstring> wstr;
	wstr.push_back(L"Credit");
	wstr.push_back(L"");
	wstr.push_back(L"");
	wstr.push_back(L"Á¦ÀÛÀÚ");
	wstr.push_back(L"");
	wstr.push_back(L"");
	wstr.push_back(L"¹®°­Çõ");
	wstr.push_back(L"");
	wstr.push_back(L"±èÂùÈñ");
	wstr.push_back(L"");
	wstr.push_back(L"");
	wstr.push_back(L"");

	wstr.push_back(L"Lorem ipsum dolor sit amet, consectetur adipiscing ");
	wstr.push_back(L"elit. Vivamus vitae venenatis elit. Sed tincidunt ");
	wstr.push_back(L"lorem ut sapien ultricies rhoncus. Pellentesque at ");
	wstr.push_back(L"dolor vitae odio ultrices ullamcorper. Pellentesque ");
	wstr.push_back(L"fermentum turpis sed enim viverra dictum. Vivamus ");
	wstr.push_back(L"suscipit aliquam molestie.Nullam nec augue nibh.");
	wstr.push_back(L"Maecenas at iaculis quam.");

	wstr.push_back(L"");
	wstr.push_back(L"");
	wstr.push_back(L"");
	wstr.push_back(L"Pellentesque tincidunt velit felis, ut rutrum ante ");
	wstr.push_back(L"dignissim et. Donec laoreet venenatis ligula at ");
	wstr.push_back(L"aliquam. Donec fermentum augue nec fringilla ornare. ");
	wstr.push_back(L"Vestibulum ante ipsum primis in faucibus orci luctus ");
	wstr.push_back(L"et ultrices posuere cubilia curae; Nunc consequat ");
	wstr.push_back(L"efficitur velit, id porttitor metus malesuada ac. ");
	wstr.push_back(L"Class aptent taciti sociosqu ad litora torquent per ");
	wstr.push_back(L"conubia nostra, per inceptos himenaeos. Nunc eleifend ");
	wstr.push_back(L"nulla non leo suscipit dignissim. Pellentesque nunc est, ");
	wstr.push_back(L"viverra sit amet dignissim eu, dapibus in quam. Integer ");
	wstr.push_back(L"enim risus, congue non eleifend eget, bibendum quis leo. ");
	wstr.push_back(L"Orci varius natoque penatibuset magnis dis parturient ");
	wstr.push_back(L"montes, nascetur ridiculus mus. Sed non augue dolor. ");
	wstr.push_back(L"Suspendisse consequat mi odio, at viverra ante ultrices ");
	wstr.push_back(L"nec. Donec scelerisque quis risus id consequat.");

	wstr.push_back(L"");
	wstr.push_back(L"");
	wstr.push_back(L"");
	wstr.push_back(L"Maecenas bibendum erat sed eros auctor suscipit. Donec ");
	wstr.push_back(L"vehicula a diam id commodo. Sed lorem dolor, tempor at ");
	wstr.push_back(L"magna eu, pharetra blandit eros. Nunc suscipit lacus in ");
	wstr.push_back(L"diam rutrum commodo. Vivamus a euismod ex. Mauris feugiat ");
	wstr.push_back(L"elit eget rhoncus eleifend. Suspendisse vulputate magna ");
	wstr.push_back(L"vitae varius auctor. Vestibulum magna velit, sollicitudin ");
	wstr.push_back(L"at laoreet sed, viverra nec mi. Nulla volutpat enim eu ");
	wstr.push_back(L"nisl fermentum, imperdiet commodo mi varius. Duis laoreet ");
	wstr.push_back(L"vitae leo vel rhoncus. Ut vitae nisl ac velit cursus congue ");
	wstr.push_back(L"a non erat. Maecenas commodo rutrum metus id fermentum. ");
	wstr.push_back(L"Praesent fermentum ut massa in tempus. Ut at faucibus sem. ");
	wstr.push_back(L"Proin ut sapien egestas, pretium diam ut, ultricies ante. ");
	wstr.push_back(L"Nunc felis erat, ullamcorper id egestas euismod, posuere et.");

	wstr.push_back(L"");
	wstr.push_back(L"");
	wstr.push_back(L"");
	wstr.push_back(L"Nullam dolor purus, varius nec auctor sit amet, rutrum non ");
	wstr.push_back(L"lorem. Nam non neque semper, varius elit et, finibus diam. ");
	wstr.push_back(L"Aliquam pulvinar eget leo eu dictum. Quisque pretium sapien ");
	wstr.push_back(L"nec mauris varius euismod. Fusce ante diam, auctor sit amet ");
	wstr.push_back(L"interdum ac, rhoncus luctus libero. Sed commodo varius enim, ");
	wstr.push_back(L"sit amet mattis neque venenatis et. Curabitur eget elit ");
	wstr.push_back(L"mauris. Sed nec turpis id leo volutpat vulputate sed vel ");
	wstr.push_back(L"lacus. Suspendisse eu odio nulla. Nulla faucibus malesuada ");
	wstr.push_back(L"nisi. Maecenas posuere mi eu nibh euismod imperdiet. Integer ");
	wstr.push_back(L"venenatis pulvinar magna non volutpat. Nullam fermentum mauris.");

	wstr.push_back(L"");
	wstr.push_back(L"");
	wstr.push_back(L"");
	wstr.push_back(L"Cras vel augue id nulla blandit vestibulum ac sed dui. ");
	wstr.push_back(L"Phasellus hendrerit feugiat sapien, id placerat orci ");
	wstr.push_back(L"vestibulum at. Orci varius natoque penatibus et magnis dis ");
	wstr.push_back(L"parturient montes, nascetur ridiculus mus. Aenean sagittis ");
	wstr.push_back(L"commodo metus, ut porttitor lorem vehicula a. Cras eros orci, ");
	wstr.push_back(L"laoreet quis feugiat at, sagittis non risus. Morbi tortor ");
	wstr.push_back(L"ipsum, auctor a porta tristique, vehicula aliquam nisi. ");
	wstr.push_back(L"Vestibulum congue interdum augue, in egestas ligula eleifend ");
	wstr.push_back(L"ac. Cras efficitur felis vel interdum vulputate. Nam sem ");
	wstr.push_back(L"sapien, convallis non gravida sed, tristique ut mi. Donec ");
	wstr.push_back(L"interdum neque sit amet efficitur scelerisque. Cras ut odio ");
	wstr.push_back(L"sit amet sem mollis imperdiet eget eget ipsum. Donec vel ");
	wstr.push_back(L"tristique enim. Morbi consectetur ultricies diam vitae ");
	wstr.push_back(L"mollis. Cras eget leo quam.");

	wstr.push_back(L"");
	wstr.push_back(L"");
	wstr.push_back(L"");
	wstr.push_back(L"Lorem ipsum dolor sit amet, consectetur adipiscing elit. ");
	wstr.push_back(L"Curabitur at nisl velit. Nam vitae nisi risus. Pellentesque ");
	wstr.push_back(L"condimentum, erat et mattis venenatis, tortor libero suscipit ");
	wstr.push_back(L"magna, quis tempor diam dolor vitae metus. Mauris a ultrices ");
	wstr.push_back(L"nulla. Suspendisse semper risus a elit finibus venenatis. ");
	wstr.push_back(L"Sed non malesuada neque. Phasellus accumsan ex mollis, cursus ");
	wstr.push_back(L"turpis vestibulum, sodales orci. Donec venenatis magna eros, ");
	wstr.push_back(L"quis condimentum purus semper non. Etiam rhoncus suscipit ");
	wstr.push_back(L"pretium. In ut nibh ut diam tristique accumsan non dapibus ");
	wstr.push_back(L"massa. Pellentesque euismod, nulla id posuere imperdiet, ");
	wstr.push_back(L"justo quam porttitor lacus, quis posuere orci eros eget arcu. ");
	wstr.push_back(L"Aliquam vel dolor id elit dapibus sodales ac sit amet tellus. ");
	wstr.push_back(L"Quisque fringilla ex justo, et porta nibh posuere at. Sed sed ");
	wstr.push_back(L"euismod lectus. Sed dignissim nisi id aliquet commodo.");

	wstr.push_back(L"");
	wstr.push_back(L"");
	wstr.push_back(L"");
	wstr.push_back(L"Special Thanks");
	wstr.push_back(L"");
	wstr.push_back(L"");
	wstr.push_back(L"±èÇöÁØ");
	wstr.push_back(L"");
	wstr.push_back(L"And.. You");

	textObj->SetCreditText(wstr);
	textObj->SetMoveValue(0, -0.1f);

	time = 0;
}

void Scene_Credit::Exit()
{
	SoundMgr::GetInst()->Stop(SOUND_CHANNEL::SC_BGM);
}

void Scene_Credit::Update()
{

	if (time < 61.5f)
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
