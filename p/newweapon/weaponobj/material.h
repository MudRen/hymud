// Creat by Ciwei@SJ

#include <ansi.h>

nosave mapping essence = ([
"weapon":({
([
	"name":                     HIW"���",
	"id":                       ({"youyu","jade","yu"}),
	"long":                     "����һ��ʮ��ϸ�����ܵ���񣬿���ȥ��֬����,������ࡣ\n",
	"weight":                   2500,
	"unit":                     "��",
	"level":                    1,
	"value":                    ({50000,30000}),
	"damage":                   ({1,30}),
	"status":                   ({0,2}),
]),
([
	"name":                     YEL"����",
	"id":                       ({"duyu","jade","yu"}),
	"long":                     "����һ�顰��ɽ�񡱣�����ȥ�����ʣ��ʵ�ϸ�壬��Ӳ���ܡ�\n",
	"weight":                   2500,
	"unit":                     "��",
	"level":                    2,
	"damage":                   ({10,30}),
	"status":                   ({1,2}),
	"value":                    ({80000,40000}),
]),
([
	"name":                     HIY"����",
	"id":                       ({"nanyu","jade","yu"}),
	"long":                     "����һ���ʼ���΢�ܵ����񣬿���ȥϸ�����󣬹���͸����ɫ��߲�½�롣\n",
	"weight":                   2500,
	"unit":                     "��",
	"value":                    ({120000,50000}),
	"level":                    4,
	"damage":                   ({20,30}),
	"status":                   ({2,2}),
]),
([
	"name":                     HIB"����",
	"id":                       ({"miyu","jade","yu"}),
	"long":                     "����һ���ʵؽ�Ӳ�����񣬿���ȥϸ�壬ɫ�����ޡ����ȣ��������ʣ�������Ȼɫ�ʡ�\n",
	"weight":                   2500,
	"unit":                     "��",
	"value":                    ({170000,60000}),
	"level":                    6,
	"damage":                   ({30,40}),
	"status":                   ({2,3}),
]),
([
	"name":                     GRN"������",
	"id":                       ({"fengleiyu","jade","yu"}),
	"long":                     "����һ����ɫ�����������ķ����񣬿���ȥ�������ʵ�ϸ�塣\n",
	"weight":                   2500,
	"unit":                     "��",
	"value":                    ({200300,70000}),
	"level":                    8,
	"damage":                   ({40,80}),
	"status":                   ({3,3}),
]),
([
	"name":                     HIY"������",
	"id":                       ({"longlingyu","jade","yu"}),
	"long":                     "����һ���ڽ������������ۣ�������צ����͸�λꡣ\n",
	"weight":                   2500,
	"unit":                     "��",
	"value":                    ({400300,90000}),
	"level":                    10,
	"damage":                   ({50,80}),
	"status":                   ({4,2}),
]),
}),
"armor":({
([
	"name":                     HIW"���",
	"id":                       ({"banyu","jade","yu"}),
	"long":                     "��ϸ΢�ߵ㣬�����ڻ�����Ȫ��С������\n",
	"weight":                   2500,
	"unit":                     "��",
	"level":                    1,
	"value":                    ({50000,30000}),
	"armor":                   ({1,10}),
	"status":                   ({0,2}),
]),
([
	"name":                     YEL"����",
	"id":                       ({"liuyu","jade","yu"}),
	"long":                     "ͨ��������������ͣ������Ը���������ʯ��\n",
	"weight":                   2500,
	"unit":                     "��",
	"level":                    2,
	"armor":                   ({5,15}),
	"status":                   ({1,2}),
	"value":                    ({80000,40000}),
]),
([
	"name":                     HIY"֬��",
	"id":                       ({"zhiyu","jade","yu"}),
	"long":                     "����������֬����Ħ��ȥ�����鶯����������������\n",
	"weight":                   2500,
	"unit":                     "��",
	"value":                    ({120000,50000}),
	"level":                    4,
	"armor":                   ({10,20}),
	"status":                   ({2,2}),
]),
([
	"name":                     HIB"������",
	"id":                       ({"xiangniyu","jade","yu"}),
	"long":                     "͸��һ�����������ʯ���·�����Ů�·������˼�����\n",
	"weight":                   2500,
	"unit":                     "��",
	"value":                    ({170000,60000}),
	"level":                    6,
	"armor":                   ({20,30}),
	"status":                   ({2,3}),
]),
([
	"name":                     GRN"������",
	"id":                       ({"lvyusui","jade","yu"}),
	"long":                     "����һ����ɫ�����������������裬����ȥ�������ʵ�ϸ�塣\n",
	"weight":                   2500,
	"unit":                     "��",
	"value":                    ({200300,70000}),
	"level":                    8,
	"armor":                   ({35,40}),
	"status":                   ({3,3}),
]),
([
	"name":                     GRN"�����",
	"id":                       ({"fenglingyu","jade","yu"}),
	"long":                     "���������죬Ʈ��������һ�������˼���Ʒ��\n",
	"weight":                   2500,
	"unit":                     "��",
	"value":                    ({400300,90000}),
	"level":                    10,
	"armor":                   ({45,40}),
	"status":                   ({4,2}),
]),
}),
]);

void init()
{
	add_action("do_combine", "combine");
}

int do_combine(string arg)
{
	int i,j,k;
	object *inv, gem, me = this_player(),newgem;

	if (!arg || arg == "")
		return notify_fail("����ϲ�ʲô���ϣ�\n");
	if (arg != query("id")) return 0;
	if (query("level") == 6)
		return notify_fail("��������Ѿ�����ߵȼ��ˣ�\n");
	if (me->query("max_neili") < 800 || me->query("neili") < 800)
		return notify_fail("�������ڵ�������Ϊ�����޷��˹��ϲ����ϣ�\n");

	inv = all_inventory(me);
	for(i = 0; i < sizeof(inv); i++)
		if (inv[i] != this_object() && inv[i]->query("id") == query("id")) {
			if (!objectp(gem))
				gem = inv[i];
			else {
				message_vision(HIG"$N����������͸ȫ������" + name() + HIG"�������������
������$N�ջ���������ֻ��" + name() + HIG"�ƺ���ø��������ˣ�\n", me);
				me->add("max_neili", -200);
				me->add("neili", -200);
				me->start_busy(1);
j=query("level");
j=j+1;
if (query("ayushi")==1)
	{
j=j+6;
}
j=j+1;
k=3;
if (j >=2) k=5;
if (j >=3) k=6;
if (j >=4) k=8;

if (random(k)==0)
{
           newgem = new("/p/newweapon/weaponobj/material"+j);
           newgem->move(me);
message_vision(HIG"��$N�������� " + name() + HIG"Ʒ�ʵõ����������"+newgem->query("name")+"\n"NOR, me);
//				new_gem(query("material"), query("level") + 1)->move(me);
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
	return notify_fail("�����������ͬ���Ĳ��ϲ��ܽ��кϲ���\n");
}
