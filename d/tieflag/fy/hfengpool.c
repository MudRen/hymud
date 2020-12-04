 inherit ROOM;
#include <room.h> 
void create()
{
        set("short", "��ҶȪ");
        set("long", @LONG
���Ƴ��еķ�ҶȪ�Ƿ�Բ�������������һ����Ȫ��ˮ�����У�Ȫˮ�ʵ���,
�ʶ�������Ҷ����������ȥ����������Ч����˵�����������ٵ����á����ֵ�һ
�������ɶ�ÿ�춼�Դ�Ȫˮ��棨�����裩�����������绨�������ò��
LONG
        );
        set("exits", ([
                "west" : __DIR__"hfenglang3",
        ]));
        set("objects", ([
                __DIR__"npc/xianu": 2,
        ]) );
        set("outdoors", "fengyun");
        set("no_fly", 1);
        set("coor/x",45);
        set("coor/y",45);
        set("coor/z",0);
        setup();
        create_door("west", "̴ľ��", "east", DOOR_CLOSED); 
} 
void init()
{
        add_action("do_jump", "wash"); 
} 
int do_jump()
{
        object me;
        int wait;
        me = this_player();
        me->add_temp("jumpinpool",1);
        wait = random( 50 - (int)me->query("con")) + 4 * (int)me->query_temp("jumpinpool");
        if ( wait <= 20) wait = 21;
        message_vision("$N��������Ȫˮ�У�\n",me);
        tell_object(me,"��е�ȫ���ޱȵ���̩����\n");
        remove_call_out("curehimup");
   call_out("curehimup", wait, me);
        if(!me->query("����B/�䵱_��Ҷ") && !random(10))
                call_out("give_maple_leaf",5,me);
return 1;
}  
int give_maple_leaf(object me)
{
        object leaf;
        
        if(!me || !present(me,this_object()))
                return 1;
        tell_object(me,"һƬ���ķ�ҶƮ�˹����������Ľ���ʰ��������\n");
        leaf=new("/d/tieflag/fy/obj/mapleleaf");
        leaf->move(me);
        return 1;
}  
void curehimup(object me)
{
        int gin,kee,sen;
        if(!me) return;
        gin=(int)me->query("max_gin");
        kee=(int)me->query("max_kee");
        sen=(int)me->query("max_sen");
if( me && environment(me) == this_object())
        {
        message_vision("$N�ľ�����ȫ�ָ��ˣ���\n", me);
        me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
        me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen);
        if(!random(30)) me->delete_temp("jumpinpool");
        }
return;
}   
