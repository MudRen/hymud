// thief.c
inherit NPC;
 
void create()
{
        set_name("��������", ({ "oldman" }) );
        set("rank", "����");
        set("gender", "����" );
        set("str", 65);
        set("dex", 65);
        set("age", 65);
        set("int", 25);
        set("con", 28);
        set("long", @LONG
һ�������µ����ˣ���Ȼ��ͺܴ��ˣ�ȴ��ɫ�����۾���������
LONG
);
        set("combat_exp", 993000);
        set("attitude", "heroism");
        set("env/wimpy", 70);
        set_skill("sword", 940);
        set_skill("parry", 950);
        set_skill("force", 950);
        set_skill("dodge", 900);
        set_skill("dagger", 925);
        set_skill("stealing",935); 
        setup();
 
        add_money("gold",1);
        //carry_object("/u/cloud/obj/cloth/black_cloth")->wear();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
        
        set("score",-30);
}
