// zjb /2002/3/16/
#include <ansi.h>
inherit ROOM;
void on_sun();
void create()
{
        set("short", HIC"����"NOR);
        set("long", @LONG 
��������һ������,һ��������ǰ���죬
������ҹ�����������⡣

LONG
        ); 
        set("exits", ([ 
                   "north"  : __DIR__"changlang5", 
                 "west"  : __DIR__"jingtou", 
         "east"  : __DIR__"changlang6",
         "south"  : __DIR__"changlang6",
                                            ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
    object me, room; 

room = find_object(__DIR__"baoku2");    me = this_player();  
message_vision(HIR"ͻȻ���﷢��һ�����������������˽�����������Ļ�����!\n"NOR, me);
{
if (me->query("neili")>99)
{
if (me->query_skill("dodge",1)>300)
{   
message_vision(HIB"$N�粽���ţ���Ȼ�������졣\n"NOR, this_player());
message_vision(HIB"ʮ֦�س��شֵľ��ּ�ʸ�������������µĴ���һ�˰� \n"NOR, this_player());
message_vision(HIB"�ڴ�����������ƿ����������ĺ�Х��������ž��ĵ���\n"NOR, this_player());
message_vision(HIB"�ȵ�������̶���$N����һ�ƣ�����˼�ʸ!\n"NOR, this_player()); 
message_vision(HIB"���ǻ������˲�������!\n"NOR, this_player());
me->add("neili",-me->query("max_neili")/5); 
}
}if (me->query_skill("dodge",1)<201) 
  {     
message_vision(HIR"$N�粽���ţ���Ȼ�������졣\n"NOR, this_player());
message_vision(HIR"ʮ֦�س��شֵľ��ּ�ʸ�������������µĴ���һ�˰� \n"NOR, this_player());
message_vision(HIR"�ڴ�����������ƿ����������ĺ�Х��������ž��ĵ���\n"NOR, this_player());
message_vision(HIR"�ȵ�������̶���$N������ʸ,���������Ṧ̫�����ʸ\n"NOR, this_player()); 
message_vision(HIR"������,���������!\n"NOR, this_player());
  me->receive_wound("qi",me->query("max_qi")/4);
}    
if (me->query("neili")<100)
{
message_vision(HIR"$N�粽���ţ���Ȼ�������졣\n"NOR, this_player());
message_vision(HIR"ʮ֦�س��شֵľ��ּ�ʸ�������������µĴ���һ�˰� \n"NOR, this_player());
message_vision(HIR"�ڴ�����������ƿ����������ĺ�Х��������ž��ĵ���\n"NOR, this_player());
message_vision(HIR"�ȵ�������̶���$N������ʸ,����������������������ʸ\n"NOR, this_player()); 
 message_vision(HIR"������,���������!\n"NOR, this_player());
  me->receive_wound("qi",me->query("max_qi")/6);
}
if (me->query("neili")<1)
 {
me->set("neili",1);
}
            }
}

