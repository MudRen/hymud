// zjb /2002/3/15/
#include <ansi.h>
inherit ROOM;
int do_jump(string arg);  
void on_sun();
void create()
{
        set("short", "�ֱ�");
        set("long", @LONG 
�����ø�����ĸֱ�,̽�첻�����ĺ��,���ǹ��Ʋ���,
�������������ڹ������Ǻܷ�������!
LONG
        );
        set("exits", ([
                              ]));
        set("no_clean_up", 1);
        setup();
}
void init()
{
    object me;
    me = this_player();
    if (userp(me)){
        call_out("do_sun",1,me);
        }

    
   add_action("do_jump", "jump"); 
}
int do_jump(string arg)
{
        object me; 
               me = this_player();
      if( !arg || arg=="" ) return notify_fail("��Ҫ��������!\n");
     if( arg=="up" ) { 
if (me->query_skill("dodge",1)<200)
{       write("��ƴ��������,������Ϊ�Ṧ����ʧ����!\n");
                            return 1;
        }  
  write("������һԾ,���ص����ܵ�!\n");
  if (!query("jiadodge")&& me->query_skill("dodge") <220)
{
 write(HIC"�㷢����һԾʹ�㷢�ӳ���ƽʱ���Ӳ���ˮƽ������Ṧ�ȼ���������!\n");
 me->set_skill("dodge",me->query_skill("dodge",1)+2);
set("jiadodge",1);
}
 write(HIR"��ͻȻ����ԭ����ť���ұ����и���ť!\n");
this_player()->set_temp("tongguo",1);
        this_player()->move(__DIR__"tongdao5");
 return 1;
   }

        else {
            write("������������?!\n");
            return 1;
        }
       }  
void do_sun(object me)
{
if (!me) return;
  if (environment(me)!=this_object()) return;  
if (me->query("neili")>9)
{  
write(HIR"��е����ϵ���������������!\n"NOR);
me->add("neili",-me->query("max_neili")/100); 
}if (me->query("neili")<10) 
  {    
 write(HIB"��������Ѿ��ľ�,��е������Խ��Խ����!\n"NOR);
  me->receive_wound("qi",me->query("max_qi")/100);  
}    
   call_out("do_sun",3,me);
            }

