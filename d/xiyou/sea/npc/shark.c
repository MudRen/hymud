inherit NPC;
string *first_name = ({ "��Ƥ", "�̱�", "˫ͷ", "����"});
string *name_words = ({ "��"});

void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];

        set_name(name, ({ "shark" }) );
        set("race", "Ұ��");
        set("age", 20);
        set("long", "һֻģ���׶�Ĵ����㡣\n");
        set("str", 20);
        set("cor", 30);
        set("max_kee", 800);
        set("max_sen", 800);
        set("limbs", ({ "ͷ��", "����", "ǰ��", "β��", "��Ƥ"}) );
        set("verbs", ({ "bite"}) );

        set("combat_exp", 100000+random(10000));
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 20);
	set_weight(500000);
        setup();
}



