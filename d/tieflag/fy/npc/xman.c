 // taolord.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER; 
int leave();
void create()
{
        set_name("�ڴ�", ({ "master xman", "master", "xman" }) );
        set("nickname", HIY"������ʦ"NOR);
        set("gender", "����");
        set("age", 99);
        set("long",
"�ڴ��ǵ�����Ƴǳ���������ʦ�ܣ����ǵ����ʦ���书��ɲ⡣\n"
);                
        set("combat_exp", 100000000);
        set("score", 50000); 
        set("class", "shaolin"); 
        set("str", 100);
        set("int", 100);
        set("cor", 100);
        set("cps", 100);
        set("spi", 100);
                set("fle",      100); 
                set("no_busy", 9);
        set("neili", 88000);
        set("max_neili", 88000);
        set("force_factor", 50);
                set("max_jing",28000);
                set("max_sen",28000); 
/*         set("inquiry", ([
                "̫������": 
"̫���������ؾ���������һ���������֡�\n",
        })); */
        set("apprentice_available", 1);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.yuhuan" :),
                                    
        }) ); 
         set("rank_nogen",1);
        create_family("������", 1, "ʥɮ"); 
        
        set("inquiry", ([
                "leave": (: leave:),
        ]));
        
  set("jing", 38000);
	set("max_jing", 38000);
	set("qi", 38000);
	set("max_qi", 38000);
	set("neili", 98000);
	set("max_neili", 98000);
	set("jiali", 90);
	set("age", 80);
	set("shen_type", 1);
	set("shen", 100000);
	set("str", 150);
	set("int", 50);
	set("con", 50);
	set("dex", 150);
	set("max_qi", 38000);
	set("max_jing", 38000);
	set("neili", 98000);
	set("max_neili", 98000);
	set("jiali", 150);
	set("combat_exp", 9800000);
	set("score", 500000);
 set_temp("fanzhen",1);
	set_skill("buddhism", 500);
	set_skill("literate", 300);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set_skill("unarmed", 300);
	set_skill("blade", 300);
	set_skill("claw", 300);
	set_skill("club", 300);
	set_skill("cuff", 300);
	set_skill("dodge", 300);
	set_skill("finger", 300);
	set_skill("force", 300);
	set_skill("hand", 300);
	set_skill("parry", 300);
	set_skill("staff", 300);
	set_skill("strike", 300);
	set_skill("sword", 300);
	set_skill("whip", 300);

set_skill("weituo-zhang", 380);
set_skill("shaolin-tantui", 380);
set_skill("jingang-zhang", 380);
set_skill("jimie-zhua", 380);
set_skill("duoluoye-zhi", 380);
set_skill("mohe-zhi", 380);
set_skill("boluomi-shou", 380);
	set_skill("banruo-zhang", 380);
	set_skill("cibei-dao", 380);
	set_skill("damo-jian", 380);
	set_skill("fengyun-shou", 380);
	set_skill("fumo-jian", 380);
	set_skill("hunyuan-yiqi", 380);
	set_skill("jingang-quan", 380);
	set_skill("longzhua-gong", 380);
	set_skill("luohan-quan", 380);
	set_skill("nianhua-zhi", 380);
	set_skill("pudu-zhang", 380);
	set_skill("qianye-shou", 380);
	set_skill("sanhua-zhang", 380);
	set_skill("riyue-bian", 380);
	set_skill("shaolin-shenfa", 380);
	set_skill("weituo-gun", 380);
	set_skill("wuchang-zhang", 380);
	set_skill("xiuluo-dao", 380);
	set_skill("yingzhua-gong", 380);
	set_skill("yijinjing", 380);
	set_skill("yizhi-chan", 380);
	set_skill("zui-gun", 380);
	set_skill("weituo-chu", 380);
	set_skill("ranmu-daofa", 380);
	set_skill("wuying-jian", 380);
	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "wuchang-zhang");
	map_skill("cuff", "jingang-quan");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("force", "yijinjing");
	map_skill("hand", "fengyun-shou");
	map_skill("parry", "nianhua-zhi");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "wuying-jian");
	map_skill("whip", "riyue-bian");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
(: perform_action, "cuff.fumo" :),
	(: perform_action, "cuff.jin" :),
		(: perform_action, "cuff.jingang" :),
			(: perform_action, "cuff.qixing" :),
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "sword.wuying" :),
                (: perform_action, "sword.lidichenfo" :),
                (: perform_action, "sword.ruying" :),
                 (: perform_action, "sword.foxing" :),	
                (: exert_function, "jiuyang" :),
                (: exert_function, "tong" :),
                (: exert_function, "roar" :),		 	
                (: exert_function, "chang" :),		 		
                (: exert_function, "jingang" :),		 			
        }) );
        setup(); 
        carry_object("clone/weapon/gangjian")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();

} 

void init()
{
        object ob;
        ::init();
//        add_action("do_killing", "kill");
        if( interactive(ob = this_player()) ) {
                remove_call_out("punish_betray");
                call_out("punish_betray",2 , ob);
        }
}  
void punish_betray(object ob)
{
        if( ( ob->query("once_xman")==1) && ( (ob->query("class"))!= "shaolin"))
          {      
                tell_object(ob, YEL"\n�ڴ����:�������壡����\n"NOR);                  
                message("vision", YEL"�ڴ���"+ ob->name() +"ŭ������"+ ob->name() + "�� ���㲻�£�\n"NOR, environment(ob), ob);
                tell_object(ob, HIW"�ڴ�һȭ�������������ϣ�\n"NOR);              
                message("vision", HIW"�ڴ�һȭ����"+ ob->name() +"��������ϣ�\n"NOR, environment(ob), ob);
                tell_object(ob, HIR"��ֻ�����ε�ת,ҡҡ�λεص�����ȥ----�ڲ�����ѽ!\n"NOR);
                ob->set("title",HIW"������ͽ"NOR);
                ob->die();
          }
}  

int leave() {
        if (this_player()->query("class")!="shaolin") return 0;
        message_vision(CYN"$N����һ������������Ҳ�ǲ����Բ���쳾�ģ���Ȼ�����ţ���Ҫ�������ۣ���\n"NOR, this_object());
        message_vision(CYN"$N˵�����Ǳ����˷��棬�ҿ���Ҳ�����������Ϲ��������ӡ�\n"NOR,this_object());
        
        return 1;
}  