// trap.c
// created by mes, updated 6-21-97 pickle
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "ʯ���");
  set ("long", @LONG

�϶�������������ø��������ˣ�ǰ��Ҳ͸����һ�㶹��ĵƹ⣬��
ϡ�ɼ���Ӱ����������ͻȻ�ߵ����ߺ������˵����ã��㲻������һ
���亹��
LONG);
  set("trap", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"jail",
  "south" : __DIR__"lock",
]));

  setup();
}
void init()
{
  add_action("do_disarm", "disarm");
}
int do_disarm()
{
  object me=this_player(), room=this_object();
  int mykar,mydodge,factor;
  int damage, kee, maxkee;
  mykar=(int)me->query_kar();
  mydodge=me->query_skill("dodge");
  factor=(int)(mykar*3+mydodge);
  maxkee=(int)me->query("max_qi");
  kee=(int)me->query("qi");
  damage=maxkee*3/5;
  if (!me->query_temp("mark/wudidong_aware_of_trap"))
    return notify_fail("��Ҫ��ʲô��������ɭɭ�ģ��������ߣ�\n");
  me->delete_temp("mark/wudidong_aware_of_trap");
  if (!room->query("trap"))
    return notify_fail("�����Ѿ�������ˣ�\n");
  if (random(factor)>50)
    {
      message_vision(BLU "$N�ɹ��ز���˷�����Ļ��ء�\n" NOR, me);
      room->delete("trap");
      room->set("trap", 0);
      return 1;
    }
  else
    {
      message_vision(RED "һ���Ҽ���$N������" NOR, me);
      if(damage>kee)
	{
	  room->set("trap", 1);
	  call_out("playerdead", 1, me);
	  return 1;
	}
      else
	{
	  message_vision(RED "$N�˵ò��ᡣ\n" NOR, me);
	  message_vision(BLU "���ر������. \n" NOR, me);
	  me->receive_damage("qi", damage);
	  me->receive_wound("qi", damage-10);
	  room->delete("trap");
	  room->set("trap", 0);
	  return 1;
	}
    }
}
int valid_leave(object me, string dir)
{
  object room=this_object();
  int damage, kee, maxkee;
  maxkee=(int)me->query("max_qi");
  kee=(int)me->query("qi");
  if (dir =="north" && room->query("trap")==1)	
    {
	if(!userp(me)) return 0;

      message_vision(RED "$N����ȥ��ͻȻ�䣬ǽ�����һ����ꡣ\n" NOR, me);
      call_out("playerdead", 1, me);
      return notify_fail("");
    }
  //room->set("trap", 1);
  return ::valid_leave(me, dir);
}
void playerdead(object me)
{
  int mypot, mylp, mynewpot;

  if (me->query("combat_exp")<800000 && random(2))
  {

me->unconcious();
  }
  else
  {
    me->unconcious();
  }
  return;
}
