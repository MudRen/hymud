 // post_officer.c
inherit NPC; 
string send_mail();
string receive_mail(); 
void create()
{
        set_name("����", ({ "officer", "post officer" }) );
        set("title", "�������䳤");
        set("gender", "����" );
        set("age", 43);
        set("long",
                "���絣�η�������䳤�Ѿ��м����ˣ��˺ܺã�\n"
                "���������ķ����൱����������������վ�������졣\n");
        set("combat_exp", 800);
        set("attitude", "friendly");
        set("inquiry", ([
                "��վ" : "�ǰ�... ������Ƿ������Ҫ���Ż�������",
       ]));
        set_skill("literate", 70);
        set_skill("unarmed", 400);
        setup();
        add_money("coin", 70);
        carry_object("/clone/misc/cloth")->wear();
} 
