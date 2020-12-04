#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"����"NOR);
        set("long", @LONG
�ƽ��ǽ�ڹ�Ȼ��֮�ƶ����ֳ��˵��Ż����˻�δ��ȥ������һƬ��
�͵Ĺ����˳��������ɫ��ǽ�ں󣬾���Ȼȫ�����鱦����������鱦��
�κ������ζ��벻��������ô����鱦��
LONG
        );
        set("exits", ([ 
                "center" : __DIR__"center",
                        ]));
        set("objects", ([
                __DIR__"obj/treasure" : 3,
                __DIR__"npc/maskman_g" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void init()
{
        add_action("do_pick", "get");
}  
int do_pick(string arg) {
        object me, guard;
        int num;
        
        if(!arg) return 0;
        if (arg=="all" || arg == "treasure stone"
                || sscanf(arg,"treasure stone %d",num)) {
                if (guard=present("maskman",this_object())) {
                        message_vision("$N���Բ�����ֵ�ס���㡣\n",guard);
                        return 1;
                }
                return 0;
   }
        return 0;
}   
