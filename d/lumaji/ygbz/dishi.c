// zjb /2002/3/16/
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG  
���Ǹ���Լ��ʮ���������ε��ң���������������� 
���ҶԵط���
LONG
        );     
        set("exits", ([  
                              ]));
              set("no_clean_up", 0);
        setup();
}
void init()
{
    object me;
    me = this_player(); 
    add_action("do_push", "push"); 
}
 void check_pushwall()
{
    object room; 
  object me = this_player(); 
 if( query("zuobian") &&query("youbian"))
{
message_vision(HIR"��ߵ�ǽ�������Ĵ��ˡ�\n"NOR, this_player());          

        set("exits/west", __DIR__"changlang");
           delete("zuobian");
        delete("youbian"); 
me->delete_temp("pushzuo");
me->delete_temp("pushyou");
      call_out("on_guan", 8);
    }
}


int do_push(string arg)
{
        object me; 
      string dir;
             me = this_player();
       if( !arg || arg=="" ) return notify_fail("��Ҫ��ʲô����!\n");
      if( sscanf(arg, "%s", dir)==1 ) {
    if( dir=="wall") {
   message_vision(HIR"$N����ǽ����һ�ߣ�\n"NOR, this_player());          
          return 1;
} 
    if( sscanf(arg, "wall %s", dir)==1 ) {
   if( dir=="right" ) {  
if(me->query_temp("pushzuo"))  return notify_fail("���Ѿ�������ߵ�ǽ�ˣ����������ұߵģ��㵱�Լ�������ѽ!\n");
            message_vision("$N�������ұߵ�ǽ�ڡ�\n", this_player()); 
set("youbian",1);
me->set_temp("pushyou",1); 
check_pushwall();
return 1;
}
 else if( dir=="left" ) { 
if(me->query_temp("pushyou"))  return notify_fail("���Ѿ������ұߵ�ǽ�ˣ�����������ߵģ��㵱�Լ�������ѽ!\n");
  message_vision("$N��������ߵ�ǽ�ڡ�\n", this_player()); 
set("zuobian",1);
me->set_temp("pushzuo",1); 
check_pushwall();
return 1;
}         else {
            write("������ʲô����?\n");
            return 1;
        }
}
} 
}

void on_guan(object room)
{
      message_vision(HIB"ͻȻ�������ǵ�������ǽ���ֺ�����!\n"NOR, this_player());
delete("exits/west");
}

