// Room: /d/snow/school2.c

inherit ROOM;

void create()
{
        
	set("coor",({-20,4950,10}));
	set("short", "�ɶ�Ҫ���㳡");
        set("long",
"��������վ������Ҫ���Ĺ㳡�ϣ��㻷�����ܣ�ֻ��һ�ಲ�����������ϣ�����ߵı߾�\n"
"�����ڶ�ݺݵĿ����㣬��ǽ���������ż����������ͣ���ͷ����æ���ϲˣ������������\n"
"���ּ�ճ��ˡ�\n"
);
        set("exits", ([ /* sizeof() = 2 */
        "west" : __DIR__"happyinn2",
        "east" : __DIR__"happyinn1",
 ]));
        set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/zgx" : 1,
   __DIR__"npc/room_guard" : 5,
  __DIR__"npc/waiter" : 1,
]));
        set_temp("light",1);
        setup();
}
