//Cracked by Roath
// guanyin.c ��������
// By Dream Dec. 19, 1996

inherit NPC;
inherit F_MASTER;

int do_drop(object, object);

void create()
{
	set_name("��������", ({ "guanyin pusa", "guanyin", "pusa" }));
	set("title", "�ȿ���Ѵ�ȴ�");
	set("long", @LONG
��Բ�ĵ£���������ü��С�£�����˫�ǡ�����������
ޥ�԰����١���������٤ɽ�ϴȱ�������������������
LONG);
	set("gender", "Ů��");
	set("age", 35);
	set("attitude", "peaceful");
	set("rank_info/self", "ƶɮ");
	set("rank_info/respect", "��������");
	set("class", "bonze");
                set("str",100);
                set("spi",80);
                set("cor",80);
                set("cps",80);
                set("con",80);
                set("per",40);
                set("int",40);
                set("kar",40);// Cigar@sjsh_SKxyj add the all attribute.
	set("max_kee", 5000);
	set("max_gin", 5000);
	set("max_sen", 5000);
        set("force", 6000);
        set("max_force", 3000);
        set("force_factor", 250);
   



	//let's use cast bighammer to protect her...weiqi:)
	create_family("�Ϻ�����ɽ", 1, "����");

	setup();
        carry_object("/d/xiyou/nanhai/obj/jiasha")->wear();
        carry_object("/d/xiyou/nanhai/obj/nine-ring")->wield(); 
}

