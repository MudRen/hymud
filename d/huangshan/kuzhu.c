 // TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����Ϫ");
        set("long", @LONG
��;ʢ������Ϫˮ�����ֵ״�����������������һ��СȪ��Ȫˮ���е���
�Ŀ�ɬζ��������ҩ��ڣ����������ҩ����Ʒ������֪������������Ȫˮ��Ȫˮ
���ڽⷦ�����а���������ǰ��һ���ͱڵ�ס��ȥ·��
LONG
        );
        set("exits", ([ 
  "southup" : __DIR__"zhulin",
]));
        set("objects", ([
                __DIR__"npc/snake" : 2,
"quest/skills2/wunon/yu/yutan" : 2	,
       ]) );
        set("item_desc", ([
                "����Ϫ": "��������Ŵ�Ϫ�����飩�кȣ������룩һ�ڡ�\n",
                "kuzhuxi": "��������Ŵ�Ϫ�����飩�кȣ������룩һ�ڡ�\n"
        ]) );
        set("outdoors", "huangshan");
    set("coor/x",-560);
    set("coor/y",-465);
        set("coor/z",10);
        setup();
}
void init(){
        add_action("do_drink","drink");
        add_action("climbing", "climb");
}
int do_drink(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg != "xi") return 0;
        if(me->query("water") >= me->max_water_capacity())
                return notify_fail("���ƺ������ʡ�\n");
        message_vision("$N���������ڿ���Ϫ�к���һ��ڿ�ˮ��\n",me);
   me->add("water",50);
        me->apply_condition("kuzhu",3+random(5));
        return 1;
} 
int climbing(string arg)
{
        object obj, me;
        int i;
        
        me = this_player();
        i = me->query_skill("dodge");
    if(!arg || arg=="") return notify_fail("��Ҫ��ʲô��\n");
    if( arg == "valley" || arg == "up" || arg == "�ͱ�"){
                me->start_busy(2);
                if( i >= 120 )  {  
                message_vision("$Nץ��ͻ����ʯ�ǣ�������˳���ͱ�������ȥ��\n", me);
            call_out("fliping",2,me);
                } else { 
                        if( random(10) > 1) {
                                message_vision("$Nץ��ͻ����ʯ�ǣ�������˳���ͱ�������ȥ��\n", me);
                                call_out("falling", 2 , me);
                        } else {
                        message_vision("$Nץ��ͻ����ʯ�ǣ�������˳���ͱ�������ȥ��\n", me);
                        call_out("fliping",2,me);
                        }
                }       
    } else {
        write("�㲻������"+arg+"\n");
    }
        return 1;
}
int fliping(object me)
{
        if( !me->is_ghost()) {   
        me->move(__DIR__"huangshan");
        message_vision("$N˳�Źȱ�����������\n", me);
        }
        return 1;
} 
void falling(object me) {
   tell_object(me, "ͻȻ�������һ��������������׹ȥ��\n");
        message_vision("�����š���������������һ����$N���صĴ�����ˤ��������\n", me);
    me->receive_wound("qi", random(50));
    me->receive_wound("jing", random(50));
    me->receive_wound("jing", random(50));
}
              
