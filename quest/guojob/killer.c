#include <ansi.h>
inherit NPC;

int do_copy(object me,int flag);
int do_back(object me);

void create()
{
      string weapon;
        set_name("������", ({ "heiyi ren","ren"}));
        set("gender", "����");
        set("age", random(20) + 25);
        set("str", 33);
        set("con", 36);
        set("int", 30);
        set("dex", 33);
        set("long", "һ�����ź�ɫҹ���µ��ˡ�\n");
        set("combat_exp", 80000 + random(40000)); 
        set("attitude", "friendly");
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("cuff", 50);
        set_skill("blade", 50);
        set_skill("taizu-quan", 50);
        set_skill("qingmang-jian", 50); 
        set_skill("wind-blade", 80+random(180));
     set_skill("necromancy", 80);
        set_skill("xiaowuxiang", 80);
        set_skill("force", 80);
        set_skill("longxiang", 80);
        set_skill("dodge", 50);
        set_skill("shenkong-xing", 80);
        set_skill("unarmed", 80);
        set_skill("yujiamu-quan", 80);
        set_skill("parry", 80);
        set_skill("cuff", 80);
        set_skill("sword", 80);
        set_skill("mingwang-jian", 80);
        set_skill("lamaism", 50);
        set_skill("literate", 80);
        set_skill("hammer", 80);
        set_skill("riyue-lun", 80);
	set_skill("dashou-yin", 80);
        set_skill("staff", 80);
        set_skill("xiangmo-chu", 80);
        set_skill("magic", 80);
        set_skill("kwan-yin-spells", 80);

        map_skill("blade", "wind-blade");
        map_skill("parry", "wind-blade");

        map_skill("magic", "kwan-yin-spells");
        map_skill("cuff", "yujiamu-quan");
        map_skill("hand", "dashou-yin");
        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("parry", "riyue-lun");
        map_skill("sword", "mingwang-jian");
        map_skill("hammer", "riyue-lun");

prepare_skill("cuff", "yujiamu-quan");
prepare_skill("hand", "dashou-yin");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.chen" :),
                (: perform_action, "cuff.jiang" :),
                (: perform_action, "hand.dashouyin" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: perform_action, "blade.fanzhuan" :),
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );
                set("max_qi", 450); 
        set("eff_jingli", 400); 
        set("neili", 700); 
        set("max_neili", 700);
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 250);
        set_temp("apply/damage", 250);        
        //set("jiali", 30);
        weapon = random(2)?"/clone/weapon/gangdao":"/clone/weapon/gangdao";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/misc/cloth");
}

int do_copy(object me,int flag)
{
        int i,j;
        object ob;
        ob = this_object();

        i = me->query_skill("dodge",1);
        j = me->query_skill("force",1);
        i = i>j?i:j;
		if(flag==0)
		i = i - random(20);
		else 
	    i = i + random(20);
        if( i < 60) i = 60;
        i=i*0.7;
        ob->set("combat_exp", me->query("combat_exp",1)*4/5);
        ob->set_skill("force", i);
        ob->set_skill("sword", i);
        ob->set_skill("blade", i);
        ob->set_skill("dodge", i);
        ob->set_skill("parry", i);
        ob->set_skill("wind-blade", i);       
        ob->set_skill("taizu-quan", i); 
        ob->set_skill("yujiamu-quan", i);
        ob->set_skill("parry", i);
        ob->set_skill("cuff", i);
        ob->set_skill("sword",i);
        ob->set_skill("mingwang-jian", i);
        ob->set_skill("lamaism", i);
        ob->set_skill("literate", i);
	ob->set_skill("dashou-yin", i);
        ob->set_skill("magic", i);
        ob->set_skill("longxiang", i);
        ob->set_skill("shenkong-xing", i);
        ob->set_skill("kwan-yin-spells", i);
        ob->set("max_qi",     me->query("max_qi")); 
        ob->set("max_jing", me->query("max_jing")*2); 
        ob->set("max_neili",  me->query("max_neili")); 
        ob->set("qi",     me->query("max_qi")); 
        ob->set("jing", me->query("max_jing")*2); 
        ob->set("neili",  me->query("max_neili")); 

        ob->set("eff_qi",     me->query("max_qi")); 
        ob->set("eff_jing", me->query("max_jing")*2); 
ob->set_name("������", ({me->query("id")+" heiyi","heiyi ren","ren"}));
        ob->reincarnate(); 
		call_out("do_back", 350,  ob);  
        return 1;
}
int do_back(object me)
{                       
  tell_room(environment(me), me->query("name")+"�Ҵ�ææ���뿪�ˡ�\n", ({me}));	
  destruct(me); 
  return 1;
}

/*void unconcious()
{            
	::die();       
}*/

void die()
{
	object corpse;
	mixed killer;
	if( !(killer = query_temp("last_damage_from")) ) return;
	if( !living(this_object()) ) revive(1);
	else delete_temp("faint_by");
	COMBAT_D->announce(this_object(), "dead");
	if( !(killer = query_temp("last_damage_from")) )
	killer = "Ī�������";
	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
	corpse->move(environment());
	set_temp("last_damage_from", "Ī�������");
    corpse->set_temp("must_killby",this_object()->query_temp("must_killby"));
	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());
    destruct(this_object());
}
