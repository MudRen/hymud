 // maniac.c
inherit NPC; 
void create()
{
        object ob; 
        set_name("��ң��", ({ "xiaoyao", "xiaoyao hou", "hou" }) );
        set("gender", "����");
        set("age", 67);
        set("long",
                "�����ͷ�����������������죬���������ƺ����ˡ�\n"); 
        set("cor", 30);
        set("class","taoist");
        set("combat_exp", 3000000);
        set("score", 8000);
        set("bellicosity", 30000);
        set("reward_npc", 1);
        set("difficulty", 2);
        
        set("jing",2400);
        set("max_jing",2400);
        set("eff_jing",2400);
        
        set("force", 1200);
        set("max_neili", 1200);
          
        set("mana", 800);
        set("max_mana", 800); 
        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("force", 100);
        set_skill("spells", 200);
        set_skill("necromancy", 70);
        
        map_skill("spells", "necromancy"); 
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: cast_spell, "feeblebolt" :),
        }) ); 
        set_temp("apply/attack", 200);
        set_temp("apply/dodge", 200);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
