inherit NPC;
void create()
{
        set_name("���۸�", ({ "woman" }) );
        set("gender", "Ů��" );
        set("age", 48);
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
        set("long","�������޲�����δϴǦ������ʮ�������ͣ���߶�ߵ���ģ�
��ò���㲣�����ϡ�Կɼ�����ʱ�ķ绪��
\n");
        set("combat_exp", 2000);
        set("score", -50);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("flying-dragon", 70);
        set_skill("zuixian-steps", 10);
        set_skill("thunderwhip",10);
        set_skill("iceheart",10);
        map_skill("unarmed", "flying-dragon");
        map_skill("dodge", "zuixian-steps");
        set("chat_chance", 1);
/*        set("chat_msg", ({
                (: random_move :),
        }) );*/
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money( "coin" , 50);
}       
