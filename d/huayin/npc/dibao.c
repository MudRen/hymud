// smith.c

inherit NPC;

void create()
{
	set_name("Ī��ǫ", ({ "mo ti qian"}) );
	set("title","ͭɽ��ر�");
        set("gender", "����" );
        set("age", 58);
	set("str",60);
        set("long", "������ͭɽ��ĵر�����˵��
�Ǵ�ͬ��֪�������ݡ�\n");

        set("combat_exp", 100);
        set("attitude", "friendly");
        setup();

	carry_object("/clone/misc/cloth")->wear();
}