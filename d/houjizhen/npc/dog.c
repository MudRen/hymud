// dog.c
// by dicky

inherit NPC;

void create()
{
        set_name("���Ź�", ({ "kanmen dog","dog" }) );
        set("race", "Ұ��");
        set("age", 3);
	set("long", "����һֻ���Ź�������ֻʣ��Ƥ����ͷ��\n");
        set("attitude", "heroism");

        set("max_qi", 500);
        set("max_jing", 500);
        set("max_sen", 500);
        
        set("combat_exp", 50000);
        set("limbs", ({ "ͷ��", "����", "β��","ǰ��", "���"}) );
        set("verbs", ({ "bite","claw" }) );
        set("str",20);
        set("cor",30);
        set("chat_chance", 1);
        set("chat_msg", ({
                "���ҹ���һ�ֱ��˵��۹⿴����,Ϊ������Ĳ����е��޿��κ�!\n",
         }));

	set_temp("apply/attack", 35);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 20);
        setup();
}
