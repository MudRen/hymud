inherit NPC;
string kill_passenger(object who);
void create()
{
        set_name("�ձ�����", ({ "laoren" }) );
        set("gender", "����" );
        set("age", 68);
        set("str", 28);
        set("cor", 27);
        set("cps", 25);
        set("int", 23);
        set("max_atman", 300);
        set("atman", 300);
        set("max_mana", 300);
        set("mana", 300); 
        set("max_neili", 100);
        set("neili", 50);
        set("force_factor", 5);
        set("attitude", "aggrensive"); 
        set("long","����һλ�þ���˪���ձ����ˡ�\n");
        set("bellicosity",1000000);
        set("combat_exp", 2000);
        set("score", -50);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("flying-dragon", 10);
        set_skill("zuixian-steps", 10);
        set_skill("thunderwhip",10);
        set_skill("iceheart",10);
        map_skill("unarmed", "flying-dragon");
        map_skill("dodge", "zuixian-steps");  
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money( "coin" , 50);
} 
void init()
{
        object me;
        me = this_player();
        if( interactive(me))
                if( me->query("class") != "yinshi")
                kill_ob(me); 
}  
