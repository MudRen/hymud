 // jiayi.c
inherit NPC; 
void create()
{
    set_name("��������",({"old woman","woman"}));
    set("long","�����궨�������ɫ����������...\n");
    set("gender","Ů��");
    set("age",42);
    set("skill_public",1);  
    set("no_arrest",1);
    set("int",22);
    set("cor",0);
    set("per",0);
    set("con",0);
    set("cps",20);
    set("agi",0);
    set("jing",1000);
    set("max_jing",1000);
    set("eff_gin",1000);
    set("max_sen",1000);
    set("jing",1000);     
    set("eff_sen",1000);
    set("combat_exp",0);  
    set_skill("force",100);
    set_skill("jiayiforce",75);
    set("neili",100000);
    set("max_neili",100000);
    set("force_factor",2000);
    map_skill("force","jiayiforce");
    set("attitude", "friendly");
        set("chat_chance",2);
        set("chat_msg",({
                "����˵������������ڣ������񹦡�\n",
    }) );
    setup();
    carry_object("/clone/misc/cloth")->wear();   
    carry_object(__DIR__"obj/jiabook");  
    add_money("coin",130);
}
int recognize_apprentice(object ob)
{
        if(ob->query("marks/����") )
              return 1;
}                             
