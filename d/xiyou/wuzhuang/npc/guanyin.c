//Cracked by Roath
// guanyin.c ��������
// By Dream Dec. 19, 1996

inherit NPC;
inherit F_MASTER;
#include "/d/migong/romnpc2.c"
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
	set("max_qi", 5000);
	set("max_jing", 5000);
	set("max_jing", 5000);
        set("neili", 6000);
        set("max_neili", 3000);
       
	set("inquiry",([
      "��ƿ": "ǰЩ�죬���ǽ��ҵľ�ƿ�ã�������Ҳû�л�����ȥ�����ɡ�" ]));



	//let's use cast bighammer to protect her...weiqi:)
	create_family("�Ϻ�����ɽ", 1, "����");

	setup();
	initlvl((800+random(880)),0);
        carry_object("/d/qujing/nanhai/obj/jiasha")->wear();
        carry_object("/d/qujing/nanhai/obj/nine-ring")->wield(); 
}

void die()
{
	int i;
	string file;
	object *inv;

        if( environment() ) {
        message("sound", "\n\n��������ҡͷ̾�����������ϣ�����ħ�ϣ����伲�࣬���˶�֮��\n\n", environment());
        command("sigh");
        message("sound", "\n�������������ƣ��ǲ�����������ȥ�ˡ�����\n\n", environment());
}

	destruct(this_object());
}



void unconcious()
{
	die();
}

