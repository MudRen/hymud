// Room: /d/jinghai/wm10.c

inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
������һ��������ͷ׵�ʯ���̳ɵ�С·�ϣ�ʯ������˸�
�ֻ��ơ�С·�������������ӣ�����ɭɭ���������ء���ʱ��ݺ
���������������������Ŀ������������Ҫ�쵽�������ˣ�����
����������¥�������������Կ���������ˮկ�����ˡ�
LONG
	);

        

	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"wm19",
  "east" : __DIR__"wm9",
  "west" : __DIR__"wm11",
]));
        set("objects",([
        __DIR__"npc/kanshou2" : 1,
]));


        set("outdoors","jinghai");

	setup();
}
int valid_leave(object who,string dir)
{
        object npc;

        npc=present("kan shou",this_object());

        if(dir=="east" || dir == "e")
        {
       who->delete_temp("can_enter_wm19");
        return ::valid_leave(who,dir);
        }

        if(npc&& (dir == "north" || dir == "n")
        && !who->query_temp("can_enter_wm19") )
        return notify_fail("����˵����û�����������������⡣\n");

        return ::valid_leave(who,dir);
}

