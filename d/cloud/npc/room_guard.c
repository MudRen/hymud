
// room_guard.c
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("����", ({ "guard" }) );
        set("title", "������");
        set("gender", "����" );
        set("age", 25);
        set("long", "�㿴��һ���⺷�Ĵ��ͷ��\n");
         set("str", 15);
         set("cor", 30);
         set("con", 30);
        set("kee", 500);
        set("max_force", 1000);
        set("force", 1000);
        set("max_kee", 500);
        set("int", 14);
        set("combat_exp", 20000);
        set("attitude", "heroism");
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);

        set("inquiry", ([
                "����" : "�⵶���Ǹ�����, 
��˵�ǵ����ż�����������ʱ���ϴ͵ġ�",
                "������" : "��Ҳ֪��'�̺�����'����¥���ڽֶ��棬�ҳ�ȥ�ġ�", 
        ]) );



        setup();
        add_money("silver", 12);
        add_money("coin", 500);
        carry_object("/clone/misc/cloth")->wear();
}

