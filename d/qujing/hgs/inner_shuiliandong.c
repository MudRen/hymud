// Room: /d/4world/shuilian_dong.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "ˮ�����ڲ�");
  set ("long", @LONG

������ˮ�������������һƬ�ڰ���ʯ������ϡ���Կ���ʲô����
�ں����ġ�����ͼ��ʯ������(expand)һЩ������ȡ���Ǽ�������
LONG);

//  set("not_generating_jingbubang", 0);
  setup();
}

void init()
{
	add_action("do_expand", "expand");
}

int do_expand(string arg)
{
	object me=this_player();
	object ob; 

	if( (!arg) || !((arg == "gap") || (arg == "ʯ��")))
		return notify_fail("��Ҫ�ǿ�ʲô��\n");

	if( !(ob = me->query_temp("weapon")) || ( (string)ob->query("skill_type")!="axe" && (string)ob->query("skill_type")!="blade" && (string)ob->query("skill_type")!="sword" ) ) 
		return notify_fail("û�й�����ô�ɻ\n");

	if( me->query_str() < 50 )
		return notify_fail("�������������\n");

	if (me->query("qi") < 200) {
		message_vision(HIR"\nֻ���ú��һ����һ���ʯ��������������$N�����˹�ȥ��\n\n"NOR, me);
		me->unconcious();
		}
	else {
		me->receive_damage("qi", 200);
		message("vission", HIR "\nֻ���ú��һ����һ���ʯ������������\n\n" NOR, environment(me));
		}
		


	return 1;
}

/*
int regenerate()
{
set("not_generating_jingbubang", 0);
return 1;
} */

