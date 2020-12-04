// Room: /d/tianshui/cross.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "С��㳡");
	set("long", @LONG
������С��������룬һ���Ͽ����Ĺ㳡������ʯ���ŵ��档
�����������ǳ����֡�һ�Ը�Ů�������������գ�����ʯ�����
���ɣ��м�һ��ϸ����(rope)�������������СŮ��һ����Ծ��
��������ӯ���������������߶���Χ�۵����Ƿ���һ����Ľк�
�������Ϸ�����һ�Ŵ��������˵�Ѿ��Ѿ����������ٶ��꣬��
�����С����ʷ�ļ�֤��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wroad1",
  "north" : __DIR__"nroad1",
  "south" : __DIR__"sroad1",
  "east" : __DIR__"eroad1",
]));

	set("item_desc",([
	"rope" : "��Ҳ������ȥ����(zou)���ԡ�\n",
	"����" : "��Ҳ������ȥ����(zou)���ԡ�\n",
]));

	set("objects",([
	__DIR__"npc/yiren" : 1,
	__DIR__"npc/yi_girl" : 1,
	__DIR__"npc/cleaner" : 1,
]));
	set("outdoors","tianshui");
	setup();
}

void init()
{
	add_action("do_zou",({ "zou","jump"}));
}

int do_zou(string arg)
{
	object me,m_obj;
	int level;
	me = this_player();
	if(!arg) return 0;
	if( arg != "����" && arg != "rope" && arg != "����")
	{
		write("��Ҫ��ʲô��\n");
		return 1;
	}
	if(me->is_busy())
		return notify_fail("������æ��");
	if( me->query_temp("on_rided") )
	{
		write("����������������\n");
		return 1;
	}
	if(me->query("qi") < 20) {
		message_vision("$N�λ����ƵĲ������ӣ��������ͨ��һ�µ��������������Ǳ�����һ���Ц��\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("qi",20);
	me->start_busy(1);
	if( !me->query_skill("dodge", 1) )
	me->set_skill("dodge", 0);
	level = me->query_skill("dodge",1);

	if( level < 20) {
		if(random(10) < 4){
		message_vision("$NС�ĵز������ӣ����������ţ�һ��ûע�����������������һ����...������\n",me);
		return 1;
		}
		me->improve_skill("dodge",(int)me->query("int")/6+level/2);
		message_vision("$N�������ӣ�С�ĵ�����һ�ˣ�����һ������������\n",me);
		message_vision("�������������кã���öͭǮ������������\n",me);
		m_obj = new(COIN_OB);
		m_obj->set_amount(10);
		m_obj->move(this_object());
		return 1;
	}

	if( level < 50) {
		if(random(10) < 3){
		message_vision("$Nһ��������ʯ���������������˹�ȥ��һ��С�紵��$N����������������һ����...������\n",me);
		return 1;
		}
		me->improve_skill("dodge",(int)me->query("int")/6+level/2);
		message_vision("$Nһ��������ʯ���������������ɵ�����һ�ˣ�����һ������������\n",me);
		message_vision("����������һ��кã�Ǯ������������������\n",me);
		m_obj = new(COIN_OB);
		m_obj->set_amount(20);
		m_obj->move(this_object());
		return 1;
	}

	message_vision(HIC "$Nһ����������������ʯ������ӯ��������������һ�ˡ�\n" NOR,me);
	message_vision(HIC "������һ����$N���ƺȲʣ�����\n" NOR,me);
	me->receive_damage("qi",50);
	return 1;
}