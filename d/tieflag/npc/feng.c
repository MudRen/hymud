 // feng.c
inherit NPC; 
void create()
{
    set_name("�����",({"feng jiuyou","feng"}));
    set("long","�������ģ����������߻���ħ��һ��Ҳ���ܶ��ˡ�\n");
    set("nickname","��������");
    set("gender","����");
    set("age",42);
    set("no_arrest",1);
    set("int",22);
    set("cor",0);
    set("per",30);
    set("con",0);
    set("cps",20);
    set("agi",0);
    set("jing",1000);
    set("max_jing",1000);
    set("eff_gin",1000);
    set("max_qi",1000);
    set("eff_qi",1000);
    set("qi",1000);  
    set("max_sen",1000);
    set("jing",0);    
    set("eff_sen",1000);
    set("combat_exp",400000);  
    set_skill("nine-moon-claw",100);
    set_skill("force",100);
    set_skill("demon-force",150);
    set_skill("unarmed",100);
    set_skill("parry",150);
    set_skill("dodge",150);
    set("neili",10000);
    set("max_neili",10000);
    set("force_factor",20);
    map_skill("force","demon-force");
    map_skill("unarmed","nine-moon-claw");
    set("attitude", "friendly");
    setup();
    carry_object("/clone/misc/cloth")->wear(); 
    add_money("coin", 30);
}
int accept_fight(object me)
{
        return notify_fail("������Ѿ�����ս���ˡ�\n");
}                 
