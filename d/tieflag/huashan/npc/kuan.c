 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("��������", ({ "ku an" }) );
        set("gender", "����");
        set("age", 65);
        set("long",
"һ����ü�������ϵ���\n"
);
        set("inquiry", ([
        ]) );
      
        set("chat_chance", 1);
        set("chat_msg", ({
                "��������̾�����������������������������ʵ���ǲ����Ѱ�����\n",
        }) );
          
        set("attitude", "friendly");
        set("title",HIG"����"NOR);
        set("score", 0);
        set("reward_npc", 1);
        set("difficulty",5);
        set("class","bonze");
        set("fly_target",1);
        
        set("combat_exp", 3500000);        
        set("int", 30);
        set("cps", 20);
        set("spi", 30);
        set("fle",50);
        
        set("neili", 2000);
        set("max_neili",2000);
        set("force_factor", 40);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 500);
        set("max_mana", 500);
        
        set("resistance/kee",50);
        set("resistance/gin",50+random(40));
        set("resistance/sen",50);        
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "staff.longxianyuye" :),
                (: perform_action, "unarmed.qianshouqianbian" :),
        }) ); 
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);              
        //set_skill("lotusforce", 150);
        //set_skill("notracesnow",150);
        //set_skill("dabei-strike",165);
        set_skill("cloudstaff",350);
        set_skill("staff",150); 
        map_skill("staff","cloudstaff");
        map_skill("unarmed","dabei-strike");
        map_skill("force", "lotusforce");
        map_skill("dodge","notracesnow");
        map_skill("move","notracesnow");
        map_skill("parry","cloudstaff");
        map_skill("sword","cloudstaff");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(2));
        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/misc/cloth")->wear();
} 
       
