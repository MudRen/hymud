//Cracked by Roath
inherit NPC;

string *first_name = ({ "����",
			"����",
			"�徲",
			"����",
			"����",
			"���",
			"����",
			"����",
			"�̴",
			"����",
			"����",
			"ׯ��",
			"�ǻ�",
			"����",
			"����",
			"����",
			"����",
			"����"
});

string *name_words = ({"�޺�"});

int create()
{
	string name;
	name = first_name[random(18)];
	name+= name_words[random(sizeof(name_words))];

	set_name(name, ({"luo han", "luohan"}));
  	set("long", "�Ϻ���������ʮ���޺���\n");
	set("title", "ʮ���޺�");
        set("gender", "����");
        set("age", 25);
        set("attitude", "peaceful");
        set("rank_info/self", "ƶɮ");
        set("class", "bonze");
        set("max_qi", 2000);
        set("max_jing", 2000);
        set("max_neili", 2000);

        create_family("�Ϻ�����ɽ", 2, "����");

        setup();
        carry_object("/d/xiyou/nanhai/obj/sengpao")->wear();
        carry_object("/d/xiyou/nanhai/obj/budd_staff")->wield();
        return 1;
}
