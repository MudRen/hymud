// smith.c

#include <ansi.h>


inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("������", ({ "zhou", "smith" }) );
        set("gender", "����" );
        set("age", 33);
        set("long", "������������ǯ��סһ����ȵ�����Ž�¯�С�\n");
        set("combat_exp", 400);
        set("inquiry", ([
		"��������" : "�ø��ҿ�����˵�ɡ�һ������׾����ˡ�\n",
        ]) );
        setup();
        carry_object(__DIR__"obj/hammer")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object who, object ob)
{
	if((string)ob->name() != YEL "�����ƽ��" NOR){
		write("���Ҷ����Ҿ������ˣ�лл��\n");
		command("smile");
		return 1;
	}
	write("�����������������ⲻ�������ƽ���������һ������ѽ��\n");
	write("��˵ʮ����ǰ���䷬���λ"+RANK_D->query_respect(ob)+"��ô��õ��ģ�\n");
	write("û�뵽�ƾɳ������ˣ�Ҫ����������ҷ��Ĳ�Ҫ�����һ�¡���\n");
	write("�����������ô���ʼ����������æ��������\n");
	who->start_busy(4);
	call_out("xiu_li",3,who,ob);
	return 1;
}

void xiu_li(object who,object ob)
{
	ob->set_name(HIY "�����ƽ��" NOR, ({ "golden armor", "armor" }) );
	ob->set("armor_prop/armor", 300);
	ob->set("long", "һ������������������ף�����ȴ���ᣬ��֪����ʲô���ɵġ�\n");
	write("����������ͷ�ϵĺ�ˮ˵�����������޺��ˣ������������˼����ⶫ�����Ǹ�������\n");
	command("give golden armor to "+(string)who->query("id"));
	return;
}
