#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "�ض�");
        set("long", @LONG
����СС�ĵص���Լ���߰˳ߣ�Ȼ��������Ǹ�СС�Ķ������Ҳ
����ֻ���߰˳߼��������ⶴ�ȴ�����̺������崲�ޱ�����������ˮ��
һ̳�ƣ���һ������⡢�㳦��Ŵ�׸⣬��Ȼ����ʮ�����顣
LONG
        );
        set("exits", ([ 
                                ]));
        set("objects", ([
                __DIR__"obj/barrel" : 1,
        ]) );
        set("resource/water", 1);
        set("liquid/container", "ˮ��");  
        set("objects", ([
               __DIR__"obj/ricecake" : 1,
               __DIR__"obj/meat" : 1,
        ]) );
        set("item_desc", ([
                "��": "����ߵͲ�ƽ���ڽ������һ����������һ�飬Ҳ�������(dig)һ�¡�\n",
                "����": "����ߵͲ�ƽ���ڽ������һ����������һ�飬Ҳ�������(dig)һ�¡�\n",
                "ground": "����ߵͲ�ƽ���ڽ������һ����������һ�飬Ҳ�������(dig)һ�¡�\n",
                "floor": "����ߵͲ�ƽ���ڽ������һ����������һ�飬Ҳ�������(dig)һ�¡�\n",
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void init()
{
        add_action("do_dig", "dig");
} 
int do_dig(string arg)
{
        object room, *inv;
        object me, weapon, ob;
        int i;
        me = this_player();
        room = find_object(__DIR__"center");
        if(!objectp(room)) 
                room = load_object(__DIR__"center"); 
        if (weapon=me->query_temp("weapon"))
                message_vision(YEL"$N����"+weapon->query("name")+YEL"���ڵ���ƴ��������������\n"NOR,me);
                else message_vision(YEL"$Nߣ�����ӣ��ڵ���ƴ��������������\n"NOR,me);
        message_vision(HIR"ͻȻ�����һ�죬����ľ�����ѵ���������������һ���󶴡�\n"NOR,me);
        inv = all_inventory(this_object());
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if (!userp(ob))continue;
                message_vision(HIR"һ�����У�$N����ֱ׹��ȥ��\n"NOR,ob);
                message("vision",HIR"��ͨһ��������ˤ�¸�������\n"NOR,room);
                ob->move(room);
        }
        return 1;
} 
