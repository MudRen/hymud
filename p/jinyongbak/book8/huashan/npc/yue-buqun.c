
inherit NPC;
#include <ansi.h>;
int ask_me();

void create()
{
        set_name("����Ⱥ", ({ "yue buqun", "yue" }) );
        set("title", "��ɽ������");
        set("nickname", "���ӽ�");
        set("gender", "����");
        set("class", "swordsman");
        set("age", 55);
        set("long",
                "����Ⱥ����ִ�ƻ�ɽ�ɣ��˵���������һ��һ�ĸ��֡�\n");
        set("attitude", "peaceful");
        set("str", 56);
        set("con", 50);
        set("dex", 50);
        set("int", 58);

    set("guard/flag", 1);
    set("guard/ok", 1);
    set("qi", 150000);
    set("max_qi", 150000);
    set("jing", 150000);
    set("max_jing", 150000);
    set("neili", 150000);
    set("max_neili", 150000);
    set("jiali", 200);

    set("combat_exp", 24500000);
    set("score", 0);

	set_skill("cuff", 500);
	set_skill("strike", 500);
	set_skill("force", 500);             // �����ڹ�
	set_skill("finger", 500);            // ����ָ��
	set_skill("unarmed", 500);           // ����ȭ��
	set_skill("dodge", 500);             // ��������
	set_skill("parry", 500);             // �����м�
	set_skill("sword", 500);             // ��������
	set_skill("pixie-jian", 500);        // ��а����
	set_skill("changquan", 500);         // ̫�泤ȭ
	set_skill("literate", 100);          // ����ʶ��
	set_skill("kuihua-xinfa", 500);      // �����ķ�
	set_skill("kuihua-dafa", 500);      // ������
	set_skill("kuihua-feiying", 500);      // ������
	set_skill("tmzhang", 500);
	set_skill("staff", 500);
	set_skill("tmjian", 500);
	set_skill("tmdao", 500);
	set_skill("pmshenfa", 500);
	set_skill("cuff",500);
	set_skill("blade", 500);
	set_skill("tmdafa", 500);
	set_skill("tmquan", 500);       
	map_skill("force", "kuihua-xinfa");
	map_skill("sword", "kuihua-dafa");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "kuihua-feiying");
	map_skill("parry", "pixie-jian");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tonggui" :),
                (: perform_action, "sword.pi" :),
                	(: perform_action, "sword.yinrou" :),
                (: perform_action, "sword.po" :),
                (: perform_action, "sword.gui" :),
                (: perform_action, "parry.cimu" :),
                (: perform_action, "parry.huanying" :),
                (: perform_action, "parry.sanlianci" :),
                (: perform_action, "dodge.kuihuashenzhang" :),
                (: perform_action, "dodge.feiying" :),
                (: perform_action, "dodge.jue" :),
                (: perform_action, "unarmed.yuhuan" :),
                (: exert_function, "powerup" :),
                (: exert_function, "kuihuawudi" :),
                (: exert_function, "powerup" :),                
        }) );
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 900);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        
        create_family("��ɽ��", 13, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if(((int)who->query("jinyong/book8")>=11))
	{
//::die();	
	}
        else if(who) {
        	message_vision("$N˵���������ܣ��ⲻ���ܣ���а���������޵У���ô�ᱻ���ܣ�\n" NOR,this_object());
		i = random(5000);
		who->set("jinyong/book8",11);
		who->add("combat_exp",i+30000);
		who->add("potential",i*45);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
		tell_object (who,"��Ӯ����"+chinese_number(i+30000)+"�㾭��"+
		           chinese_number(i*45)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		message("channel:chat", HIB"������III����˵"+who->name() + "�����Ц����������������!"NOR"\n", users());
		who->save();
        }
	::die();
}
