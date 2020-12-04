
// post_officer.c

inherit NPC;

string send_mail();
string receive_mail();

void create()
{
	set_name("�Ҷ�", ({ "waiter" }) );
	set("title", "");
	set("gender", "����" );
	set("age", 18);
	set("long",
		"�ſ���ѩͤ����䳤�Ѿ���ʮ�����ˣ���Ȼ�ڼ��м�����Ǩ��\n"
		"���ᣬ����������Ϊ�᲻���뿪���Сɽ��������ˣ�ѩͤ���\n"
		"����Զſ�ķ����൱����������������վ�������졣\n");
    set("max_kee",300);
    set("kee",300);
    set("max_force",200);
    set("force",200);
    set("con",30);
    set("cor",30);
    set("str",15);
	set("combat_exp", 8000);
	set("attitude", "friendly");
	set("inquiry", ([
		"��վ" : "�ǰ�... �������ѩͤ�䣬��Ҫ������",
		"����" : (: send_mail :),
		"����" : (: receive_mail :),
	]) );
	set_skill("literate", 70);
	set_skill("dodge", 30);
	set_skill("unarmed", 40);
	setup();
	add_money("coin", 70);
}

string send_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "������仹�ڰɣ�������Ϳ��Լ����ˡ�\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "���Ǳ�Ǹ��������һ�µ���վ�����Ұɡ�\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "Ŷ... Ҫ������������������䣬���ŵķ�����������˵����\n";
}

string receive_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "������仹�ڰɣ������е��Ŷ������档\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "���Ǳ�Ǹ��������һ�µ���վ�����Ұɡ�\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "�ã���������....���ˣ�����������⣬�������ɣ���������ˡ�\n";
}
