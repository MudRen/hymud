#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "�峤��");
  set ("long", @LONG
�����Ǵ峤�ļң�����ȴ����Ϊ���أ�ǽ�߿��ż���ũ�ߣ�
ǽ��һ���񴲣����ž�������˯��������ָ�� sleep��������
ͨ�����ûʲô����ƽ�������Ƕ��˿��Ե�����Ҫ ������
ָ�� yao��Щʳ��������������һ�����ʦ��æ����ͷ��
�����ݽǷ���һ����ˮ�ס�  
LONG);
  set("exits", ([ /* sizeof() == 2 */

"south" : __DIR__"new1",

]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chushi" : 1,
 
]));
//  set("outdoors","welcome");
  set("sleep_room", 1);
set("roomif","$botten#Ҫʳ��|˯��:yao|sleep$#");

  set("no_beg", 1);
  set("pingan",1);
  set("no_fight", 1);
  set("chatroom",1);
  setup();
  //replace_program(ROOM);
}

void init()
{
	add_action("do_naqu","yao");
}


int do_naqu(string arg)
{
	object me,sth;
	mapping data;
	me=this_player();
	if(! living(me))	return 0;
	//if(! arg)	return notify_fail("��Ҫ��ȡʲô��\n");
	if(me->query("combat_exp",1) > 80000 && !wizardp(me) && me->query("nbjob",1)!=3 )
{
message_vision("��ʦЦ����$N�㵽�����Լ�ȥ��ɡ�\n",me);
		return 1;
}
 if (present("mantou",me)) 
{
message_vision("��ʦЦ����$N�Ȱ����ϵĳ��������ɡ�\n",me);
return 1;
}


 if (present("water",me)) 
{
message_vision("��ʦЦ����$N�Ȱ����ϵĺ��������ɡ�\n",me);
return 1;
}
me->set("food",100);
me->set("water",100);
me->set_temp("nbjob4",1);
sth=new(__DIR__"obj/mantou");
sth->move(me);
sth=new(__DIR__"obj/water");
sth->move(me);
message_vision("��ʦ��һ����ͷ��һ����ˮ�ݵ�$N���У�Ц���������á�\n",me);
	return 1;
}