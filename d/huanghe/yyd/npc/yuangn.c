// yuangn.c Ԭ����
// zly 99.6.22

#include <ansi.h>
inherit NPC;
string ask_yyd();

void create()
{
        object ob;
        set_name("Ԭ����", ({ "yuan guannan", "yuan", "guannan"}));
        set("gender", "����");
        set("unique", 1);
        set("age", 22);
        set("long", "����һ��Ӣ����������������������ҡ�����ȡ�\n");
        set("attitude", "friendly");
        set("shen", 150000);
        set("env/wimpy", 30);
        set("str", 19);
        set("int", 24);
        set("con", 22);
        set("dex", 26);

        set("qi", 33900);
        set("max_qi", 33900);
        set("jing", 33900);
        set("max_jing", 33900);
        set("neili", 61500);
        set("max_neili", 61500);
        set("jiali", 50);

        set("combat_exp", 8500000);
        set("score", 200000);
        set_skill("force", 370);
        set_skill("unarmed", 300);
        set_skill("dodge", 350);
        set_skill("parry", 350);
        set_skill("hand",370);
        set_skill("staff", 370);
        set_skill("taixuan-gong", 350);

set_skill("huanhe-dao", 380);
set_skill("sata-shenfa", 350);
set_skill("sumi-jian", 350);
set_skill("wuyu-quan", 350);
set_skill("xiuli-qiankun", 350);
set_skill("strike", 250);
set_skill("cuff", 250);
set_skill("unarmed", 250);
set_skill("blade", 350);
set_skill("sword", 350);
set_skill("club", 380);
set_skill("bawang-qiang", 380);
//map_skill("sword", "sumi-jian");
map_skill("blade", "huanhe-dao");
map_skill("strike", "xiuli-qiankun");
map_skill("cuff", "wuyu-quan");
      map_skill("force", "taixuan-gong");
        map_skill("dodge", "sata-shenfa");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
    	prepare_skill("strike", "xiuli-qiankun");
	prepare_skill("cuff", "wuyu-quan");

        
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "blade.huan" :),
                	(: perform_action, "blade.kuang" :),
                		(: perform_action, "blade.leitingpili" :),
                			(: perform_action, "blade.shiwanshenmo" :),
                				(: perform_action, "blade.tiandirenmo" :),
                					(: perform_action, "blade.xueyu" :),
                						(: perform_action, "blade.baoxue" :),
                						(: perform_action, "blade.baoxue" :),                							
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
                
        }) );
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 1000);
	set_temp("apply/damage", 600);

        set("chat_chance", 3);
        set("chat_msg", ({
            "Ԭ���г������������ƽ����ֿ��⾡�������Ʋ���ƶ���ɷ���¿�Х������֪��ȴͷ�Ͻ�......��\n",
            "Ԭ����������������������Ӣ�������½̶��ܣ�������Ʒ��Ψ�ж����......��\n", 
        }) );

        set("inquiry", ([
//           "���޵���"  : (: ask_yyd :),
        ]));

        setup();
        if (clonep()) {
                ob = new(__DIR__"obj/yuan");
                //ob = new("/clone/weapon/gangdao");
                ob->move(this_object());
                ob->wield();
        carry_object(__DIR__"obj/changpao")->wear();        
        add_money("gold",1);
   }
}

/*string ask_yyd()
{
        object me=this_player();
        if(me->query_skill("blade", 1) <120)
                return "���Ȱѵ����Ļ��������˵�ɡ�\n";
        if(me->query("fuqi"))
                return "�ף��㲻���Ѿ�ѧ���˷��޵�������\n";
        if(me->query_temp("mb"))
                return "�ף��Ҳ��ǸղŸ���������\n";
        me->set_temp("mb",1);
        command("hmm");
        command("whisper "+me->query("id")+" ��ʦ��ʦĸ˵�������ǵ����ĸ�ɮԲ���ڼ��ϵ�С���ϡ�");
        return "����޵������ǵ���һλ��ɮ�����ҵ�ʦ���ģ�������������ĺ���������ȥ����λ��ɮ�ɣ�\n";
}
*/
void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
 who->set_temp("book145",1);
	::die();
}                                                                        