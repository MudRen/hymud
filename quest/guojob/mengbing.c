#include <ansi.h>
inherit NPC;

int do_copy(object me,int maxpot,int type);

void create()
{
      string weapon;
        set_name("蒙古大汉", ({ "menggu dahan","dahan"}));
        set("gender", "男性");
        set("age", random(20) + 25);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
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
        set_skill("yijinjing",50);
        set_skill("wind-blade", 80+random(180));
        map_skill("blade", "wind-blade");
        map_skill("parry", "wind-blade");
        set_temp("apply/damage", 150);

	map_skill("dodge", "qingmang-jian");
        map_skill("sword", "qingmang-jian");
        map_skill("cuff", "taizu-quan");
        map_skill("force", "yijinjing");

        prepare_skill("cuff", "taizu-quan");         
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );
        
           set_skill("taiji-shengong", 80);
           set_skill("taiji-quan", 80);
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-quan");
                
        set("max_qi", 450); 
        set("eff_jingli", 400); 
        set("neili", 700); 
        set("max_neili", 700);
        set("jiali", 30);
        weapon = random(2)?"/clone/weapon/gangdao":"/clone/weapon/gangdao";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int do_copy(object me,int maxpot,int type)
{
        int i,j;
        object ob;
        ob = this_object();
        i=maxpot;
        if(type==1)
		i = i - random(20);
		else  
	    i = i +10+ random(10);
        if( i < 100) i = 100;
        
        ob->set("combat_exp", (me->query("combat_exp")+random(me->query("combat_exp")))*3/4);
        ob->set_skill("force", i);
        ob->set_skill("blade", i);
        ob->set_skill("cuff",  i);
		ob->set_skill("blade", i);
        ob->set_skill("dodge", i);
        ob->set_skill("parry", i);
        ob->set_skill("wind-blade", i);       
        ob->set_skill("taizu-quan", i); 
        set_skill("yijinjing",i);
        ob->set("max_qi",     me->query("max_qi")/2); 
        ob->set("max_jing", me->query("max_jing")/2); 
        ob->set("max_neili",  me->query("max_neili")/2); 
        ob->set("qi",     me->query("max_qi")/2); 
        ob->set("jing", me->query("max_jing")/2); 
        ob->set("neili",  me->query("max_neili")/2); 

        ob->set("eff_qi",     me->query("max_qi")/2); 
        ob->set("eff_jing", me->query("max_jing")/2); 
        if(type==3)
		{ob->set("max_qi",     i*40);
		 ob->set("max_neili",  i*35); 
		}
		if(type==2)
        ob->set("max_qi",     i*40); 
		ob->reincarnate(); 
        ob->set("qi",ob->query("max_qi"));
        ob->set("neili",ob->query("max_neili"));
	    return 1;
}

void init()
{
        remove_call_out("leave");
        call_out("leave",300);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "钻进路边的杂草，不见了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}
