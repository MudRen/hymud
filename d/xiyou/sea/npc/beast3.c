inherit NPC;
string *first_name = ({ "˫ͷ", "��", "��Ƥ", "����"});
string *name_words = ({ "��"});

void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];

        set_name(name, ({ "jiao" }) );
        set("race", "Ұ��");
        set("age", 20);
	set("attitude", "aggressive");
        set("long", "һֻ��ģ�����ĺ��ԡ�\n");
        set("str", 20);
        set("cor", 30);
        set("max_kee", 1200);
        set("max_sen", 1200);
        set("limbs", ({ "ͷ��", "����", "���", "β��", "��Ƥ"}) );
        set("verbs", ({ "bite", "claw"}) );

        set("combat_exp", 370000+random(100000));
  set("daoxing", 400000);

	set_skill("dodge", 170);
	set_skill("unarmed", 170);
	set_skill("parry", 170);
        set_temp("apply/damage", 25);
        set_temp("apply/armor", 80);
	set_weight(500000);
        setup();
}

