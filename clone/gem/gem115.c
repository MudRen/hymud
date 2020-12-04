// gems - by xbd

#include <ansi.h>

inherit ITEM;
inherit F_GEMS;

void create()
{
	int lev, i,j,fn;
	string gem, s;
	object me = this_player();

	i = 11;
	lev=5;
	if (i == 1) gem = "ruby";
	else if (i == 2) gem = "topaz";
	else if (i == 3) gem = "sapphire";
	else if (i == 4) gem = "emerald";
	else if (i == 5) gem = "amethyst";
	else if (i == 6) gem = "windjade";
	else if (i == 7) gem = "firejade";
	else if (i == 8) gem = "icejade";
	else if (i == 9) gem = "thunderjade";
	else if (i == 10) gem = "earthjade";
	else if (i == 11) gem = "diamond";
	else gem = "skull";

	

	set_name(query_gem_name(gem, lev), ({query_gem_id(gem, lev)}));
	set_weight(100);
	set("long", query_all_effect(gem));
	set("unit", "��");
	set("no_put",1);
       set("treasure",1);       
//	set("no_get",1);
//	set("no_drop",1);
	set("no_beg",1);
	set("no_steal",1);
//        set("no_clone",1);
        set("no_pawn",0);
            set("treasure",0);	
	set("value", 10000 * lev * lev * lev);
	set("material", gem);
	if (i > 0) i=i*10;set("level", lev);set("lb", i);
	setup();
}

void init()
{
	add_action("do_insert", "insert");
	add_action("do_combine", "combine");
}
int set_level(int lb,int lev)
{       
	int lev2,i;
	string gem, s;
	object me = this_player();

	if (!lb)
{
		 i = random(17);
}
else
{
	i = lb;
}			
	if (i < 1) gem = "ruby";
	else if (i < 3) gem = "topaz";
	else if (i < 5) gem = "sapphire";
	else if (i < 7) gem = "emerald";
	else if (i < 9) gem = "amethyst";
	else if (i < 11) gem = "windjade";
	else if (i < 12) gem = "firejade";
	else if (i < 13) gem = "icejade";
	else if (i < 14) gem = "thunderjade";
	else if (i < 15) gem = "earthjade";
	else if (i < 16) gem = "diamond";
	else gem = "skull";

	if (!i)  i=random(100);
	if (i < 50) lev2 = 1;
	else if (i < 75) lev2 = 2;
	else if (i < 90) lev2 = 3;
	else if (i < 95) lev2 = 4;
	else if (i < 96) lev2 = 5;
	else if (i < 97) lev2 = 6;
	else if (i < 98) lev2 = 7;
	else lev2= 8;

  if (!lev) lev=lev2;


	set_name(query_gem_name(gem, lev), ({query_gem_id(gem, lev)}));
	set_weight(100);
	set("long", query_all_effect(gem));
	set("unit", "��");
	set("no_put",1);
       set("treasure",1);       
//	set("no_get",1);
//	set("no_drop",1);
	set("no_beg",1);
	set("no_steal",1);
//        set("no_clone",1);
        set("no_pawn",0);
            set("treasure",0);	
	set("value", 10000 * lev * lev * lev);
	set("material", gem);
	if (i > 0) i=i*10;set("level", lev);set("lb", i);
        return 1;
}
int do_insert(string arg)
{
	int index;
	string gem, item_name;
	object ob, me = this_player();

	if (!arg || arg == "")
		return notify_fail("ָ���ʽ��insert ��ʯ into ��Ʒ at socket ���\n");
	if (sscanf(arg, "%s into %s at socket %d", gem, item_name, index) != 3)
		return notify_fail("ָ���ʽ��insert ��ʯ into ��Ʒ at socket ���\n");
	if (gem != query("id")) return 0;
	if (!objectp(ob = present(item_name, me)))
		return notify_fail("���������Ƕ��ʲô�����ϣ�\n");

	if (index ==0)
		return notify_fail(ob->name() + "�Ϻ���û������ӿ�ѽ��\n");

	if (index > ob->query("sockets/max"))
		return notify_fail(ob->name() + "�Ϻ���û������ӿ�ѽ��\n");
	if (ob->query("equipped"))
		return notify_fail(ob->name() + "��װ�����أ�\n");
	if (me->query("max_neili") < 1000 || me->query("neili") < 1500)
		return notify_fail("�������ڵ�������Ϊ�����޷��˹���Ƕ��ʯ��\n");

	message_vision(HIG"$N����������һʹ����" + name() + HIG"������" + ob->name() + HIG"�У�
ɲ�Ǽ䣬ֻ��" + ob->name() + HIG"�Ϸ���һ������Ĺ�â���ƺ���һ������������������У�\n", me);
	me->add("max_neili", -100);
	me->add("neili", -1000);
	me->start_busy(2);
	ob->set(sprintf("sockets/socket%d", index), query("material"));
	ob->set(sprintf("sockets/socket%d_level", index), query("level"));

	seteuid(ROOT_UID);
	reload_object(ob);
        seteuid(getuid());
	destruct(this_object());

	return 1;
}

int do_combine(string arg)
{
	int i;
	object *inv, gem, me = this_player();

	if (!arg || arg == "")
		return notify_fail("����ϲ�ʲô��ʯ��\n");
	if (arg != query("id")) return 0;
	if (query("level") == 8)
		return notify_fail("�����ʯ�Ѿ�����ߵȼ��ˣ�\n");
	if (me->query("max_neili") < 500 || me->query("neili") < 800)
		return notify_fail("�������ڵ�������Ϊ�����޷��˹��ϲ���ʯ��\n");

	inv = all_inventory(me);
	for(i = 0; i < sizeof(inv); i++)
		if (inv[i] != this_object() && inv[i]->query("id") == query("id")) {
			if (!objectp(gem))
				gem = inv[i];
			else {
				message_vision(HIG"$N����������͸��ʯ������" + name() + HIG"�������������
������$N�ջ���������ֻ��" + name() + HIG"�ƺ���ø��������ˣ�\n", me);
				me->add("max_neili", -10);
				me->add("neili", -500);
				me->start_busy(1);

if ((random(6)*query("level"))==0)
{
				new_gem(query("material"), query("level") + 1,query("lb"))->move(me);
}
else
{
				message_vision(RED"$N���һ������! " + name() + RED"ͻȻ�ѿ��ˣ�ʧȥ�˹���\n", me);
	
}
				destruct(gem);
				destruct(inv[i]);
				destruct(this_object());
				return 1;
			}
		}
	return notify_fail("�����������ͬ���ı�ʯ���ܽ��кϲ���\n");
}
