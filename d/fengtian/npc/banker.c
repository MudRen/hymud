
// banker.c

inherit NPC;

void create()
{
        set_name("�Ƶò�", ({ "huang decai","huang"}) );
        set("title", "Ǯׯ�ϰ�");
        set("gender", "����" );
        set("age", 39);

        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);

        set("long","����������¡Ǯׯʢ���ֵ�õ��֡�\n");

        set("combat_exp", 100);
        set("attitude", "friendly");

        set("max_atman", 500);
        set("atman", 500);
        set("max_force", 1000);
        set("force", 1000);
        set("force_factor", 20);
        set("max_mana", 500);
        set("mana", 500);

        setup();
        
        carry_object("/clone/misc/cloth")->wear();
}
