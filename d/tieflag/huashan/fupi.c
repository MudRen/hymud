#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "����ʯ");
        set("long", @LONG
�������ۣ�������ʯ�β��ý��ڵ���������һ���ʯ����һ�����࣬����
�ɣ�������Ϊ���ϣ���ͬ��������˵�˳�����ɽ��ĸ֮����ʯ�����ͷ֮����һ��
��������һ�˷������롣
LONG
        );
    set("exits", ([ 
        "southup" : __DIR__"lianhua",
        ]));
     set("objects", ([
                __DIR__"npc/hawk" : 1,
                        __DIR__"npc/hawktrainer" : 1,
       ]) ); 
    set("outdoors", "huashanfy"); 
    set("coor/x",-640);
    set("coor/y",-92);
    set("coor/z",75);
        setup();
    //replace_program(ROOM);
} 
void init()
{
        add_action("do_chop","chop");
} 
int do_chop(string arg)
{
        object me,*inv,weapon;
        object hawk,chain,hawktrainer;
        int i;
        hawk = present("hawk",this_object());
        if (!hawk || this_object()->query("item_desc") == 0 )
        {
                return 0;
                //need to give them hint here?
                //return notify_fail("��Ҫ����ʲô��\n");
   }
        
        if(!arg || (arg != "chain" && arg != "����") ) 
        {
                return notify_fail("��Ҫ����ʲô��\n");
        }
        me=this_player();
        
        if (hawktrainer = present("hawk trainer",this_object()))
        { 
        message_vision(RED"$N��$n���һ�����������ӥ�����⣡���ò��ͷ��ˣ� \n"NOR,
                       hawktrainer,me);
        hawktrainer->kill_ob(me);
        me->start_busy(2);
        return 1;
    } 
        inv = all_inventory(me);
        for (i=0;i<sizeof(inv);i++ )
        {
                if (objectp(inv[i]) && inv[i]->query("weapon_prop") && inv[i]->query("equipped"))
                { 
                        weapon = inv[i];
                        message_vision("$N�þ�ȫ���������е�"+weapon->name()+"������������ȥ��������\n",me);
                        //weapon->set("weapon_prop",0);
                        //weapon->save();
                        me->reset_action();
                        if (weapon ->query("rigidity")>=2000)
                        {
                                hawk->set("marks/chained",0);
                                this_object()->set("item_desc",0);
                                message_vision("����Ӧ�����ϣ�\n",me);
                                chain = new(__DIR__"npc/obj/chain");
                                chain->move(this_object());
                                return 1;
                        }
                        message_vision("ֻ������������һ����$N���е�"+weapon->name()+"�����˿�ȥ����������˿������\n",me);
                        me->start_busy(2);
                        return 1; 
                }
        }
   return notify_fail("��Ҫ��ʲô�������� \n");
}    
