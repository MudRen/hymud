
// seller.c

inherit NPC;

void create()
{
        set_name("���Ϻ�", ({ "seller" }) );
        set("title", "�̷���");
        set("gender", "����" );
        set("age", 28);
        set("str", 26);
        set("int", 14);
        set("long",
                
"���Ϻ��Ǹ���Ǯ�ۿ��Ĵ���̣�����������˳���ѻƬ!\n");
        set("combat_exp", 3000);
        set("attitude", "heroism");

        set("force", 120);
        set("max_force", 120);
        set("force_factor", 1);

        set_skill("unarmed", 30);
        set_skill("dodge", 30);

        setup();
}

