// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ��ϱ߾��Ǹ������������ˡ��кܶ����˴����
�����߹���˵�����������ĸ����������ȥ�����Ե������ı����̨��
LONG
	);
set("outdoors", "gaoli");
set("exits", ([
		"southeast" : __DIR__"xuanwumen",
        	"northwest":__DIR__"shanlu10",
	]));
       setup();
	
}

