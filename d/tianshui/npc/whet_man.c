// whet_man.c

inherit NPC;
 
void create()
{
        set_name("ĥ����", ({"whet man", "man"}));
        set("long", @TEXT
�԰���ĥ�˵�Ϊ����
TEXT
	);
	set("gender","����");
	set("age",37);
	set("con",30);
	set("str",20);
	set("combat_exp",1300);
        set("attitude","peaceful");
	set("chat_chance",5);
	set("chat_msg", ({
	"ĥ���˺��ţ���ĥ�˵�ඣ�ĥ����ĥ��ඣ���\n",
	(: random_move :),
}) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/m_stone");
}