#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "�ؽ�");
        set("long", @LONG
�ؽ��ﺮ�����ʪ��������ǽ���Ϲ���һյ�͵ơ��谵�ĵƹ��£�
������Ե���ɭ�ɲ����ؽ�����һ�����ӣ������϶˶�����������һ
���ˡ�
LONG
        );
        set("exits", ([
                "down" : __DIR__"dijiao2",
                "up" : "/d/wudang/sanqingdian",	
        ]));
        set("objects", ([
                __DIR__"npc/biaoge" : 1,
        ]));
        set("item_desc", ([
        "����" : "һ��ľ�Σ�����İ���(handle)��Щ�ɶ����ƺ�����תһ�£�Turn����\n",
        "chair" : "һ��ľ�Σ�����İ���(handle)��Щ�ɶ����ƺ�����תһ�£�Turn����\n",
    ]));
        set("coor/x",-1120);
        set("coor/y",-120);
        set("coor/z",-20);
        setup();
        
} 
void init(){
        add_action("do_turn", "turn");
} 
int do_turn(string arg){
        object me, guard, nroom;    
        me = this_player();
        if(!arg || (arg != "handle" && arg != "����")) {
                tell_object(me,"��Ҫתʲô��\n");
                return 1;
        }
        message_vision(HIY "$N�������ϰ���һ�£����º�Ȼ�ѿ���һ���󶴣�\n$N�����һ����������ȥ��\n"NOR, this_player());
        nroom = find_object("/d/ghost/house3");
        if(!objectp(nroom)) nroom=load_object("/d/ghost/house3");
   me->move(nroom);
        message_vision(HIY "\n$N����������˳�����\n"NOR, me);
        return 1;
}  
