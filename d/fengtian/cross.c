// Room: /d/fengtian/cross.c

inherit ROOM;

void create()
{
	set("short", "ʮ��·��");
	set("long", @LONG
�����»�·����Զ·������ֽ����һ��ʮ��·�ڣ�������
�������ıȽ����ӣ�ʵ������������С�㳡��·���е�ת����
��һƬ�̵أ��̵�����һЩʯ�գ�����������������Ϣ��
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"xm4",
  "west" : __DIR__"wy3",
  "east" : __DIR__"wy4",
  "north" : __DIR__"xh1",
]));
        set("objects",([
        	__DIR__"npc/jinbing" :5,        	
        "/clone/misc/dache" : 1 
        ]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
