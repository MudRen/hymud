// dabaiyuan.c
// By jpei

inherit NPC;

int do_cut(string arg);

void create()
{
        set_name("���Գ", ({ "da baiyuan", "da", "baiyuan", "yuan" }) );
        set("race", "Ұ��");
        set("age", 54);
        set("long", "һֻ�����Ű�ë����Գ������ŧѪģ��������һ���󴯡�\n��ϸ���ŷ��֣��������ϵ�ͻ���Ǳ��������߷���ʲô��ȥ��������Ҫ����֮�����С�\n");

        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 100000);
    	set("str", 36);
	set("cor", 30);
	set("dex", 30);
       set("max_qi", 5500);
	set("max_jing", 5220);
	set("neili", 5000);
	set("max_neili", 5000);
	set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 10);

        setup();
	if (clonep()) call_out("disappear", 180);
}

void init()
{
	add_action("do_cut", ({"cut", "sever", "ge", "heal", "zhi", "yizhi", "zhiliao"}));
	::init();
}

void disappear()
{
	message_vision("$N������ã�Ҳû���˾������������ȥ�ˡ�\n", this_object());
	destruct(this_object());
}

int do_cut(string arg)
{
	int i;
	object thread, yaocao,who,fang;
	object me = this_player();
	who=me;

	if (id(arg)) {
		if (!present("sharp rock", me))
			return notify_fail("��ϧ����ͷû�е�����\n");
		if (!present("fish bone", me) || !thread = present("xi si", me))
			return notify_fail("��ϧ����ͷû�����ߡ�\n");
		if (!yaocao = present("yao cao", me))
			return notify_fail("��ϧ����ͷû�в�ҩ��\n");


      if(!query("iskillok"))
      {
      message_vision("ͻȻ����Χ������������ �Ѿ����澭��������!\n",who);	
      	fang = load_object(__DIR__"zhu-changling");
	fang->move(environment(who));	
	fang->kill_ob(who);
     this_object()->set("iskillok",1);
     set("iskillok",1);
      return 1;
      }	

      if(who->is_fighting())
      {
      message_vision("������æ!\n",who);	
      return 1;
      }	
   if(who->query("jinyong/book12")==2 && who->query_temp("book1233"))
{
		i = 1250+random(2000);
		who->set("jinyong/book12",3);
		who->add("combat_exp",i+13000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		tell_object (who,"��Ӯ����"+chinese_number(i+13000)+"�㾭��"+
		           chinese_number(i*18)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		who->save();
}
		destruct(thread);
		destruct(yaocao);
		remove_call_out("disappear");


if (!me->query("jiuyangget"))
{
		new("/d/fairyland/obj/jiuyang-zhenjing")->move(me);
		new("/d/fairyland/obj/pantao")->move(me);
		write("���ü�ʯ�������Գ�Ǹ��Ϸ첹��֮����ֻ�����澹����һ���Ͳ���������һ������һ�׾��顣\n");
		write("��ʱ����������ϸ��飬æ���뻳�С�Ȼ����������룬��Ƥ��ɵ�ϸ˿���ߣ���ǿ�����˰�Գ���˿ڡ�\n");
		write("��Ѳ�ҩ�����˸��������˴�����Գʮ�ָм��㣬������һ�������Ĵ���ң�Ȼ�����ˡ�\n");
                me->set("jiuyangget",1);
                me->set("jiuyangok",1);
 }
      		call_out("leavet",1);
	}
	return 0;
}
void leavet()
{
        object ob = this_object();
 //message_vision("$N����������ȥ��\n" NOR,this_object());
        destruct(this_object());
}  