#include<graphics.h>
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int score = 0;
char c[20];
LOGFONT f;
ExMessage m;
void init()
{
	int x = 410, y = 200;
	setbkcolor(RGB(243, 243, 243));
	cleardevice();
	setfillcolor(RGB(255, 255, 255));
	setbkcolor(RGB(255, 255, 255));
	setlinecolor(RGB(204, 204, 204));
	fillroundrect(x, y, x+460, y+320, 16, 16);
	settextstyle(48, 0, _T("΢���ź� Bold"));
	outtextxy(x+30, y+30, _T("�ҵ����ص�ţ"));
	settextstyle(22, 0, _T("΢���ź�"));
	outtextxy(x + 30, y+110, _T("�ƶ�������ֱ�����ҵ������ص�ţ��"));
	outtextxy(x + 30, y+135, _T("��������Խ�������е�Խ�졣"));
	outtextxy(x + 30, y+170, _T("(ȷ���㿪ʼ��Ϸǰ����������)"));
	setfillcolor(RGB(0, 103, 192));
	setlinecolor(RGB(0, 62, 115));
	setbkcolor(RGB(0, 103, 192));
	fillroundrect(x + 30, y + 250, x + 180, y + 290, 8, 8);
	settextcolor(RGB(255, 255, 255));
	settextstyle(30, 0, _T("΢���ź�"));
	RECT r = { x + 30,y + 250,x + 180,y + 290 };
	drawtext(_T("��ʼ��Ϸ"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	while (1) {
		m = getmessage(EM_MOUSE);
		if (m.x >= x + 30 && m.x <= x + 180 && m.y >= y + 250 && m.y <= y + 290)
			if (m.lbutton==1)return;
	}
}
int game()
{
	int x = rand() % 1280, y = rand() % 720, s;
	setbkcolor(RGB(243, 243, 243));
	cleardevice();
	while(1) {
		m = getmessage();
		s = sqrt((x - m.x) * (x - m.x) + (y - m.y) * (y - m.y));
		Beep(1200-s*0.6, 10);
		if (s<=20)
			if (m.lbutton == 1) {
				solidcircle(x, y, 20);
				Sleep(3000); score++;
				return 1;
			}
	}
}
void congrats()
{
	ofstream outfile;
	outfile.open("score");
	outfile << score << endl;
	outfile.close();
	int x = 410, y = 200;
	setbkcolor(RGB(243, 243, 243));
	cleardevice();
	setfillcolor(RGB(255, 255, 255));
	setbkcolor(RGB(255, 255, 255));
	setlinecolor(RGB(204, 204, 204));
	fillroundrect(x, y, x + 460, y + 320, 16, 16);
	settextcolor(RGB(0, 0, 0));
	settextstyle(48, 0, _T("΢���ź� Bold"));
	outtextxy(x + 30, y + 30, _T("��ϲ��"));
	settextstyle(22, 0, _T("΢���ź�"));
	outtextxy(x + 30, y + 110, _T("���ҵ���һͷţ��"));
	sprintf(c, "��ǰ�ܷ֣�%d", score);
	outtextxy(x + 30, y + 135, c);
	setfillcolor(RGB(0, 103, 192));
	setlinecolor(RGB(0, 62, 115));
	setbkcolor(RGB(0, 103, 192));
	fillroundrect(x + 30, y + 250, x + 180, y + 290, 8, 8);
	settextcolor(RGB(255, 255, 255));
	settextstyle(30, 0, _T("΢���ź�"));
	RECT r = { x + 30,y + 250,x + 180,y + 290 };
	drawtext(_T("��ʼ��Ϸ"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	while (1) {
		m = getmessage(EM_MOUSE);
		if (m.x >= x + 30 && m.x <= x + 180 && m.y >= y + 250 && m.y <= y + 290)
			if (m.lbutton == 1)return;
	}
}
int main()
{
	initgraph(1280, 720);
	srand((unsigned)time(NULL));
	gettextstyle(&f);
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	settextcolor(RGB(0, 0, 0));
	ifstream infile;
	infile.open("score");
	infile >> score;
	infile.close();
	init();
	while (1) {
		if (game())congrats();
	}
	_getch();
	closegraph();
}