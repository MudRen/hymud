
// Room: /d/snow/sroad4.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long",
"����һ������ʵ����ʯ���������������������Ļ�ľ������������ͨ��ˮ�̸�����\n"
"�����ν���Զ�ǽֵ���·�ڡ�\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"sroad3",
]));
	set("outdoors", "ny");

	setup();
//  replace_program(ROOM);;
}
int valid_leave(object me, string dir)
{
        if( dir=="north" && !wizardp(me) )
                return notify_fail("����ʩ���У���ĵ���\n");
        return ::valid_leave(me, dir);
}
