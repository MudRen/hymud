#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int HAVE_WEAPON=1;

int give_weapon();


void create()
{
	int i=random(2);
        set_name(HIY"梵音神尼"NOR,({"fan yin", "shenni", "nigu","master"}));
       set("long",
"神尼名动武林,是当世两大神尼之一,据说她的武功已经到了神而名之的地步.\n");
       set("title", YEL"白云庵主持"NOR);
       set("gender", "女性");
       set("age", 76);
       set("attitude", "friendly");
       set("class","nigu");
       set("rank_info/respect", "神尼");
       set("per", 30);
        set("int", 30);
        set("inquiry", ([
                        "兵器" : (: give_weapon :),
                    "宝刃":(:give_weapon:),
                                    "宝刀":(:give_weapon:),

                ]) );   

        set("combat_exp", 9000000);
        set("str", 55);
        set("max_qi",30000);
        set("max_jing",30000);
        set("max_sen",30000);
        set("neili", 50000);
        set("max_neili", 50000);
        set("atman", 50000);
        set("max_atman", 50000);
        set("mana", 50000);
        set("max_mana", 50000);
        set("force_factor", 150);



set_skill("demon-strike",380);
set_skill("yubi-jian",380);
set_skill("zhuifeng-quan",380);
set_skill("bitao-shengong",380);
set_skill("baihua-zhang",380);
set_skill("feixian-jian",380);
set_skill("qiongya-bufa",380);

        set_skill("literate",380);
        set_skill("unarmed",380);
        set_skill("dodge",290);
        set_skill("parry",280);
	set_skill("force",380);
	set_skill("blade",280);
	set_skill("changquan",380);
	set_skill("strike",380);
	set_skill("whip",380);
	set_skill("cuff",380);
	set_skill("sword",380);
set_skill("buddhism",500);
set_skill("zhuyue-whip",380);
set_skill("snowsword",380);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 650);

        //set_skill("doomsword",380);
        //set_skill("chilian-shenzhang",380);
        //set_skill("softsword",280);
        //set_skill("nine-moon-sword",380);
        map_skill("strike","baihua-zhang");
        map_skill("cuff","zhuifeng-quan");
        map_skill("sword","yubi-jian");
        map_skill("force","bitao-shengong");
        map_skill("dodge","qiongya-bufa");
        map_skill("parry","yubi-jian");

	prepare_skill("strike", "baihua-zhang");
	prepare_skill("cuff", "zhuifeng-quan");
if (i==0)
{
map_skill("sword","snowsword");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "fofa" :),
                (: exert_function, "ziqi" :),
                (: exert_function, "weituo" :),
                (: exert_function, "shield" :),
                (: exert_function, "powerup" :),
                (: exert_function, "roar" :),
                (: perform_action, "sword.hanyue" :),
                (: perform_action, "sword.hanyue" :),
                (: perform_action, "sword.tian" :),	
                (: perform_action, "sword.tian" :),	
                (: perform_action, "parry.shi" :),
                (: perform_action, "cuff.hantian" :),
(: perform_action, "cuff.luori" :),
(: perform_action, "cuff.nx" :),
(: perform_action, "cuff.qiankun" :),		             
(: perform_action, "cuff.qin" :),		             
(: perform_action, "cuff.qzwd" :),		             	             
        }) );  
}  

else
{
map_skill("whip","zhuyue-whip");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "fofa" :),
                (: exert_function, "ziqi" :),
                (: exert_function, "weituo" :),
                (: exert_function, "shield" :),
                (: exert_function, "powerup" :),
                (: exert_function, "roar" :),
                (: perform_action, "whip.huabian" :),
                (: perform_action, "whip.jueqing" :),
                (: perform_action, "whip.jueqing" :),	
                (: perform_action, "whip.yinhua" :),	
                (: perform_action, "cuff.hantian" :),
(: perform_action, "cuff.luori" :),
(: perform_action, "cuff.nx" :),
(: perform_action, "cuff.qiankun" :),		             
(: perform_action, "cuff.qin" :),		             
(: perform_action, "cuff.qzwd" :),		             	             
        }) );  
}  

create_family("白云庵", 3, "传人");
setup();

        carry_object("/d/hainan/obj/bai_cloth")->wear();
if (i==0)        carry_object("/d/hainan/obj/yuruyi")->wield();
else        carry_object("/clone/weapon/changbian")->wield();
        add_money("gold.c",10);
}



int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "nigu");
}
int give_weapon()
{  
  object me,ob;

  me=this_player();
if ((me->query("family/master_id")=="zhongling")&&(me->query("family/family_name")=="白云庵"))
 {
  if( me->over_encumbranced() ) return notify_fail("你已经负荷过重了！\n");

  if(HAVE_WEAPON==0)
    command("say 你来晚了，这东西已经给人取走了。");  
  else  
  {
  clone_object("/d/hainan/obj/hanyue.c")->move(me);

    command("say 钟灵这小丫头真是胡闹,这件东西你就拿去吧。");  
    message_vision("梵音神尼给$n一把寒月斩。\n",this_object(),me);   
    
    HAVE_WEAPON=0;   
  }

  return 1;
 }
else
 command("say 老尼哪来的什么神兵利刃呀,你别听那些小丫头乱说!\n");
return 1;
}

void attempt_apprentice(object ob)
{

	command("recruit " + ob->query("id") );
      
}
