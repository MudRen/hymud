// Room: /d/snow/ruin1.c
#include <localtime.h>
inherit ROOM;
int flag = 0;
void create()
{
        set("short", "�ƾɴ�լ");
        set("long", @LONG
������һ���ƾɴ�լ��ǰԺ�������Ѿ�������һ�룬���ڵ���
����ס�����ȥ·��ͥԺ���Ӳݴ����������Ѿ��ܾ�û����ס�ˣ�
��˵���������й����֣����ǵ�Ҳ��û��˵�����˱�������˸�
���ľ�����Ȼ�ճ�����������Ծ��ɴ�լ�����Żص����ϡ�
LONG
        );
       set("item_desc", ([ /* sizeof() == 2 */
                "�Ӳ�": "������Ӳ��Ѿ������м����ĳ����ˣ����Ȼ�����ϱߵĲݴ���ʲ
�ᶫ���������������⣬����Ҳ�п�������Ĵ����
",
                "����": "���������ڵĺۼ�������������լ�����˴������Ϊ���ֵĹ�ϵ��
�뿪�İɡ�
",
]));
        set("outdoors", "xueting");
        set("exits", ([ /* sizeof() == 1 */
                "west" : __DIR__"lane1",
]));
        setup();
}


void init()
{
        add_action("do_climb", "climb");
      //  add_action("do_search", "search");
}
int do_climb(string arg)
{
        if( arg == "����" )
        message_vision("$NС�����������̮�����������������\n", this_player());
        this_player()->move(__DIR__"ruin2");
        message("vision", this_player()->name() + "��̮����������һͷ���˹�����\n",
                environment(this_player()), this_player());
        return 1;
}
/*
int do_search(string arg)
{
        mixed t;
        object ob;
        if( arg == "�Ӳ�" ){
        t = NATURE_D->game_time(1);
        // Can only be found during 11:00 to 14:00
        if( flag || (t[LT_HOUR] < 10) || (t[LT_HOUR] > 13) ) {
                message_vision("$N���Ӳݴ���������ȥ������ʲ��Ҳû���ҵ���\n", this_player());
                return 1;
        }
        flag = 1;
        ob = new(__DIR__"/npc/obj/hairpin");
        ob->move(this_player());
        message_vision("$N�ڲݴ���������ȥ�����������һ֧������\n", this_player());
        return 1;}
        message_vision("$N������ȥ������ʲ��Ҳû���ҵ���\n", this_player());
        return 1;
}
void reset()
{
        flag = 0;
        ::reset();
}
*/