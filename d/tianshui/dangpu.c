// Room: /u/xiaozhen/dangpu.c

#include <room.h>

inherit HOCKSHOP;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨������
����ǰ����̨�ϰ���һ��ľ��(mupai)����̨���������ϰ壬һ
˫�������۾��������´������㡣 
LONG
	);
	set("item_desc", ([
	"mupai" : "���Ŀ���������䵱(pawn)������(sell)���ֻ���
��ƽ���ף��������ۡ�\n\n",
	"ľ��" : "���Ŀ���������䵱(pawn)������(sell)���ֻ���
��ƽ���ף��������ۡ�\n\n",
	]) );
	set("exits", ([
  "east" : __DIR__"nroad2",
	]));

	set("objects",([
	__DIR__"npc/tang" : 1,
]));
	setup();
}
