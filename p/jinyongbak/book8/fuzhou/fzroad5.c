// Room: /d/fuzhou/fzroad5.c
// Date: May 12, 98  Java

inherit ROOM;
void fighting(object who);

void create()
{
	set("short", "���ӹŵ�");
	set("long", @LONG
����������������ɽ�������������Ĺ���̣����ղ�����⡣
ɽ�ж������޳�û�޳�����·������·����һ���Ẻ����������
���ۿ����㡣
LONG );
	set("exits", ([
		"south" : "/d/fuzhou/fzroad5",
	]));
        set("objects", ([
		__DIR__"npc/fangrenzhi" : 1,
		__DIR__"npc/linpingzhi" : 1,
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
