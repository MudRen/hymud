// zjb /2002/3/16/
#include <ansi.h>
inherit ROOM;
void on_sun();
void create()
{
        set("short", "�ȵ�");
        set("long", @LONG 
������һ���ȵ�,ĩ��û�밵��������Ѳ�Զ�� 
��ǳ������������Ŀ�����������!

LONG
        );     
        set("exits", ([  
            "enter"  : __DIR__"baoku",
                   "north"  : __DIR__"langdao5",
                "south"  : __DIR__"langdao6",
                "west"  : __DIR__"langdao6",
              "east"  : __DIR__"langdao6",
                              ]));
              set("no_clean_up", 0);
        setup();
}
void init()
{
    object me;
    me = this_player(); 
{
if (me->query_temp("jinbaoku"))
{
call_out("on_jinbaoku", 1);
}
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
        add_action("do_push", "push"); 
}


void on_jinbaoku(object room)
 {
  object me = this_player(); 
   message_vision(HIC"$NͻȻ�뵽����Ȼǽ�ڿ����������ôǽ����û�����һ�ߣ��β���(push)��ȥ������!\n"NOR, this_player()); 
}
int do_push(string arg)
{
        object me; 
      string dir;
             me = this_player();
       if( !arg || arg=="" ) return notify_fail("��Ҫ��ʲô����!\n");
      if( sscanf(arg, "%s", dir)==1 ) {
    if( dir=="ǽ��" || dir=="wall") {
   message_vision(HIR"$N�����ƿ���ǽ�ڣ��ֳ���һ����·!��\n"NOR, this_player());  
        set("exits/out", __DIR__"dishi");
call_out("on_guan", 5);
              return 1;
}
         else {
            write("������ʲô����?\n");
            return 1;
        }
}
} 

void on_guan(object room)
{
      message_vision(HIB"ͻȻ�������ǵ�������ǽ���ֺ�����!\n"NOR, this_player());
delete("exits/out");
}

