 inherit NPC;
#include <ansi.h> 
void create()
{
        object armor;
        set_name("��������", ({ "chi yang" }) );
        set("gender", "����");
        set("age", 65);
        set("long",
"һ����ɫ��죬��ĸߴ�ĵ��ˡ�\n"
);
        set("inquiry", ([
        ]) );
      
        set("chat_chance", 1);
        set("chat_msg", ({
        "��������Ц�������Ǵ������������������������һ�������������\n",
        }) );
          
        set("attitude", "friendly");
        set("title",HIW"�䵱"NOR);
        set("score", 0);
        set("reward_npc", 1);
        set("difficulty",15);
        set("class","wudang");
        set("fly_target",1);
        set("combat_exp", 4400000);        
        set("int", 30);
        set("cps", 40);
        set("spi", 30);
        set("fle",50);
        
        set("neili", 2000);
        set("max_neili",2000);
        set("force_factor", 40);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 500);
        set("max_mana", 500);
        
        set("resistance/gin",40);
   set("resistance/kee",40);
        set("resistance/sen",40);
        
     set("neili", 36400);
        set("max_neili", 36400);
        set("jiali", 50);
        set("max_qi",18200);
        set("max_jing",15200);

        set("combat_exp", 5400000);
        set("shen", 20000);
        set_temp("xunshan", 200);
        set("apprentice_available", 3);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jm" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jie" :),
                (: perform_action, "sword.xian" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),                
                (: exert_function, "powerup" :),
        }) );

        set_skill("unarmed", 180);
        set_skill("sword", 290);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 200);
        set_skill("huashan-sword", 290);
        set_skill("zixia-shengong", 320);
        set_skill("hunyuan-zhang", 290);
        set_skill("poyu-quan", 290);
        set_skill("feiyan-huixiang", 290);
        set_skill("pixie-sword",280);
        set_skill("zhengqijue",200);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(2));
        carry_object("/clone/weapon/gangjian")->wield();
         armor=new("/clone/misc/cloth");
        armor->set_name("˿֯�ĵ���",({"cloth"}) );
        armor->move(this_object());
        armor->wear();

} 
        
