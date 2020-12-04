// zhang. ���ϰ�

inherit NPC;

void create()
{
	set_name("���ƹ�", ({ "zhang zhanggui", "zhang", "zhanggui" }));
	set("title", "����ƹ��ϰ�");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "����");
	set("age", 45);
	set("long", "���ƹ������￪�ƹݻ�û�ж೤ʱ�䡣\n");
	set("combat_exp", 2000);
	set("inquiry", ([
		"name" : "�͹�������ʲô����С�����ƹ�ͺá�",
		"rumors" : "��˵�и���������ʲôʮ�˵�Խ���ˣ��ٸ�����׽�á�",
		"here" : "������������ѽ���͹�����Ȼ��֪����",
		"������" : "�������������ѽ���͹����ⲻ������ë¿��ë¿��",
		"�һ���": "��˵�Ƕ����ϵ�С���������ݵĶ����ߣ������߿��ܲ��ܹʹ��ɣ�",
		"����" : "������һ���һ��࣬����õúܡ�",
	]) );
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	setup();
}

void init()
{	
}

int accept_object(object who, object ob)
{
	int pay, value;

	if (ob->query("money_id")) {
		if (!(pay = who->query_temp("total_pay"))) {
			tell_object(who, "���ƹ�æ������Ц�������͹����ֲ�ǷС���Ǯ���ͱ�����ͷ��Ѱ�����ˡ���\n");
			return 0;
		}
		if (!who->query_temp("to_pay")) {
			tell_object(who, "���ƹ�˵�������͹����Ƚ���(pay)�ٸ����\n");
			return 0;
		}
		value = ob->value();
		if (value >= pay) {
			who->delete_temp("to_pay");
			who->delete_temp("total_pay");
			if (value == pay) message_vision("���ƹ���������Ц����$N����������л�͹��������ߺá���\n", who);
			else message_vision("���ƹ���������Ц����$N����������л�͹�����С�ѣ��϶��������������ˣ����ߺá���\n", who);
			return 1;
		}
		else {
			pay -= value;	
			message_vision("���ƹ����$N˵����������������" + chinese_number(pay) + "�ġ���\n", who);
			who->set_temp("total_pay", pay);
			return 1;
		}
	}
	return 0;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N��ɥ�ط������ƹ���ڸ߸ߵĹ�̨���棬��������\n", ob);
}

void unconcious()
{
	say( "���ƹ��һ�������Ҳ����ˣ��������ң���\n");
	say( "����ӹ�̨�������һ��Сͯ���������ƹ����������һ��ҩ������ˡ�\n");
	say( "Ƭ��֮�䣬���ƹ��ָֻ��˾��񣬡��ٺ١���Ц��������\n");
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
}

void die()
{
	unconcious();
}

