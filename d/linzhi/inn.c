// Room: /d/linzhi/inn.c

inherit ROOM;

void create()
{
	set("short", "�����͵��Ժ");
	set("long", @LONG
�����ǰ�һ��Ψһ��һ�ҿ͵꣬Ҳ�ǰ�����ү�ĲƲ�����Ժ
������ʯשΧ��Ժ������ż���ʢˮ�õ�ʯ��(fill)�������
����һ�����Ρ������Ǹ�����Ȧ��һ����ƿ������߽���������
��������к���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"by04",
  "north" : __DIR__"inn01",
  "west" : __DIR__"inn02",
]));
        set("outdoors", "linzhi");
        set("resource/water", 1); 
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
