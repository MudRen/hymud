 inherit NPC;
void create()
{
        set_name("�ض���", ({ "dahan"}) );
        set("gender", "����" );
        set("age", 32+ random(10));
        set("long", "����һλ�Ӱ�ɽ��ˮ���Ĺض��󺺡�\n");
        set("combat_exp", 5000);
        set("attitude", "aggrensive");
        set_skill("unarmed", 30 + random(100));
        set("chat_chance", 10);
        set("chat_msg", ({
                "�ض��󺺺�ˬ�������Ц��\n",
                (: random_move :),
        }) );
        setup();
    add_money("silver", 30);
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/xuechang");
}  
