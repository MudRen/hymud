// chi.c
// by dicky

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",HIW "ԡ�ɳ�" NOR);
        set("long", @LONG
ԡ�ɳ����ٲ������һ̶��ˮ���ر߲�Զ����Σ�ҡ�ԡ�ɳ�Ԣ��һƬ����
�У��������������ɽ��ء����������������̿������������ʱ�����
������ţ�������ޣ����������칬������������
LONG
);
        set("outdoors", "taxue");
        set("xxc", 1);
        setup();
}

void init()
{
   object me, room;
    me = this_player();
    if (!(room = find_object(__DIR__"pubu")))
          room = load_object(__DIR__"pubu");
    if(interactive(me)){ 
        tell_room(environment(me), me->name()+"��ͨһ�����˽�����\n", ({ me }));
        tell_object(me, "����ͨһ�������˳�ˮ��\n");    
        tell_room(room, "ֻ������ͨ��һ����"+me->name()+"�Ѿ������˳�ˮ�\n");    
        call_out("do_swim", 1, this_player());       
       }
    add_action("do_no", "quit");
    add_action("do_no", "dazuo");
    add_action("do_no", "practice");
    add_action("do_no", "lian");
    add_action("do_no", "respirate");
    add_action("do_no", "exercise");
    add_action("do_no", "tuna");
    add_action("do_halt", "halt");
}

int do_no()
{
        write("�����ﲻ׼�����������飡\n");
        return 1;
}

int do_swim(object me)
{
        if(!living(me)) return 0;        
        
        if(me->query_con() < 25){
          tell_object(me, HIB "���ϳ�ˮ����̹ǣ����͵�һ������æ�������⣡\n"NOR);
          tell_room(environment(me), me->name()+"ȫ����£�����ææ����������ȥ��\n", ({ me }));
          me->move(__DIR__"pubu");
          tell_room(environment(me), me->name()+"����ææ�ش�ԡ�ɳ�������������ȫ���ף�ֱ����£�\n", ({ me }));
          me->start_busy(2);
          me->receive_damage("jing", 100);
          me->receive_damage("qi", 100);
         
          return 1;
          }
        tell_object(me, GRN "\n���������ĳ�ˮ�о�����Ϸ�������㻹�ǵ���������·���߹���̽��\n"NOR);
        me->set_temp("swimming", 1);
        me->set_temp("apply/short", ({me->name()+"("+me->query("id")+")"GRN" <��ˮ��> "NOR}));             
        me->receive_damage("qi", (int)me->query("kar") * 4 );
        call_out("do_pa", (20+random(40)-(me->query("con"))), me); 
        me->start_busy(6);      
        return 1;         
}

int do_pa(object me)
{
  if(!environment(me)->query("xxc")) return 0;
     if(!living(me)){
          message_vision("\nһ����紵���������Ե�$N�Ƶ��رߡ�\n", me);
          me->move(__DIR__"pubu");
          me->delete_temp("swimming");
          me->delete_temp("apply/short");
          message_vision("\nһ��������紵���������Ե�$N�Ƶ��˳رߡ�\n", me);
          return 1;
          }
     
     tell_object(me, HIY "\nͻȻһ����紵�����������һ�£���æ����ԡ�ɳء�\n" NOR );     
     tell_room(environment(me), "һ����紵����"+me->name()+"���������һ�£����ϳرߴ����·���\n", ({ me }));
     me->delete_temp("swimming");
     me->delete_temp("apply/short");
     me->move(__DIR__"pubu");
     tell_room(environment(me), me->name()+"�����ӵش�ԡ�ɳ�������������\n", ({ me })); 
     return 1;         
}

int do_halt()
{
      object me = this_player();
      remove_call_out("do_pa");

   if (me->is_busy())
        return notify_fail("����æ���ģ�\n");
     tell_object(me, HIY "\nͻȻ��������ʲô�£���æ���ϳرߴ����·���\n" NOR );
     tell_room(environment(me), me->name()+"����������ʲô�Ƶģ���æ���ϳرߴ����·���\n", ({ me }));
     me->delete_temp("swimming");
     me->delete_temp("apply/short");
     me->move(__DIR__"pubu");
     tell_room(environment(me), me->name()+"����ææ�ش�ԡ�ɳ�������������\n", ({ me })); 
     return 1;         
}

