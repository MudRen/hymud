inherit NPC;
void create()
{
        set_name("�����", ({ "dagu" }) );
        set("gender", "Ů��" );
        set("age", 38);
        set("str", 58);
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
        set("long","����һ����ĸߴ���üĿ�������������һ���Ů�ӡ�\n");
        set("combat_exp", 2000);
        set("score", -50);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("flying-dragon", 50);
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
                if( me->query("class") )
                if( me->query("class") != "yinshi")
                kill_ob(me); 
}       
