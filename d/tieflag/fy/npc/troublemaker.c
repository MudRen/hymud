inherit NPC;
string kill_passenger(object who);
void create()
{
        set_name("��������", ({ "naked man" }) );
        set("gender", "����" );
        set("age", 28);
        set("str", 28);
        set("cor", 27);
        set("cps", 25);
        set("int", 23);
        set("attitude", "aggrensive"); 
        set("long","����һλ����ϴ�����������\n"); 
        set("combat_exp", 200000);
        set("score", 50);
        set_skill("unarmed", 100);
        set_skill("dodge", 100); 
        set_skill("meihua-shou", 10);
        set_skill("fall-steps", 10); 
        map_skill("unarmed", "meihua-shou");
        map_skill("dodge", "fall-steps");  
        setup();
        add_money( "coin" , 10);
} 
void init()
{
        add_action("do_look", "look");
} 
int do_look(string arg)
{
        if ( arg == "naked man")
        COMBAT_D->auto_fight(this_object(), this_player(), "berserk");  
        return 0; 
}      
