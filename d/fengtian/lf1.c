// Room: /d/fengtian/lf1.c

inherit ROOM;

void create()
{
	set("short", "��Ա�⸮");
	set("long", @LONG
��������Ա��ĸ��ڣ���Ա����ʢ���ϳǵ����������ˣ���
����ʵ������������
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kd1",
  "east" : __DIR__"lf2",
]));
        set("outdoors", "fengtian");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}
