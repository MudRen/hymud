
//dashou_head.c
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("����", ({ "head" }) );
        set("title", "�ܼ�");
        set("gender", "����" );
        set("age", 35);
        set("long", "�㿴��һ���⺷�Ĵ��ͷ��\n");
        set("str", 29);
        set("int", 14);
        set("combat_exp", 2500);
        set("attitude", "heroism");
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);

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

