// ri_header.c

inherit NPC;

void create()
{
        set_name("�׿�Զ", ({ "lei kaiyuan", "lei", "kaiyuan" }) );
        set("title", "�����ھ�����ͷ");
        set("gender", "����" );
        set("age", 45);
        set("str", 30);
        set("cor", 27);
        set("int", 23);
	set("max_kee",1300);

        set("max_force", 2000);
        set("force", 2000);
        set("force_factor", 20);

        set("long",@LONG
�����ھ������׿�Զһ�ִ����ģ�ƾ�Ų�����书
�ͽ����Ϲ㷺����Ե�������ھֵ�����Խ��Խ�á�
LONG);

        set("combat_exp", 100000);
        set_skill("unarmed", 100);
        set_skill("parry", 150);
        set_skill("dodge", 100);
        set_skill("blade", 120);
        set_skill("force", 100);

        setup();
	carry_object(__DIR__"obj/key1");
        carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
