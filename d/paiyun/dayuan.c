// Room: /d/paiyun/dayuan.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
С·�ľ�ͷ��һ�����ķ���Ժ�䣬Ժ��������һЩ�����
��е���м�ĳ��ؿ���ȥƽ������ʵ���������Ǿ�������������
������Ժ��Ķ�����һ���ߴ�Ľ����ڵ׽��ֵĺ������顰����
�á��������֣������������ɷǷ���
LONG
	);

	set("exits", ([ /* sizeof() == 5 */
  "west" : __DIR__"chufang",
  "south" : __DIR__"lu2",
  "east" : __DIR__"lh_tang",
  "northeast" : __DIR__"lu3",
  "northwest" : __DIR__"lin1",
]));
        set("objects",([
        __DIR__"npc/cleaner" : 1,
]));

	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
