// Room: /d/snow/court.c
inherit ROOM;
void create()
{
        set("short", "��У");
        set("long", @LONG
������ѩͤ�����У��ƽ������Թٸ���ʩ����ʲô�����Ŀ�
�Ե���������У�����ߣ���ν��У�Ͼ��ǵط����е�������������
�ˣ����굣��У�ϵ��ǿ�ĥ�������ϵ���������������岻�Ǻܺã�
����������У�����������ǽֵ���������һ�����ã���������ʦү
��������¾ͻ������￪�á�
LONG
        );
        set("outdoors","xueting");
        set("exits", ([ /* sizeof() == 1 */
                "south" : __DIR__"wstreet2",
        ]));
        set("objects", ([
        __DIR__"npc/oldman": 1
        ]));
        setup();
}
