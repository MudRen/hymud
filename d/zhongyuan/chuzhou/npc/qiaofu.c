// �����Է� /d/city/chuzhou/npc/qiaofu.c
// by lala, 1997-12-14

inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name("�Է�", ({ "qiao fu", "qiao", "fu", "woodman", "axeman" }) );
    set("gender", "����" );
    set("combat_exp", 2500);

        set("qi",400);
        set("max_qi",400);
        set("eff_kee",400);
        set("sen",400);
        set("max_sen",400);
        set("eff_sen",400);
    set("chat_chance", 10);
    set("chat_msg",({
        "�Է�̾��������˭���ҵ��ղ񰡣���\n",}) );
    set("attitude", "friendly");
    set("env/wimpy", 70);     
    set("no_leave_chuzhou", 1);

	set("vendor_goods", ({
		__DIR__"obj/chai",
	}));    
    set( "talk_msg", ({
        "��Ҫ��ѧ�䡭�����һ������û��ʲô��������ݡ���",
        "���������ӹ�����Ȼ���������ܻ��ܹ�����",
        "����˵�������ϵ���ؤ��ʲôؤ��ģ����Դ�Ҷ������ǡ���",
        "������������ҵĲ�̰ɡ���",
    }));
    setup();
    carry_object("/clone/misc/cloth")->wear();
    carry_object("clone/weapon/gangdao")->wield();
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}    
