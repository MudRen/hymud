 // Room: /d/oldpine/keep2.c
#include <ansi.h> 
inherit ROOM; 
void create()
{
        set("short", "����կ");
        set("long", @LONG
����Ӧ��������կ�ˣ���ȻΧ�������ǽ����ľͷ��ɵģ�������
ϸһ�����������Ҫ��λ�ö����˲���ɳ��ʯ�ѣ�������Ȼ���������
�ĺõط����������óȻ�Ӵ��ſڹ��������϶���Դ���ģ���կ����
��������ߣ�����Խ��һ��ľ׮֮����Ǵ�����
LONG
        );
        
        set("exits", ([ /* sizeof() == 2 */
                "west" : __DIR__"keep15",
                "east" : __DIR__"keep3",
        ]));
        set("objects", ([
                __DIR__"npc/bandit_guard" : 3,
                __DIR__"npc/bandit_leader" : 2
        ]) ); 
        set("coor/x",590);
        set("coor/y",2350);
        set("coor/z",90);
        setup();
} 
int valid_leave(object me, string dir)
{
	if ( objectp(present("bandit", environment(me))) && 
		dir == "east")
		return notify_fail("������ס�����ȥ·��\n");
	if ( objectp(present("bandit leader", environment(me))) && 
		dir == "east")
		return notify_fail("����ͷ����ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}

