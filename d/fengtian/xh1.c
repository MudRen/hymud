// Room: /d/fengtian/xh1.c

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

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"cross",
  "east" : __DIR__"chaguan",
  "north" : __DIR__"xh2",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
