 inherit NPC;
void create()
{
        set_name("԰��", ({ "gardener" }) );
        set("nickname", "����һ��");
        set("gender", "����");
        set("age", 32);
        set("long",
"����һ���Ƿ�԰��ʮ��������԰����һ�Ѵ��ʹ�ĳ����绯��");
        set("combat_exp", 30000);
        
        set("score", 200);
        set("str", 20);
        set("int", 30);
        set("cor", 20);
        set("cps", 30);
        set("spi", 30);
        set("fly_target",1);
        set("max_jing", 500);
        set("eff_gin", 500);
        set("jing", 500);
        set("max_qi", 2000);
        set("eff_qi", 2000);
        set("qi", 2000);
        set("max_sen", 500);
        set("eff_jing", 500);
        set("jing", 500); 
        set("neili", 150);
        set("max_neili", 150);
        set("force_factor", 5); 
        set("atman", 1500);
        set("max_atman", 1500); 
        set("mana", 3000);
        set("max_mana", 3000);
        set("mana_factor", 50); 

        set_skill("literate", 10);
        set_skill("magic", 50);
        set_skill("force", 50);
        set_skill("spells", 50);

        set_skill("unarmed", 30);
        set_skill("sword", 330);
        set_skill("parry", 30);
        set_skill("dodge", 30);

        set_skill("taoism", 30);

        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30); 
        setup(); 
        carry_object(__DIR__"obj/lscissors")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("coin", 3); 
}        
