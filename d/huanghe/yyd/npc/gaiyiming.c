// gaiyiming.c ��һ��
// zly 7/6/99

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��һ��", ({"gai yiming", "gai", "yiming"}));
	set("title", HIY"̫������"NOR);
	set("nickname", "�˲��ϲ�����ר�̤ѩ�޺ۡ�����ˮ�Ϸɡ�˫�̸���ʡ");
        set("shen_type", 1);
	set("gender", "����");
	set("age", 36);
	set("long", 
"���˿�������С�������°ͼ�������������һ�Զ�ü�ִ̡�\n"
	);

	set("attitude", "aggressive");
        set("vendetta/authority",1);
	
	   set("qi", 23900);
        set("max_qi", 23900);
        set("jing", 23900);
        set("max_jing", 23900);
        set("neili", 41500);
        set("max_neili", 41500);
        set("jiali", 50);

        set("combat_exp", 8500000);
        set("score", 200000);
        set_skill("force", 370);
        set_skill("unarmed", 300);
        set_skill("dodge", 350);
        set_skill("parry", 350);
        set_skill("hand",370);
        set_skill("staff", 370);
        set_skill("taixuan-gong", 250);
set_skill("huanhe-dao", 350);
set_skill("sata-shenfa", 350);
set_skill("sumi-jian", 280);
set_skill("wuyu-quan", 350);
set_skill("xiuli-qiankun", 350);
set_skill("strike", 250);
set_skill("cuff", 250);
set_skill("unarmed", 250);
set_skill("blade", 350);
set_skill("sword", 350);
set_skill("club", 280);
set_skill("bawang-qiang", 280);
map_skill("sword", "sumi-jian");
//map_skill("blade", "huanhe-dao");
map_skill("strike", "xiuli-qiankun");
map_skill("cuff", "wuyu-quan");
      map_skill("force", "taixuan-gong");
        map_skill("dodge", "sata-shenfa");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
set_skill("club", 280);
set_skill("bawang-qiang", 280);

    	prepare_skill("strike", "xiuli-qiankun");
	prepare_skill("cuff", "wuyu-quan");

        
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "sword.dieying" :),
                (: perform_action, "sword.feiwu" :),
                (: perform_action, "sword.jiushi" :),
                (: perform_action, "sword.jiushi" :),                	
                (: perform_action, "sword.ruhe" :),
                (: perform_action, "sword.shenfeng" :),                	
                (: perform_action, "sword.wuyun" :),                	                	                	                	
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
                
        }) );
		
	map_skill("force", "huntian-qigong");

        set("chat_chance", 3);
        set("chat_msg", ({
            "��һ��һ�ڶ��Ҵ̣�ϸ��ϸ���ص���������ʲô�������͸��������°ɣ���\n",
            "��һ��˵�����������ֵ����������������壬ר�ų�ǿ�������ٸ�
��ƶ���������˳ƴ��������ġ�̫������������\n", 
     }) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();

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

  	if((int)who->query("jinyong/book14")==2 && who->query_temp("book143") )
{
		//message_vision("$N˵����̫������ ������Ź���ģ�\n" NOR,this_object());
		i = 380+random(2000);
		who->set("jinyong/book14",3);
		who->add("combat_exp",i+8000);
		who->add("potential",i*19);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
		tell_object (who,"��Ӯ����"+chinese_number(i+8000)+"�㾭��"+
		           chinese_number(i*19)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");

		who->save();
}
        
message_vision("$N˵�������л۵�����֪���ˣ�����̫��������ȥ�����ģ�\n" NOR,this_object());	
	call_out("leavet",1);
        
	::die();
}




void leavet()
{
        object ob = this_object();
 message_vision("$N����������ȥ��\n" NOR,this_object());
        destruct(this_object());
}