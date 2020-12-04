// feng-buping.c  �ⲻƽ
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("�ⲻƽ", ({ "feng buping", "feng" }) );
        set("nickname", YEL"���콣"NOR);
        set("gender", "����");
        set("class", "swordsman");
        set("title", "��ɽ���ڵ�ʮ��������");
        set("age", 45);
        set("long",
                "�ⲻƽ�ǻ�ɽ���ڵ�һ���֣���������һ�Żƽ�������Ƥ��\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        set("neili", 30000);
        set("max_neili", 30000);
        set("jiali", 30);
        set("max_qi",30000);
        set("max_jing",30000);

        set("combat_exp", 5000000);
        set("shen", -200000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
              (: perform_action, "sword.feilong" :),
                (: perform_action, "sword.kuangfeng" :),
                (: perform_action, "sword.kuanglong" :),
                (: perform_action, "sword.sao" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),   
                (: exert_function, "powerup" :),
        }) );
     
        set_skill("zixia-shengong", 300);
        set_skill("unarmed", 300);
        set_skill("strike", 300);
        set_skill("sword", 300);
        set_skill("force", 300);
        set_skill("parry", 300);
        set_skill("dodge", 300);
        set_skill("literate", 300);
        set_skill("huashan-sword", 300);
        set_skill("kuangfeng-jian", 300);
        set_skill("huashan-neigong", 300);
        set_skill("huashan-ken", 300);
        set_skill("huashan-zhangfa", 300);
        set_skill("huashan-shenfa", 300);
        set_skill("zhengqijue",200);
        map_skill("sword", "kuangfeng-jian");
        map_skill("parry", "kuangfeng-jian");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-zhangfa");
        map_skill("dodge", "huashan-shenfa");

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
 	if(((int)who->query("jinyong/book8")>=5))
	{
//::die();	
	}
        else if((who)&& ((int)who->query("jinyong/book8")==4)) {
		i = random(1400);
		who->set("jinyong/book8",5);
		who->add("combat_exp",i+16000);
		who->add("potential",i*14);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
		tell_object (who,"��Ӯ����"+chinese_number(i+16000)+"�㾭��"+
		           chinese_number(i*14)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		who->save();
        }
	::die();
}
