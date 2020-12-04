// Room: /d/fengtian/xh2.c

inherit ROOM;

void create()
{
	set("short", "�»�·");
	set("long", @LONG
�»�·��ʢ�����ǱȽϷ�����һ���ֵ�������ۼ��˲��ٱ�
���ĵ��̣����к��ж�����ɫ�Ĳ�ݣ�·�߻���һЩС��������
�ɳ���ɽ�ϲɵĲ�ҩ����ʱ���������򵽲��ٺö�����
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"shenwu",
  "south" : __DIR__"xh1",
  "east" : __DIR__"mofang",
  "north" : __DIR__"xh3",
]));
        set("outdoors", "fengtian");

	set("objects",([
"/clone/npc/man" : 3,
]));

	setup();
	replace_program(ROOM);
}
