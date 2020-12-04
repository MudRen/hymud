// /d/yixing/npc/cl_bei.c ����ʯ
// Last Modified by winder on Jul. 12 2002
#include <ansi.h>;
inherit NPC;
int ask_me();
#include <ansi.h>

void create()
{
	set_name("����ʯ", ({ "bei haishi", "bei" }));
	set("nickname", HIG"���ֳɴ�"NOR);
	set("party/party_name", HIC"���ְ�"NOR);
	set("party/rank", "�ܹ�");
	set("long", 
		"����һ�������������ˣ�����ȥ��ɫ�԰ף�˵������������\n"
		"����ͣ�Ŀ����ţ��������ز�һ�㡣\n");
	set("gender", "����");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);

  set("qi", 38000);
        set("max_qi", 38000);
        set("jing", 38000);
        set("max_jing", 38000);
        set("neili", 51500);
        set("max_neili", 51500);
        set("jiali", 50);
        set_skill("parry", 380);
	set_skill("force", 380);
	set_skill("unarmed", 380);
	set_skill("dodge", 380);
	set_skill("taixuan-gong", 550);
	set_skill("feixian-steps", 580);
	set_skill("shenzhao-jing", 580);
	map_skill("force", "shenzhao-jing");
	map_skill("parry", "taixuan-gong");
	map_skill("unarmed", "shenzhao-jing");
	map_skill("dodge", "feixian-steps");
        set("combat_exp", 3500000);
        set("score", 200000);
set("max_neili",50000);
        set("neili",50000);
        set("max_qi",36800);
        set("max_jing",36800);
        set("jing",36800);
        set("qi",36800);
        set("eff_jingli",38000);
        set("jingli",38000);
        set("jiali",100);
	set("szj/passed", 1);
	set("szj/over200", 1);
	set("book_count", 1);
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "unarmed.wu" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
               
        }) );
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 2000);
	set_temp("apply/damage", 2000);


	set("inquiry", ([
		"���ְ�" : "���ְ�ľ������������ܹܡ�",
		"���" : "��ȥ�ʰ����ɡ�",
		"�书" : "�������˼ҵ��书����ǿ���ˣ��㻹�������ѧ�ɡ�",
		"����" : "��λ�����������ɰ������˼�˵���㡣",
		"˾ͽ��" : "�Ҷ����ǰ������˼ҵľ���֮�飬�������Ͻ�ˮ���಻����",
		"����" : "�ҼҰ���˾ͽ��ү�������ϵġ������족Ҳ��",
	"ʯ����" : (: ask_me :),
	]));

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

int ask_me()
{
	int i;
        object ob;
	object who = this_player();
	object where = environment(who);
	if(!who->query_temp("book1131"))
	{
		message_vision("$N��$n˵���� ʯ������˭�� �Ҳ�֪���ˡ�\n",this_object(),who);
  
		return 1;	
	}

	if(!who->query_temp("book1132"))
	{
		message_vision("$N��$n˵���� չ������ͽ�Ļ�����Ҳ��?\n",this_object(),who);
  
		return 1;	
	}
message_vision("$N��$n��Ȼ��һ�ж�֪���ˣ����ȥ���ɡ�\n",this_object(),who);
who->set_temp("book1133",1);
kill_ob(who);                    
	return 1;
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
  	if(((int)who->query("jinyong/book11")>=3))
	{
//::die();	
	}
        else if(who) {
  	if(((int)who->query("jinyong/book11")==2) && who->query_temp("book1133"))
{
		message_vision("$N˵�����Ҳ���ܵģ��� �� ���������ǰ׳���������ұ���ġ�\n" NOR,this_object());
		i = 500+random(1000);
		who->set("jinyong/book11",3);
		who->add("combat_exp",i+12000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		tell_object (who,"��Ӯ����"+chinese_number(i+12000)+"�㾭��"+
		           chinese_number(i*18)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		who->save();
}
        }
	::die();
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      