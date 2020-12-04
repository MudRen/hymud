
// guard.c

#include <ansi.h>

inherit NPC;

int ask_me(object who);

void create()
{
	set_name("����»", ({ "liu anru", "liu" }) );
	set("title", "�ŷ�");
	set("gender", "����" );
	set("age", 26);
	set("str", 29);
	set("cor", 20);
	set("cps", 4);
	set("int", 11);
	set("long",
		"����»�Ǵ�����ݵ��ŷ������˹���������û����֪�����ĳ���������ֻ֪\n"
		"���������ղ�����һ�ֿ쵶����һ�����е��֡�\n" );
	set("combat_exp", 20000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"����»˵�����㵱������ʲ��ط�������������Ұ��\n",
		"����»˵������������....��....�������������ݵ�СС���ŷ���������ʰ�㣡\n",
		"����¼��Ȼ�ӳ�һ�����������棬���ǵ�����;��Ȼ��������ʲ�ᣬ��æ���С�\n",
		"����»˵��������߰ɣ���������������....\n"
	}) );
	set("inquiry", ([
  "������": (: ask_me :),
		"Ѫ��������": (: ask_me :)
	]) );

	set_skill("blade", 140);

	set_skill("parry", 140);
	
	setup();
	
	carry_object(__DIR__"obj/blade")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_me(object who)
{
	int i;
	object *ob;

	if( query("revealed") ) {
        if( is_killing(who) ) return notify_fail("���Ȼ֪�����ҵ���֣��������������\n");
		else {
			kill_ob(who);
			who->fight_ob(this_object());
            return notify_fail("���Ӿ���Ѫ��������Ѫ���������������ӣ���������\n");
		}
	}

	if( (random(10) < 2)
|| who->query("combat_exp") < 20000)
// by arboc   ||  !is_fighting() )
        return 0;

	set_temp("apply/attack", 70);
	set_temp("apply/dodge", 50);
	set_temp("apply/parry", 60);
	set_temp("apply/damage", 20);
	set("title", "Ұ��ɽկ��կ��");
	set("nickname", HIR "Ѫ������" NOR);
	message("vision",
		HIY "����»����ͻȻ�ų������Ĺ�â������˵��������...�㶼֪���ˣ�\n\n"
		"����»���һ�����е�����Ȼ��ˣ����ӽ�����ȥ�ˣ���������\n" NOR
		"����»ʹ���������������棬���ͺ������͸ղż�ֱ�������ˣ�\n",
		environment(), this_object() );
	set("pursuer", 1);
       set("shen_type",-1);
	set("attitude", "aggressive");
	set("vendetta/authority", 1);
	set("chat_msg_combat", ({
		(: random_move :)
	}) );
	set("chat_chance", 60);
	set("chat_msg", ({
		(: random_move :)
	}) );
	set("bellicosity", 200000);
	set("combat_exp", 500000);
	ob = all_inventory(environment());
	for(i=sizeof(ob)-1; i>=0; i--) {
		if( !ob[i]->is_character() || ob[i]==this_object() ) continue;
		kill_ob(ob[i]);
		ob[i]->fight(this_object());
	}
	carry_object(__DIR__"obj/blade_book");
	set("revealed", 1);
    return 1;
}

