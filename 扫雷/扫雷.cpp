#include<graphics.h>
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
MOUSEMSG m;
RECT r;
int hei, wid, mine, ma[40][40] = { 0 }, ma2[40][40] = { 0 }, x, y, mi, sy, mo;
int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };
char s[10];
void settings()
{
	settextcolor(RGB(0, 0, 0));
	settextstyle(40, 0, _T("΢���ź�"));
	outtextxy(90, 30, _T("ѡ���Ѷ�"));
	setfillcolor(RGB(46, 134, 193));
	solidroundrect(80, 120, 310, 240, 5, 5);
	setfillcolor(RGB(34, 153, 84)); 
	solidroundrect(330, 120, 560, 240, 5, 5);
	setfillcolor(RGB(212, 172, 13)); 
	solidroundrect(80, 260, 310, 380, 5, 5);
	setfillcolor(RGB(203, 67, 53)); 
	solidroundrect(330, 260, 560, 380, 5, 5);
	settextcolor(RGB(255, 255, 255));
	settextstyle(32, 0, _T("΢���ź�"));
	setbkcolor(RGB(46, 134, 193)); 
	outtextxy(100, 140, _T("��"));
	setbkcolor(RGB(34, 153, 84)); 
	outtextxy(350, 140, _T("�е�"));
	setbkcolor(RGB(212, 172, 13)); 
	outtextxy(100, 280, _T("ר��"));
	setbkcolor(RGB(203, 67, 53)); 
	outtextxy(350, 280, _T("�Զ���"));
	settextstyle(26, 0, _T("΢���ź�"));
	setbkcolor(RGB(46, 134, 193)); 
	outtextxy(100, 175, _T("9x9��10����"));
	setbkcolor(RGB(34, 153, 84)); 
	outtextxy(350, 175, _T("16x16��40����"));
	setbkcolor(RGB(212, 172, 13)); 
	outtextxy(100, 315, _T("30x16��99����"));
	setbkcolor(RGB(203, 67, 53)); 
	outtextxy(350, 315, _T("�Զ���ߺ�����"));
}
int choose()
{
	while (1) {
		m = GetMouseMsg();
		if (m.x >= 80 && m.x <= 310 && m.y >= 120 && m.y <= 240 && m.uMsg == WM_LBUTTONDOWN)return 1;
		if (m.x >= 330 && m.x <= 560 && m.y >= 120 && m.y <= 240 && m.uMsg == WM_LBUTTONDOWN)return 2;
		if (m.x >= 80 && m.x <= 310 && m.y >= 260 && m.y <= 380 && m.uMsg == WM_LBUTTONDOWN)return 3;
		if (m.x >= 330 && m.x <= 560 && m.y >= 260 && m.y <= 380 && m.uMsg == WM_LBUTTONDOWN)return 4;
	}
	
}
void getnumber(int aa)
{
	int y1 = 0, y2 = 0, y3 = 0, s1 = 9, s2 = 9, s3 = 10;
	if (aa == 1)wid = hei = 9, mine = 10;
	else if (aa == 2)wid = hei = 16, mine = 40;
	else if (aa == 3)wid = 30, hei = 16, mine = 99;
	else if (aa == 4) {
		cleardevice();
		settextcolor(RGB(0, 0, 0));
		settextstyle(40, 0, _T("΢���ź�"));
		outtextxy(90, 30, _T("�Զ������"));
		settextstyle(26, 0, _T("΢���ź�"));
		outtextxy(80, 100, _T("���"));
		outtextxy(80, 190, _T("�߶�"));
		outtextxy(80, 280, _T("����"));
		setfillcolor(RGB(208, 208, 208));
		solidroundrect(80, 140, 500, 160, 20, 20);
		solidroundrect(80, 230, 500, 250, 20, 20);
		solidroundrect(80, 320, 500, 340, 20, 20);
		setlinecolor(RGB(208, 208, 208));
		setfillcolor(RGB(255, 255, 255));
		fillcircle(y1 + 90, 150, 10);
		fillcircle(y2 + 90, 240, 10);
		fillcircle(y3 + 90, 330, 10);
		settextstyle(26, 0, _T("΢���ź�"));
		_itoa(s1, s, 10);
		outtextxy(510, 135, s);
		_itoa(s2, s, 10);
		outtextxy(510, 225, s);
		_itoa(s3, s, 10);
		outtextxy(510, 315, s);
		setlinecolor(RGB(208, 208, 208));
		fillroundrect(440, 390, 560, 420, 10, 10);
		r = { 440,390,560,420 };
		drawtext(_T("ȷ��"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
		while (1) {
			m = GetMouseMsg();
			if (m.x >= 90 && m.x <= 490 && m.y >= 140 && m.y <= 160 && m.uMsg == WM_LBUTTONDOWN) {
				y1 = m.x - 90; s1 = 22 * y1 / 410 + 9;
				s3 = (s1 * s2 - s1 - s2 - 9) * y3 / 400 + 10;
				setfillcolor(RGB(208, 208, 208));
				clearrectangle(510, 130, 560, 170);
				solidroundrect(80, 140, 500, 160, 20, 20);
				setfillcolor(RGB(255, 255, 255));
				fillcircle(y1 + 90, 150, 10);
				clearrectangle(510, 310, 560, 350);
				_itoa(s1, s, 10);
				outtextxy(510, 135, s);
				_itoa(s3, s, 10);
				outtextxy(510, 315, s);
			}
			if (m.x >= 90 && m.x <= 490 && m.y >= 230 && m.y <= 250 && m.uMsg == WM_LBUTTONDOWN) {
				y2 = m.x - 90; s2 = 16 * y2 / 410 + 9;
				s3 = (s1 * s2 - s1 - s2 - 9) * y3 / 400 + 10;
				setfillcolor(RGB(208, 208, 208));
				clearrectangle(510, 220, 560, 260);
				solidroundrect(80, 230, 500, 250, 20, 20);
				setfillcolor(RGB(255, 255, 255));
				fillcircle(y2 + 90, 240, 10);
				clearrectangle(510, 310, 560, 350);
				_itoa(s2, s, 10);
				outtextxy(510, 225, s);
				_itoa(s3, s, 10);
				outtextxy(510, 315, s);
			}
			if (m.x >= 90 && m.x <= 490 && m.y >= 320 && m.y <= 340 && m.uMsg == WM_LBUTTONDOWN) {
				y3 = m.x - 90; s3 = (s1 * s2 - s1 - s2 - 9) * y3 / 400 + 10;
				setfillcolor(RGB(208, 208, 208));
				clearrectangle(510, 310, 560, 350);
				solidroundrect(80, 320, 500, 340, 20, 20);
				setfillcolor(RGB(255, 255, 255));
				fillcircle(y3 + 90, 330, 10);
				_itoa(s3, s, 10);
				outtextxy(510, 315, s);
			}
			if (m.x >= 440 && m.x <= 560 && m.y >= 390 && m.y <= 420 && m.uMsg == WM_LBUTTONDOWN) {
				wid = s1; hei = s2; mine = s3; mi = mine; sy = wid * hei; return;
			}
		}
	}
	mi = mine; sy = wid * hei;
	return;
}
int check(int xx, int yy)
{
	if (xx<1 || xx>wid || yy<1 || yy>hei)return 0;
	if (ma2[xx][yy] != 0)return 0;
	return 1;
}
void search(int xx, int yy)
{
	for (int k = 0; k < 8; ++k) {
		int nx = xx + dx[k], ny = yy + dy[k];
		if (check(nx, ny)) {
			ma2[nx][ny] = 1;
			if (ma[nx][ny] == 0)search(nx, ny);
		}
	}
}
void getsy()
{
	sy = 0;
	for (int i = 1; i <= wid; ++i)
		for (int j = 1; j <= hei; ++j)
			if (ma2[i][j] == 0)sy++;
}
void maprint()
{
	getsy();
	settextstyle(26, 0, _T("΢���ź�"));
	setbkcolor(RGB(255, 255, 255));
	settextcolor(RGB(0, 0, 0));
	for (int i = 1; i <= wid; ++i)
		for (int j = 1; j <= hei; ++j) {
			int x1 = 9 + (i - 1) * 30, y1 = 79 + (j - 1) * 30;
			int x2 = 6 + i * 30, y2 = 76 + j * 30;
			if (ma2[i][j] == 0) {
				setfillcolor(RGB(192, 192, 192));
				setbkcolor(RGB(192, 192, 192));
			}
			else {
				setfillcolor(RGB(224, 224, 224));
				setbkcolor(RGB(224, 224, 224));
			}
			solidroundrect(x1, y1, x2, y2, 2, 2);
			r = { x1,y1,x2,y2 };
			if (ma2[i][j] == 1 && ma[i][j] != 0 && ma[i][j] != 9) {
				_itoa(ma[i][j], s, 10);
				drawtext(s, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			}
			if (ma2[i][j] == 2)drawtext(_T("��"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
	setfillcolor(RGB(224, 224, 224));
	setbkcolor(RGB(224, 224, 224));
	solidroundrect(9, 10, 109, 70, 5, 5);
	solidroundrect(119, 10, 219, 70, 5, 5);
	r = { 9,10,109,40 };
	drawtext(_T("ʣ������"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	r = { 9,40,109,70 };
	itoa(mi, s, 10);
	drawtext(s, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	r = { 119,10,219,40 };
	drawtext(_T("ʣ�����"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	r = { 119,40,219,70 };
	itoa(sy, s, 10);
	drawtext(s, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
void drawma()
{
	for (int i = 1; i <= mine; ++i) {
		do {
			x = rand() % wid + 1;
			y = rand() % hei + 1;
		} while (ma[x][y] == 9);
		ma[x][y] = 9;
	}
	for (int i = 1; i <= wid; ++i)
		for (int j = 1; j <= hei; ++j) {
			if (ma[i][j] == 9)continue;
			for (int k = 0; k < 8; ++k)
				if (ma[i + dx[k]][j + dy[k]] == 9)ma[i][j]++;
		}
}
int main()
{
	int aa, xx = 1, yy = 1, flag = 1;
	char cz;
	initgraph(640, 480);
	setbkcolor(RGB(255, 255, 255));
	srand((unsigned)time(NULL));
	cleardevice();
	settings();
	setbkcolor(RGB(255, 255, 255));
	aa = choose();
	getnumber(aa);
	initgraph(16 + wid * 30, 86 + hei * 30);
	setbkcolor(RGB(255, 255, 255));
	cleardevice();
	drawma();
	while (1) {
		flag = 1;
		maprint();
		while (1) {
			m = GetMouseMsg();
			for (int i = 1; i <= wid; ++i)
				for (int j = 1; j <= hei; ++j) {
					int x1 = 9 + (i - 1) * 30, y1 = 79 + (j - 1) * 30;
					int x2 = 6 + i * 30, y2 = 76 + j * 30;
					if (m.x >= x1 && m.x <= x2 && m.y >= y1 && m.y <= y2) {
						if (m.uMsg == WM_LBUTTONDOWN) {
							flag = 0; xx = i; yy = j; mo = 0; break;
						}
						if (m.uMsg == WM_RBUTTONDOWN) {
							flag = 0; xx = i; yy = j; mo = 1; break;
						}
					}
				}
			if (flag == 0)break;
		}
		if (mo == 0) {
			if (ma[xx][yy] == 0)search(xx, yy);
			if (ma[xx][yy] == 9 && ma2[xx][yy] != 2) {
				ma2[xx][yy] = 2;
				getsy(); maprint();
				if (IDNO == MessageBox(GetHWnd(), "�Բ���������ˣ�ף���´κ��ˡ�", _T("ɨ��"), MB_OK)) break;
				return 0;
			}
			if (ma[xx][yy] == 9)ma2[xx][yy] = 2;
			else ma2[xx][yy] = 1;
		}
		else {
			if (ma2[xx][yy] == 0)ma2[xx][yy] = 2, mine--;
			else if (ma2[xx][yy] == 2)ma2[xx][yy] = 0, mine++;
			if (ma[xx][yy] == 9 && ma2[xx][yy] == 2)mi--;
			else if (ma[xx][yy] == 9 && ma2[xx][yy] == 0)mi++;
		}
		getsy();
		if (mi == 0 || sy-mi <= 0) {
			for (int i = 1; i <= wid; ++i)
				for (int j = 1; j <= hei; ++j) 
					if (ma2[i][j] == 0)ma2[i][j] = 2;
			maprint();
			if (IDNO == MessageBox(GetHWnd(), "��ϲ�㣬��Ӯ�ˡ�", _T("ɨ��"), MB_OK)) break;
			return 0;
		}
	}
	_getch();
	closegraph();
}