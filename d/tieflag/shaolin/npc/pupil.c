 // TIE@FY3
inherit NPC;
void create()
{
        set_name("��������", ({ "ren" }) );
        set("gender", (random(2)? "Ů��":"����") );
        set("age", random(40)+10);
        set("long",
                "һ�����ڶԱ������Ե���\n");
        set("combat_exp", 5+random(50000));
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
                "����������ͷ���ű�ʯ�߽е�����ô��ô��ѧѽ��\n",
        }) ); 
        set("attitude", "friendly");
        set("rank_info/respect", "ʩ��");
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
}   
