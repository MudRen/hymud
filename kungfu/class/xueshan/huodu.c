#include <ansi.h>

inherit NPC;


void create()
{
        set_name("����", ({ "huo du", "huo", "du" }));
        set("long", @LONG
���ǽ��ַ������µĶ����ӡ���÷������洫��
������Ϊ�ɹ����ӣ���λ�������
LONG);
        set("nickname", HIY "�ɹ�����" NOR);
        set("gender", "����");
        set("age", 31);
        set("attitude", "peaceful");
        set("shen_type", -1);

        set("str", 35);
        set("int", 20);
        set("con", 25);
        set("dex", 20);

        set("max_qi", 13200);
        set("max_jing", 12200);
        set("neili", 13800);
        set("max_neili", 13800);
        set("jiali", 120);
        set("combat_exp", 1800000);

        set_skill("force", 180);
        set_skill("longxiang", 180);
        set_skill("dodge", 160);
        set_skill("shenkong-xing", 160);
        set_skill("dagger", 180);
        set_skill("finger", 180);

        set_skill("sword", 160);
        set_skill("mingwang-jian", 260);
        set_skill("hand", 160);
        set_skill("dashou-yin", 220);
        set_skill("cuff", 160);
        set_skill("yujiamu-quan", 220);
        set_skill("parry", 160);
        set_skill("lamaism", 180);
        set_skill("literate", 100);
 
        set_skill("martial-cognize", 160);
        set_skill("magic", 180);
        set_skill("kwan-yin-spells", 180);
        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("parry", "mingwang-jian");
        map_skill("sword", "mingwang-jian");
        map_skill("hand", "dashou-yin");
        map_skill("cuff", "yujiamu-quan");

map_skill("magic", "kwan-yin-spells");
map_skill("cuff", "yujiamu-quan");
map_skill("hand", "dashou-yin");
prepare_skill("cuff", "yujiamu-quan");
prepare_skill("hand", "dashou-yin");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.bei" :),
                (: perform_action, "sword.ruo" :),
                (: perform_action, "sword.xiang" :),			
                (: perform_action, "cuff.chen" :),
                (: perform_action, "cuff.jiang" :),
                (: perform_action, "hand.dashouyin" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),

        }));

        create_family("ѩɽ��", 3, "����");



        setup();

        carry_object("/d/xueshan/obj/gushan")->wield();
        carry_object("/d/city/npc/cloth/fu-cloth")->wear();
}
void unconcious()
{
        die();
}

void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	if(((int)who->query("jinyong/book10")>=1))
	{
//::die();	
	}
        else if(who) {
  	if(!who->query("jinyong/book10") && who->query_temp("qijuok") && who->query("combat_exp",1) >= 800000)
{
		message_vision("$N˵������ �� ����\n" NOR,this_object());
		i = 800+random(2000);
		who->set("jinyong/book10",1);
		who->add("combat_exp",i+9000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
		tell_object (who,"��Ӯ����"+chinese_number(i+9000)+"�㾭��"+
		           chinese_number(i*18)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		who->save();
}
        }
	who->set_temp("book1031",1);
	call_out("leavet",1);
}
void leavet()
{
        object ob = this_object();
 message_vision("$N�����򱱷���ȥ��\n" NOR,this_object());
        destruct(this_object());
}

